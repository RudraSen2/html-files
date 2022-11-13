function cal() {
  if (document.getElementById('input-area').value === 0) {
  } else if (document.getElementById('input-sale-price').value === 0) {
  } else {
    var area = document.getElementById('input-area').value;
    area = Math.round(area / 10.76);

    var sale = document.getElementById('input-sale-price').value;
    var lease_rent = area * 35.4;
    lease_rent = Math.round(lease_rent);
    var circleRate = 15 * area * 84 + area * 32200;

    var payment = 0;
    if (circleRate > sale) {
      payment = circleRate;
    } else {
      payment = sale;
    }
    payment = Math.round(payment * 0.05 + 300);

    document.getElementById('display-payment').innerHTML =
      'Stamp Duty Payable = ₹' + payment + '/-';
    document.getElementById('pop').innerHTML = 'Click Here for Account Details';
    document.getElementById('display-draft').innerHTML =
      'Lease Rent DEMAND DRAFT Payable in Favour of SIIDCUL Dehradun = ₹' +
      lease_rent +
      '/-';
  }
}
function reset() {
  document.getElementById('input-area').value = '';
  document.getElementById('input-sale-price').value = '';
  document.getElementById('display-payment').innerHTML = '';
  document.getElementById('display-draft').innerHTML = '';
  document.getElementById('pop').innerHTML = '';
}