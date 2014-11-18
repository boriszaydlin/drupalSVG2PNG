<?php

/**
 * Implements hook_preprocess_field().
 */
function strato_preprocess_field(&$variables) {
  if ($variables['element']['#field_name'] == 'field_svg_image_file') {
  	$uri = $variables['element']['#items'][0]['uri'];
  	dpm(theme_image_style(array('style_name'=>'100x100', 'path'=>$uri)));
  	//dsm(drupal_realpath($uri));
  }
}
