#ifndef _PHP_MYINIT_H
#define _PHP_MYINIT_H

//加载config.h，如果配置了的话
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
 
//加载php头文件
#include "php.h"

#define PHP_MYINIT_VERSION "1.0"
#define PHP_MYINIT_EXTNAME "myinit"

PHP_FUNCTION(my_hello_world);
PHP_MINIT_FUNCTION(myinit);
PHP_MSHUTDOWN_FUNCTION(myinit);
PHP_RINIT_FUNCTION(myinit);
PHP_RSHUTDOWN_FUNCTION(myinit);

extern zend_module_entry myinit_module_entry;
#define phpext_myinit_ptr &myinit_module_entry

#endif
