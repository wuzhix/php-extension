#ifndef _PHP_MYINI_H
#define _PHP_MYINI_H

//加载config.h，如果配置了的话
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
 
//加载php头文件
#include "php.h"

#define PHP_MYINI_VERSION "1.0"
#define PHP_MYINI_EXTNAME "myini"

PHP_FUNCTION(myini_get_default);
PHP_MINIT_FUNCTION(myini);
PHP_MSHUTDOWN_FUNCTION(myini);
PHP_MINFO_FUNCTION(myini);

extern zend_module_entry myini_module_entry;
#define phpext_myini_ptr &myini_module_entry

#endif
