<?php
//加载myvariable扩展
if (!extension_loaded('myclass')) {
    if (strtoupper(substr(PHP_OS, 0, 3)) === 'WIN') {
        dl('php_myclass.dll');
    } else {
        dl('myclass.so');
    }
}
//调用扩展提供的接口
$obj = new my_class();
$obj->public_method();
echo $obj->public_long."\n";
$obj->public_long = 10;
echo $obj->public_long."\n";