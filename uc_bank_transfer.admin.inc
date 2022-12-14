<?php

/**
 * @file
 * Payment pack administration menu items.
 *
 */

/**
 * Receive a Bank Transfer for an order.
 */
function uc_bank_transfer_receive_bank_transfer_form($form, $form_state, $order) {
  $balance = uc_payment_balance($order);
  $form['balance'] = array('#markup' => uc_currency_format($balance));
  $form['order_id'] = array(
    '#type' => 'hidden',
    '#value' => $order->order_id,
  );
  $form['amount'] = array(
    '#type' => 'textfield',
    '#title' => t('Amount'),
    '#default_value' => uc_currency_format($balance, FALSE, FALSE, '.'),
    '#size' => 10,
    '#field_prefix' => config_get('uc_store.settings', 'uc_sign_after_amount') ? '' : config_get('uc_store.settings', 'uc_currency_sign'),
    '#field_suffix' => config_get('uc_store.settings', 'uc_sign_after_amount') ? config_get('uc_store.settings', 'uc_currency_sign') : '',
  );
  $form['comment'] = array(
    '#type' => 'textfield',
    '#title' => t('Receipt No. / Comment'),
    '#description' => t('Any notes about the Bank Transfer, like receipt number.'),
    '#size' => 64,
    '#maxlength' => 256,
  );
  $form['clear'] = array(
    '#type' => 'fieldset',
    '#title' => t('Expected clear date'),
    '#collapsible' => FALSE,
  );
  $form['clear']['clear_month'] = uc_select_month(NULL, format_date(REQUEST_TIME, 'custom', 'n'));
  $form['clear']['clear_day'] = uc_select_day(NULL, format_date(REQUEST_TIME, 'custom', 'j'));
  $form['clear']['clear_year'] = uc_select_year(NULL, format_date(REQUEST_TIME, 'custom', 'Y'), format_date(REQUEST_TIME, 'custom', 'Y'), format_date(REQUEST_TIME, 'custom', 'Y') + 1);
  foreach (array('clear_month', 'clear_day', 'clear_year') as $key) {
    $form['clear'][$key]['#prefix'] = '<div style="float: left; margin-right: 1em;">';
    $form['clear'][$key]['#suffix'] = '</div>';
  }
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Receive Bank Transfer'),
  );

  return $form;
}

/**
 * Generate form to receive a bank transfer
 */
function theme_uc_bank_transfer_receive_bank_transfer_form($variables) {
  $form = $variables['form'];

  $output = '<p>' . t('Use the form to enter the Bank Transfer into the payments system and set the expected clear date.') . '</p>';
  $output .= '<p><strong>' . t('Order balance:') . '</strong> '
           . backdrop_render($form['balance']) . '</p>';

  $output .= backdrop_render_children($form);

  return $output;
}

/**
 * Validate bank transfer reception form
 */
function uc_bank_transfer_receive_bank_transfer_form_validate($form, &$form_state) {
  if (!is_numeric($form_state['values']['amount'])) {
    form_set_error('amount', t('The amount must be a number.'));
  }
}

/**
 * Submit bank transfer reception form
 */
function uc_bank_transfer_receive_bank_transfer_form_submit($form, &$form_state) {
  global $user;

  uc_payment_enter($form_state['values']['order_id'], 'bank_transfer',
                  $form_state['values']['amount'], $user->uid, '', $form_state['values']['comment']);

  db_insert('uc_payment_bank_transfer')
    ->fields(array(
    'order_id' => $form_state['values']['order_id'],
    'clear_date' => mktime(12, 0, 0, $form_state['values']['clear_month'], $form_state['values']['clear_day'], $form_state['values']['clear_year']),
  ))
    ->execute();

  backdrop_set_message(t('Bank Transfer received, expected clear date of @date.', array(
    '@date' => date(config_get('uc_store.settings', 'date_format_uc_store'), mktime(12, 0, 0, $form_state['values']['clear_month'], $form_state['values']['clear_day'], $form_state['values']['clear_year'])),
  )));

  backdrop_goto('admin/store/orders/' . $form_state['values']['order_id']);
}
