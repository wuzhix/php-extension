#ifndef _PHP_MYARRAY_H
#define _PHP_MYARRAY_H

//加载config.h，如果配置了的话
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
 
//加载php头文件
#include "php.h"

#define PHP_MYARRAY_VERSION "1.0"
#define PHP_MYARRAY_EXTNAME "myarray"

PHP_FUNCTION(myarray_add);
PHP_FUNCTION(myarray_del);
PHP_FUNCTION(myarray_update);
PHP_FUNCTION(myarray_find);
extern zend_module_entry myarray_module_entry;
#define phpext_myarray_ptr &myarray_module_entry

#endif
