#ifndef _PHP_MYREFERENCE_H
#define _PHP_MYREFERENCE_H

//加载config.h，如果配置了的话
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
 
//加载php头文件
#include "php.h"

#define PHP_MYREFERENCE_VERSION "1.0"
#define PHP_MYREFERENCE_EXTNAME "myreference"

PHP_FUNCTION(myreference_set_ref);
extern zend_module_entry myreference_module_entry;
#define phpext_myreference_ptr &myreference_module_entry

#endif
