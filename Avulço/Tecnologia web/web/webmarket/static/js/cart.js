'use strict';

console.log("hello");

const CARD_FORM = `
<h2>Pagamento por cartão</h2>

<label for="card_num">Número do cartão:</label>      
<input type="text" name="card_num" maxlength="255" required="" id="card_num">

<label for="exp_date">Data de expiração:</label>      
<input type="text" name="exp_date" maxlength="5" required="" id="exp_date">

<label for="sec_code">Código de segurança:</label>      
<input type="text" name="sec_code" maxlength="3" required="" id="sec_code">

<label for="card_name">Nome no cartão:</label>      
<input type="text" name="card_name" maxlength="255" required="" id="card_name">

<button type="submit">CONFIRMAR COMPRA</button>
`
const PIX_FORM = `
<h2>Pagamento por Pix</h2>
<p>Favor pagar utilizando o link gerado abaixo e apertar confirmar:</p>
<p>
    <code>
        <a href="#">00020126580014br.gov.bcb.pix0136123e4567-e12b-12d1-a456-426655440000 5204000053039865802BR5913Fulano de Tal6008BRASILIA62070503***63041D3D</a>
    </code>
</p>
<button type="submit">CONFIRMAR COMPRA</button>
`


const pay_details = document.getElementById("payment-details");
const pay_method_select = document.getElementById("id_payment_method");
pay_method_select.onchange = () => {
    if ((pay_method_select.value == 'Debit') || (pay_method_select.value == 'Credit')) {
        pay_details.innerHTML = CARD_FORM;
    }
    else if (pay_method_select.value == 'Pix') {
        pay_details.innerHTML = PIX_FORM;
    }
    else {
        pay_details.innerHTML = '';
    }
};