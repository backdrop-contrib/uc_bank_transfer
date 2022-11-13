This module provides an Ubercart payment method. It helps to display the shop's bank account details to the customer so a direct money transfer can be initiated by the customer. Depending on where you are from you might call this method bank transfer, wire transfer, giro transfer or direct deposit.

Features
---

There are two ways to use this module (or a combination of both):
- Put all the information you need to show to the customer into the "Payment instructions" field
- Or use the provided bank details fields which is the recommended option for multilingual websites
(current fields: Account owner, Account number, IBAN, Bank code (useful for BSB / Sort code / Bank code / Clearing number / Routing transit number or Bank transit number), SWIFT, Banking institution, Branch office)

A token [uc_order:payment-bank-details] is created which can be use to display the payment information on the invoice.
Optionally the order ID can be displayed along the payment details as 'Reason for payment'.

Installation
---------------
- Install this module using the [official Backdrop CMS instructions](https://backdropcms.org/guide/modules)


Credits
-----
- Drupal 7 development sponsored by [Origondo AG](https://www.origondo.com/)
- Original Drupal 7 development by [xweb](http://drupal.org/node/168778). Also merged functionality from a module originally developed by [Oliver Coleman](http://drupal.org/user/169370).
- Ported to Backdrop CMS by [argiepiano](https://github.com/argiepiano)

Current Backdrop CMS version mantainer
-----
[argiepiano](https://github.com/argiepiano)

License
---------------
This project is GPL v2 software. See the LICENSE.txt file in this directory
for complete text.