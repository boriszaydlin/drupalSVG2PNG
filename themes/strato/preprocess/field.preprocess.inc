<?php

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
   	    //dpm($variables);
  	    break;
  		
  	case 'field_svg_image_file':
  		$product = commerce_product_load($variables['element']['#object']->field_product['und'][0]['product_id']);
  	    $watermark = ($product->commerce_price['und'][0]['amount'] > 0);
	  	$uri = $variables['element']['#items'][0]['uri'];
		$styles = array_slice(image_styles(), 3);
		foreach($styles as $key => $value) {
			$variables['items'][0]['styles'][] = array(
				'title' => $key,
				'image' => _svgconv_convert($uri, $key, $watermark),
				'set' => _svgconv_generate_set($uri, $key, $watermark),
			);
		}
  		break;
  }
  
  //drupal_add_js('jQuery( ".tabs" ).tabs();', array('type' => 'inline', 'scope' => 'footer'));
}
