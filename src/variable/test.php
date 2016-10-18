<?php
//加载myvariable扩展
if (!extension_loaded('myvariable')) {
    if (strtoupper(substr(PHP_OS, 0, 3)) === 'WIN') {
        dl('php_myvariable.dll');
    } else {
        dl('myvariable.so');
    }
}
//调用扩展提供的接口
var_dump(myvariable_get_null());
var_dump(myvariable_get_bool());
var_dump(myvariable_get_long());
var_dump(myvariable_get_double());
var_dump(myvariable_get_string());