/* $Id$ */

-- INSTALLATION --

To display the bank details on the invoices you need to do the following:
- copy the invoice template to "/ubercart/uc_order/templates"
- select the customer_bank_transfer template for on-site invoices:
  -> Administer/Store administration/Configuration/Order settings/On-site invoice template
- select the customer_bank_transfer template for email invoices:
  -> Administer/Store administration/Conditional actions
    -> edit "E-mail customer checkout notification"
      -> Actions/Action: Email an order invoice/Invoice template
