<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * strato theme.
 */


/**
 * Implements hook_preprocess_field().
 */
function strato_preprocess_field(&$variables) {
  $watermark = TRUE;
  switch ($variables['element']['#field_name']) {
    case 'field_product':
      $product = commerce_product_load($variables['element'][0]['product_id']['#value']);
        if ($product->commerce_price['und'][0]['amount'] == 0){
          $variables['element'][0]['#attributes']['class'][] = 'hidden';
        }
        break;
      
    case 'field_svg_image_file':
      $product = commerce_product_load($variables['element']['#object']->field_product['und'][0]['product_id']);
        $watermark = ($product->commerce_price['und'][0]['amount'] > 0);
      $uri = $variables['element']['#items'][0]['uri'];
    $styles = _svgconv_activestyles();
    foreach($styles as $key => $value) {
      $variables['items'][0]['styles'][] = array(
        'title' => $value,
        'image' => _svgconv_convert($uri, $key, $watermark),
        'set' => _svgconv_generate_set($uri, $key, $watermark),
      );
    }
      break;
  }
}


/**
 * Implements hook_preprocess_node().
 */
function strato_preprocess_node(&$variables) {
  if ($variables['type'] == 'article') {
    $product = commerce_product_load($variables['field_product'][0]['product_id']);
    if($product->commerce_price['und'][0]['amount'] == 0) {
      $variables['classes_array'][] = 'buy-hidden';
    }
  } 
}
