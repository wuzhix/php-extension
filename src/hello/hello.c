#include "php_hello.h"

static zend_function_entry hello_functions[] = {
    PHP_FE(hello_world, NULL)
    {NULL, NULL, NULL}
};

zend_module_entry hello_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_HELLO_WORLD_EXTNAME, //这个地方是扩展名称，往往我们会在这个地方使用一个宏。
    hello_functions,    /* Functions */
    NULL,               /* MINIT */
    NULL,               /* MSHUTDOWN */
    NULL,               /* RINIT */
    NULL,               /* RSHUTDOWN */
    NULL,               /* MINFO */
#if ZEND_MODULE_API_NO >= 20010901
    PHP_HELLO_WORLD_VERSION,	//扩展的版本号
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_HELLO
    ZEND_GET_MODULE(hello)
#endif

PHP_FUNCTION(hello_world)
{
    php_printf("Hello World!\n");
}
