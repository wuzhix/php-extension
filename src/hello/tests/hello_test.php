<?php
if (!extension_loaded('hello')) {
    if (strtoupper(substr(PHP_OS, 0, 3)) === 'WIN') {
        dl('php_hello.dll');
    } else {
        dl('hello.so');
    }
}
hello_world();