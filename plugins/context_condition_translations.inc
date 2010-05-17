<?php

/**
 * Expose primary links as context reactions.
 */
class context_condition_translations extends context_condition {
  
  function condition_values() {
    $options = array();
    $result = db_query("SELECT nid, title FROM {node} WHERE type = 'page'");
    
    while($node = db_fetch_object($result)) {
      $options[$node->nid] = truncate_utf8($node->title, 50);
    }
    
    error_log('options: '. var_export($options, TRUE));
    
    
    return $options;
  }
  
  function options_form($context) {
    $form = parent::condition_form($context);
    $form['#type'] = 'select';
    return $form;
  }

  /**
   * Set the primary links menu;
   */
  function execute($value = NULL) {
    $contexts = context_active_contexts();
    $classes = array();    

    error_log('args: '. var_export($contexts, TRUE));
    

    // foreach ($contexts as $k => $v) {
    //   $custom = $v->reactions[$this->plugin]['primary_links'];
    //   if (!empty($custom)) {
    //     global $conf;
    //     $conf['menu_primary_links_source'] = $custom;
    //   } 
    // }
  }
}
