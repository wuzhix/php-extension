<?php
//加载myarray扩展
if (!extension_loaded('myarray')) {
    if (strtoupper(substr(PHP_OS, 0, 3)) === 'WIN') {
        dl('php_myarray.dll');
    } else {
        dl('myarray.so');
    }
}
//调用扩展提供的接口
$arr = array();
echo "init, arr is\n";
print_r($arr);
echo "\n";
myarray_add($arr, "key", "value");
echo "after add key=>value, arr is\n";
print_r($arr);
echo "\n";
myarray_del($arr, "key");
echo "after del key, arr is\n";
print_r($arr);
echo "\n";
myarray_add($arr, "key1", "value1");
echo "after add key1=>value1, arr is\n";
print_r($arr);
echo "\n";
myarray_del($arr, "key");
echo "after del key, arr is\n";
print_r($arr);
echo "\n";
myarray_update($arr, "key", "value1");
echo "after update key=>value1, arr is\n";
print_r($arr);
echo "\n";
myarray_update($arr, "key1", "value");
echo "after update key1=>value, arr is\n";
print_r($arr);
echo "\n";
myarray_find($arr, "key1");
myarray_find($arr, "key");
