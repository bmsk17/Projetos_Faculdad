from django.shortcuts import render
from django.http import HttpResponseRedirect
from django.contrib.auth.decorators import login_required

from market.models import Product, Sale
from market.forms import SaleForm


def index(request):
    products = Product.objects.all()
    return render(request, "index.html", {"products": products})


@login_required(login_url="/accounts/login/")
def product_view(request, prod_id):
    product = Product.objects.get(pk=prod_id)
    if request.method == "POST":
        product_id = request.POST.get("product_id")
        quantity = request.POST.get("quantity")
        if product_id and quantity:
            sales_data = {"product_id": product_id, "quantity": quantity}
            if "cart" in request.session:
                request.session["cart"] = request.session["cart"] + [sales_data]
            else:
                request.session["cart"] = [sales_data]
            return HttpResponseRedirect("/")

    return render(request, "product.html", {"product": product})


@login_required(login_url="/accounts/login/")
def cart_view(request):
    items = []
    total_price = 0
    if "cart" in request.session:
        for item in request.session["cart"]:
            item["prod"] = Product.objects.get(pk=item["product_id"])
            items.append(item)
            total_price += item["prod"].price * int(item["quantity"])
    total_price = round(total_price, 2)

    if request.method == "POST":
        # create a form instance and populate it with data from the request:
        form = SaleForm(request.POST)
        # check whether it's valid:
        if form.is_valid():
            sales_data = form.cleaned_data
            if items:
                for item in items:
                    Sale.objects.create(
                        product=item["prod"],
                        quantity=item["quantity"],
                        user=request.user,
                        cpf=sales_data["cpf"],
                        address=sales_data["address"],
                        payment_method=sales_data["payment_method"],
                    )
                    item["prod"].stock -= int(item["quantity"])
                    item["prod"].save()
            request.session["cart"] = []
            return render(request, "pagamento.html")

    else:
        try:
            last_user_sale = Sale.objects.filter(user=request.user).order_by("-pk")[0]
            form = SaleForm(
                initial={"address": last_user_sale.address, "cpf": last_user_sale.cpf}
            )
        except IndexError:
            form = SaleForm()

    return render(
        request, "cart.html", {"items": items, "form": form, "total_price": total_price}
    )


@login_required(login_url="/accounts/login/")
def cancel_sale(request):
    if request.method == "POST":
        request.session["cart"] = []
    return HttpResponseRedirect("/")


@login_required(login_url="/accounts/login/")
def remove_sale_item(request):
    if request.method == "POST":
        if request.session["cart"]:
            product_id = request.POST.get("product_id")
            new_cart = []
            for product in request.session["cart"]:
                if product["product_id"] != product_id:
                    new_cart.append(product)
            request.session["cart"] = new_cart
    return HttpResponseRedirect("/cart/")
