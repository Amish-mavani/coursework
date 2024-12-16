<?php
// array_search()
$array = array('1', '2', '3', '4', '5');
print_r($array);
if (($key = array_search('4', $array)) !== false) {
    unset($array[$key]);
}
print_r($array);

// array_diff()
$array = array('1', '2', '3', '4', '5');
print_r($array);
$narray = array_diff($array, array('5'));
print_r($narray);
?>