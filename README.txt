/* $Id$ */

-- INSTALLATION - INVOICE TEMPLATE --

To display the bank details on the invoices you need to do the following:
- Ubercart -2.2: copy the invoice template (customer_bank_transfer.itpl.php) to "/ubercart/uc_order/templates"
  -> note: be careful not to loose your template when updating Ubercart
- Ubercart 2.3+: copy the invoice template (uc_order-customer-bank_transfer.tpl.php) into your site theme "sites/all/themes/your-theme-name"
  -> note 1: you also need to copy uc_order.tpl.php from "/ubercart/uc_order/templates" into your site theme
  -> note 2: you may want to copy those files also into your admin theme to display the on-site invoices to the admin
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
