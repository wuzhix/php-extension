#ifndef _PHP_MYRESOURCE_H
#define _PHP_MYRESOURCE_H

//加载config.h，如果配置了的话
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
 
//加载php头文件
#include "php.h"

#define PHP_MYRESOURCE_VERSION "1.0"
#define PHP_MYRESOURCE_EXTNAME "myresource"
#define PHP_SAMPLE_DESCRIPTOR_RES_NAME "山寨文件描述符"
static int le_sample_descriptor;
static char* buffer = NULL;

ZEND_MINIT_FUNCTION(myresource);
PHP_FUNCTION(my_fopen);
PHP_FUNCTION(my_fwrite);
PHP_FUNCTION(my_fread);
PHP_FUNCTION(my_fclose);

extern zend_module_entry myresource_module_entry;
#define phpext_myresource_ptr &myresource_module_entry

#endif
