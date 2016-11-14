<?php
//加载myresource扩展
if (!extension_loaded('myresource')) {
    if (strtoupper(substr(PHP_OS, 0, 3)) === 'WIN') {
        dl('php_myresource.dll');
    } else {
        dl('myresource.so');
    }
}
//调用扩展提供的接口
$fp = my_fopen("./1.txt", "w");
my_fwrite($fp, "test\n");
my_fclose($fp);
$fp = my_fopen("./1.txt", "r");
$data = my_fread($fp, 100);
echo $data;
my_fclose($fp);