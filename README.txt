/* $Id$ */

-- INSTALLATION - INVOICE TEMPLATE --

To display the bank details on the invoices you need to do the following:
- copy the invoice template to "/ubercart/uc_order/templates"
  (which template?: - customer_bank_transfer.itpl.php for Ubercart version <= 2.2
                    - uc_order-customer-bank_transfer.tpl.php for Ubercart version >= 2.3)
- select the customer_bank_transfer template for on-site invoices:
  -> Administer/Store administration/Configuration/Order settings/On-site invoice template
- select the customer_bank_transfer template for email invoices:
  -> Administer/Store administration/Conditional actions
    -> edit "E-mail customer checkout notification"
      -> Actions/Action: Email an order invoice/Invoice template

-- MULTILINGUAL SITES --

Please note the difference between i18n variables and i18n constants !

constants: you can translate them in
-> **/admin/build/translate/search

variables: you have to translate them on the settings page for each language directly
-> en/admin/store/settings/payment/edit/methods
-> de/admin/store/settings/payment/edit/methods
-> fr/admin/store/settings/payment/edit/methods
-> es/admin/store/settings/payment/edit/methods
-> etc.
