<?php

/**
 * Form for adding / editing a sms entity.
 */
function sms_form($form, &$form_state, $sms = NULL) {
  $form['mobile'] = array(
    '#title' => t('Name'),
    '#type' => 'textfield',
    '#default_value' => isset($sms->mobile) ? $sms->mobile : '',
    '#description' => t('Mobile Number'),
    '#required' => TRUE,
    '#weight' => -50,
  );

  $form['message'] = array(
    '#title' => t('Message Code'),
    '#type' => 'textarea',
    '#default_value' => isset($sms->message) ? $sms->message : '',
    '#description' => t('Message Text'),
    '#required' => TRUE,
  );


  field_attach_form('sms', $sms, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($sms->id) ? t('Update SMS') : t('Save SMS asset'),
    ),
  );

  return $form;
}

/**
 * Submit handler for sms entity form.
 */
function sms_form_submit($form, &$form_state) {
  $sms = entity_ui_form_submit_build_entity($form, $form_state);
  $sms->save();
  drupal_set_message(t('SMS  has been saved.'));
  $form_state['redirect'] = 'admin/sms';
}
