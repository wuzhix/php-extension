#ifndef _PHP_MYCLASS_H
#define _PHP_MYCLASS_H

//加载config.h，如果配置了的话
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
 
//加载php头文件
#include "php.h"

#define PHP_MYCLASS_VERSION "1.0"
#define PHP_MYCLASS_EXTNAME "myclass"

ZEND_MINIT_FUNCTION(myclass);
ZEND_METHOD(my_class, __construct);
ZEND_METHOD(my_class, public_method);

extern zend_module_entry myclass_module_entry;
#define phpext_myclass_ptr &myclass_module_entry

#endif
