<?php

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
