#include "php_myreference.h"

ZEND_BEGIN_ARG_INFO(myreference_set_ref_arginfo, 0)
    ZEND_ARG_PASS_INFO(1)
ZEND_END_ARG_INFO()

static zend_function_entry myreference_functions[] = {
    PHP_FE(myreference_set_ref, myreference_set_ref_arginfo)
    {NULL, NULL, NULL}
};

zend_module_entry myreference_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_MYREFERENCE_EXTNAME, //这个地方是扩展名称，往往我们会在这个地方使用一个宏。
    myreference_functions,    /* Functions */
    NULL,               /* MINIT */
    NULL,               /* MSHUTDOWN */
    NULL,               /* RINIT */
    NULL,               /* RSHUTDOWN */
    NULL,               /* MINFO */
#if ZEND_MODULE_API_NO >= 20010901
    PHP_MYREFERENCE_VERSION,	//扩展的版本号
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_MYREFERENCE
    ZEND_GET_MODULE(myreference)
#endif

PHP_FUNCTION(myreference_set_ref)
{
    zval *a;
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &a) == FAILURE)
    {
        RETURN_NULL();
    }
    ZVAL_STRING(&(a->value.ref->val),"modify param");

    return;
}