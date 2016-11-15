<?php
//加载mycallback扩展
if (!extension_loaded('mycallback')) {
    if (strtoupper(substr(PHP_OS, 0, 3)) === 'WIN') {
        dl('php_mycallback.dll');
    } else {
        dl('mycallback.so');
    }
}

function test_printf($text)
{
	echo "content is {$text}\n";
	return gettype($text);
}

//调用扩展提供的接口
$ret = mycallback_call("test_printf", "hello");
echo "return is {$ret}\n";
$ret = mycallback_call("test_printf", 110);
echo "return is {$ret}\n";
