#include "php_mycallback.h"

static zend_function_entry mycallback_functions[] = {
    PHP_FE(mycallback_call, NULL)
    PHP_FE_END
};

zend_module_entry mycallback_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_MYCALLBACK_EXTNAME, //这个地方是扩展名称，往往我们会在这个地方使用一个宏。
    mycallback_functions,    /* Functions */
    NULL,                    /* MINIT */
    NULL,                    /* MSHUTDOWN */
    NULL,                    /* RINIT */
    NULL,                    /* RSHUTDOWN */
    NULL,                    /* MINFO */
#if ZEND_MODULE_API_NO >= 20010901
    PHP_MYCALLBACK_VERSION,	//扩展的版本号
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_MYCALLBACK
    ZEND_GET_MODULE(mycallback)
#endif

PHP_FUNCTION(mycallback_call)
{
    zval* function_name;
    zval* arg;
    zval retval;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &function_name, &arg) == FAILURE)
    {
        RETURN_NULL();
    }
    if (Z_TYPE_P(function_name) != IS_STRING)
    {
        php_printf("function name must be a string\n");
        RETURN_FALSE;
    }
    //zval args[1] = {*arg};
    call_user_function(EG(function_table), NULL, function_name, &retval, 1, arg);
    *return_value=retval;
    //zval_ptr_dtor(&retval);
    //zval_ptr_dtor(arg);
}