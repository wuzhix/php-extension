#include "php_myarray.h"

static zend_function_entry myarray_functions[] = {
    PHP_FE(myarray_add, NULL)
    PHP_FE(myarray_del, NULL)
    PHP_FE(myarray_update, NULL)
    PHP_FE(myarray_find, NULL)
    {NULL, NULL, NULL}
};

zend_module_entry myarray_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_MYARRAY_EXTNAME, //这个地方是扩展名称，往往我们会在这个地方使用一个宏。
    myarray_functions,    /* Functions */
    NULL,               /* MINIT */
    NULL,               /* MSHUTDOWN */
    NULL,               /* RINIT */
    NULL,               /* RSHUTDOWN */
    NULL,               /* MINFO */
#if ZEND_MODULE_API_NO >= 20010901
    PHP_MYARRAY_VERSION,	//扩展的版本号
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_MYARRAY
    ZEND_GET_MODULE(myarray)
#endif

PHP_FUNCTION(myarray_add)
{
    zval *a, *key, *pData;
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "azz", &a, &key, &pData) == FAILURE)
    {
        RETURN_NULL();
    }

    HashTable *ht = Z_ARRVAL_P(a);
    zend_string *zend_key = zval_get_string(key);
    if(zend_hash_exists(ht, zend_key))
    {
        php_printf("add, %s is exists\n", Z_STRVAL_P(key));
    }
    else
    {
        zend_hash_add(ht, zend_key, pData);
    }
    return;
}

PHP_FUNCTION(myarray_del)
{
    zval *a, *key;
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "az", &a, &key) == FAILURE)
    {
        RETURN_NULL();
    }

    HashTable *ht = Z_ARRVAL_P(a);
    zend_string *zend_key = zval_get_string(key);
    if(zend_hash_exists(ht, zend_key))
    {
        zend_hash_del(ht, zend_key);
    }
    else
    {
        php_printf("del, %s is not exists\n", Z_STRVAL_P(key));
    }
    return;
}

PHP_FUNCTION(myarray_update)
{
    zval *a, *key, *pData;
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "azz", &a, &key, &pData) == FAILURE)
    {
        RETURN_NULL();
    }

    HashTable *ht = Z_ARRVAL_P(a);
    zend_string *zend_key = zval_get_string(key);
    if(zend_hash_exists(ht, zend_key))
    {
        zend_hash_update(ht, zend_key, pData);
    }
    else
    {
        php_printf("update, %s is not exists\n", Z_STRVAL_P(key));
    }
    return;
}

PHP_FUNCTION(myarray_find)
{
    zval *a, *key, *find;
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "az", &a, &key) == FAILURE)
    {
        RETURN_NULL();
    }

    HashTable *ht = Z_ARRVAL_P(a);
    zend_string *zend_key = zval_get_string(key);
    find = zend_hash_find(ht, zend_key);
    if(find == NULL)
    {
        php_printf("find, %s is not exists\n", Z_STRVAL_P(key));
    }
    else
    {
        php_printf("find, %s is find, type is %d\n", Z_STRVAL_P(key), Z_TYPE_P(find));
    }
    return;
}

