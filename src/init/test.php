<?php
//加载hello扩展
if (!extension_loaded('myinit')) {
    if (strtoupper(substr(PHP_OS, 0, 3)) === 'WIN') {
        dl('php_myinit.dll');
    } else {
        dl('myinit.so');
    }
}
//调用扩展提供的接口
my_hello_world();
my_hello_world();