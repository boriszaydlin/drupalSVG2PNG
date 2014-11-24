# Changes that have been done to improve existing code example:

1. Added an argument in the hook_menu 'mysearch/%' and also a page argument parameter

2. Completely changed mysearch_searchpage function:

  2.1 Provided a proper title for the page using drupal_set_title without use of phtml tags inside the module

  2.2 Wrapped all text strings with a t function

  2.3 Used an existing search function for getting the list of nodes instead of writing a long and heavy SQL query to a wrong db table (node_revision contains only titles, but not body field data)

  2.4 Tried to keep code close to drupal coding standards (break long lines, provided trailing comas in arrays etc)
