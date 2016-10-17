#include "php_myinit.h"

static zend_function_entry hello_functions[] = {
    PHP_FE(my_hello_world, NULL)
    {NULL, NULL, NULL}
};

zend_module_entry myinit_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_MYINIT_EXTNAME,     //这个地方是扩展名称，往往我们会在这个地方使用一个宏。
    hello_functions,        /* Functions */
    PHP_MINIT(myinit),      /* MINIT */
    PHP_MSHUTDOWN(myinit),  /* MSHUTDOWN */
    PHP_RINIT(myinit),      /* RINIT */
    PHP_RSHUTDOWN(myinit),  /* RSHUTDOWN */
    NULL,                   /* MINFO */
#if ZEND_MODULE_API_NO >= 20010901
    PHP_MYINIT_VERSION, //扩展的版本号
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_MYINIT
    ZEND_GET_MODULE(myinit)
#endif

PHP_FUNCTION(my_hello_world)
{
    php_printf("Hello World!\n");
}

PHP_MINIT_FUNCTION(myinit)
{
	php_printf("module init\n");
    return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(myinit)
{
    php_printf("module shutdown\n");
    return SUCCESS;
}

PHP_RINIT_FUNCTION(myinit)
{
    php_printf("request init\n");
    return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(myinit)
{
    php_printf("request shutdown\n");
    return SUCCESS;
}
