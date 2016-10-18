#include "php_myvariable.h"

static zend_function_entry myvariable_functions[] = {
    PHP_FE(myvariable_get_null, NULL)
    PHP_FE(myvariable_get_bool, NULL)
    PHP_FE(myvariable_get_long, NULL)
    PHP_FE(myvariable_get_double, NULL)
    PHP_FE(myvariable_get_string, NULL)
    {NULL, NULL, NULL}
};

zend_module_entry myvariable_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_MYVARIABLE_EXTNAME, //这个地方是扩展名称，往往我们会在这个地方使用一个宏。
    myvariable_functions,    /* Functions */
    NULL,               /* MINIT */
    NULL,               /* MSHUTDOWN */
    NULL,               /* RINIT */
    NULL,               /* RSHUTDOWN */
    NULL,               /* MINFO */
#if ZEND_MODULE_API_NO >= 20010901
    PHP_MYVARIABLE_VERSION,	//扩展的版本号
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_MYVARIABLE
    ZEND_GET_MODULE(myvariable)
#endif

PHP_FUNCTION(myvariable_get_null)
{
    ZVAL_NULL(return_value);
    //RETVAL_NULL();
    return;
}

PHP_FUNCTION(myvariable_get_bool)
{
    ZVAL_BOOL(return_value, 1);
    //RETVAL_BOOL(1);
    return;
}

PHP_FUNCTION(myvariable_get_long)
{
    ZVAL_LONG(return_value, 10);
    //RETVAL_LONG(10);
    return;
}

PHP_FUNCTION(myvariable_get_double)
{
    ZVAL_DOUBLE(return_value, 1.01);
    //RETVAL_DOUBLE(1.01);
    return;
}

PHP_FUNCTION(myvariable_get_string)
{
    ZVAL_STRING(return_value, "test");
    //RETVAL_STRING("test");
    return;
}

