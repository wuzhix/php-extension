#ifndef _PHP_MYVARIABLE_H
#define _PHP_MYVARIABLE_H

//加载config.h，如果配置了的话
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
 
//加载php头文件
#include "php.h"

#define PHP_MYVARIABLE_VERSION "1.0"
#define PHP_MYVARIABLE_EXTNAME "myvariable"

PHP_FUNCTION(myvariable_get_null);
PHP_FUNCTION(myvariable_get_bool);
PHP_FUNCTION(myvariable_get_long);
PHP_FUNCTION(myvariable_get_double);
PHP_FUNCTION(myvariable_get_string);
extern zend_module_entry myvariable_module_entry;
#define phpext_myvariable_ptr &myvariable_module_entry

#endif
