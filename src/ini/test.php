<?php
//加载myini扩展
if (!extension_loaded('myini')) {
    if (strtoupper(substr(PHP_OS, 0, 3)) === 'WIN') {
        dl('php_myini.dll');
    } else {
        dl('myini.so');
    }
}
//调用扩展提供的接口
myini_get_default();
print_r(phpinfo());