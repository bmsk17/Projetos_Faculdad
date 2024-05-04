from django.urls import path

from . import views

urlpatterns = [
    path("", views.index, name="index"),
    path("cart/", views.cart_view),
    path("cancelar_compra/", views.cancel_sale),
    path("remove_sale_item/", views.remove_sale_item),
    path("produto/<int:prod_id>/", views.product_view),
]