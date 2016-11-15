#ifndef _PHP_MYCALLBACK_H
#define _PHP_MYCALLBACK_H

//加载config.h，如果配置了的话
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
 
//加载php头文件
#include "php.h"

#define PHP_MYCALLBACK_VERSION "1.0"
#define PHP_MYCALLBACK_EXTNAME "mycallback"

PHP_FUNCTION(mycallback_call);

extern zend_module_entry mycallback_module_entry;
#define phpext_mycallback_ptr &mycallback_module_entry

#endif
