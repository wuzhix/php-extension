#include "php_myclass.h"

zend_class_entry *myclass_ce;

zend_function_entry myclass_method[] = {
    ZEND_ME(my_class, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
    ZEND_ME(my_class, public_method, NULL, ZEND_ACC_PUBLIC)
    {NULL, NULL, NULL}
};

zend_module_entry myclass_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_MYCLASS_EXTNAME, //这个地方是扩展名称，往往我们会在这个地方使用一个宏。
    NULL,               /* Functions */
    ZEND_MINIT(myclass),/* MINIT */
    NULL,               /* MSHUTDOWN */
    NULL,               /* RINIT */
    NULL,               /* RSHUTDOWN */
    NULL,               /* MINFO */
#if ZEND_MODULE_API_NO >= 20010901
    PHP_MYCLASS_VERSION,    //扩展的版本号
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_MYCLASS
    ZEND_GET_MODULE(myclass)
#endif

ZEND_MINIT_FUNCTION(myclass)
{
    zend_class_entry ce;

    //my_class是类的名字
    INIT_CLASS_ENTRY(ce, "my_class", myclass_method);
    myclass_ce = zend_register_internal_class(&ce);
    //定义属性
    zend_declare_property_long(myclass_ce, ZEND_STRL("public_long"), 110, ZEND_ACC_PUBLIC);
    return SUCCESS;
}

ZEND_METHOD(my_class, __construct)
{
    php_printf("调用__construct方法\n");
    // zval *age;
    // zend_class_entry *ce;
    // ce = Z_OBJCE_P(getThis());
    // zval rv;
    // age = zend_read_property(ce, getThis(), ZEND_STRL("public_long"), 0, &rv);
    // php_var_dump(age, 1);
    // zend_update_property_long(ce, getThis(), ZEND_STRL("public_long"), 108);
    // age = zend_read_property(ce, getThis(), ZEND_STRL("public_long"), 0, &rv);
    // php_var_dump(age, 1);
}

ZEND_METHOD(my_class, public_method)
{
    php_printf("调用public_method方法\n");
}