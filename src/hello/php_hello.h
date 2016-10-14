#ifndef _PHP_HELLO_H
#define _PHP_HELLO_H

//加载config.h，如果配置了的话
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
 
//加载php头文件
#include "php.h"

#define PHP_HELLO_WORLD_VERSION "1.0"
#define PHP_HELLO_WORLD_EXTNAME "hello"

PHP_FUNCTION(hello_world);
extern zend_module_entry hello_module_entry;
#define phpext_hello_ptr &hello_module_entry

#endif
