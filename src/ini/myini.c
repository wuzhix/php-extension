#include "php_myini.h"

PHP_INI_BEGIN()
    PHP_INI_ENTRY("myini.default", "ini test", PHP_INI_ALL, NULL)
PHP_INI_END()

static zend_function_entry myini_functions[] = {
    PHP_FE(myini_get_default, NULL)
    PHP_FE_END
};

zend_module_entry myini_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_MYINI_EXTNAME, //这个地方是扩展名称，往往我们会在这个地方使用一个宏。
    myini_functions,    /* Functions */
    PHP_MINIT(myini),          /* MINIT */
    PHP_MSHUTDOWN(myini),      /* MSHUTDOWN */
    NULL,               /* RINIT */
    NULL,               /* RSHUTDOWN */
    PHP_MINFO(myini),          /* MINFO */
#if ZEND_MODULE_API_NO >= 20010901
    PHP_MYINI_VERSION,	//扩展的版本号
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_MYINI
    ZEND_GET_MODULE(myini)
#endif

PHP_FUNCTION(myini_get_default)
{
    const char* def = INI_STR("myini.default");
    php_printf("%s\n", def);
}

PHP_MINIT_FUNCTION(myini)
{
    REGISTER_INI_ENTRIES();
    return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(myini)
{
    UNREGISTER_INI_ENTRIES();
    return SUCCESS;
}

PHP_MINFO_FUNCTION(myini)
{
    DISPLAY_INI_ENTRIES();
}