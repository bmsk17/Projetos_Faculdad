from django.db import models
from django.contrib.auth.models import User
from django.core.validators import MinValueValidator 

CREDIT = "Credit"
DEBIT = "Debit"
PIX = "Pix"
PAYMENT_CHOICES = [
    (CREDIT, "Cartão de crédito"),
    (DEBIT, "Cartão de débito"),
    (PIX, "Pix"),
]


class Product(models.Model):
    name = models.CharField(max_length=255, blank=False)
    desc_full = models.TextField()
    desc_short = models.TextField()
    price = models.FloatField()
    stock = models.IntegerField()
    size = models.IntegerField()
    image = models.ImageField()

    def __str__(self):
        return f"{self.name} -- Num. {self.size}"


class Sale(models.Model):
    product = models.ForeignKey(Product, on_delete=models.PROTECT)
    user = models.ForeignKey(User, on_delete=models.PROTECT)
    address = models.TextField(verbose_name="Endereço de entrega")
    cpf = models.CharField(verbose_name="CPF na nota", max_length=255, blank=False)
    quantity = models.IntegerField(verbose_name="Quantidade", validators=[MinValueValidator(1)])

    payment_method = models.CharField(
        verbose_name="Método de pagamento",
        max_length=255,
        choices=PAYMENT_CHOICES,
    )

    def __str__(self):
        return f"{self.quantity} x {self.product} -> {self.user} (CPF: {self.cpf})"

