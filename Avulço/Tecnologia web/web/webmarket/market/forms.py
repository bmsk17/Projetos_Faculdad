from django.forms import ModelForm

from market.models import Sale


class SaleForm(ModelForm):
    class Meta:
        model = Sale
        fields = ["address", "cpf", "payment_method"]