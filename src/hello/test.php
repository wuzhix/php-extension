<?php
//加载hello扩展
if (!extension_loaded('hello')) {
    if (strtoupper(substr(PHP_OS, 0, 3)) === 'WIN') {
        dl('php_hello.dll');
    } else {
        dl('hello.so');
    }
}
//调用扩展提供的接口
hello_world();