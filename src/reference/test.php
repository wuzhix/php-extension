<?php
//加载myreference扩展
if (!extension_loaded('myreference')) {
    if (strtoupper(substr(PHP_OS, 0, 3)) === 'WIN') {
        dl('php_myreference.dll');
    } else {
        dl('myreference.so');
    }
}
//调用扩展提供的接口
$data = 110;
echo "before call func, data : {$data}\n";
myreference_set_ref($data);
echo "after call func, data : {$data}\n";