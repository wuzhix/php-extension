#include "php_myresource.h"

static zend_function_entry myresource_functions[] = {
    PHP_FE(my_fopen, NULL)
    PHP_FE(my_fwrite, NULL)
    PHP_FE(my_fread, NULL)
    PHP_FE(my_fclose, NULL)
    {NULL, NULL, NULL}
};

zend_module_entry myresource_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_MYRESOURCE_EXTNAME, //这个地方是扩展名称，往往我们会在这个地方使用一个宏。
    myresource_functions,  /* Functions */
    ZEND_MINIT(myresource),/* MINIT */
    NULL,               /* MSHUTDOWN */
    NULL,               /* RINIT */
    NULL,               /* RSHUTDOWN */
    NULL,               /* MINFO */
#if ZEND_MODULE_API_NO >= 20010901
    PHP_MYRESOURCE_VERSION,    //扩展的版本号
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_MYRESOURCE
    ZEND_GET_MODULE(myresource)
#endif

static void php_sample_descriptor_dtor(zend_resource *rsrc)
{
    FILE* fp = (FILE*)rsrc->ptr;
    fclose(fp);
    if (buffer != NULL)
    {
        free(buffer);
        buffer = NULL;
    }
}

ZEND_MINIT_FUNCTION(myresource)
{
    le_sample_descriptor = zend_register_list_destructors_ex(php_sample_descriptor_dtor, NULL, PHP_SAMPLE_DESCRIPTOR_RES_NAME,module_number);
    return SUCCESS;
}

PHP_FUNCTION(my_fopen)
{
    char* filename, *mode;
    size_t filename_len=0, mode_len=0;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss", &filename, &filename_len, &mode, &mode_len) == FAILURE)
    {
        RETURN_NULL();
    }
    if (filename_len == 0 || mode_len == 0)
    {
        php_printf("param is error\n");
        RETURN_FALSE;
    }
    FILE* fp = VCWD_FOPEN(filename, mode);
    if (fp == NULL)
    {
        php_printf("VCWD_FOPEN %s failed\n", *filename);
        RETURN_FALSE;
    }
    RETURN_RES(zend_register_resource(fp, le_sample_descriptor));
}

PHP_FUNCTION(my_fwrite)
{
    zval* file_resource;
    char* data;
    size_t data_len;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rs", &file_resource, &data, &data_len) == FAILURE)
    {
        RETURN_NULL();
    }
    FILE* fp = (FILE*)zend_fetch_resource(Z_RES_P(file_resource), PHP_SAMPLE_DESCRIPTOR_RES_NAME, le_sample_descriptor);
    if (fp == NULL)
    {
        RETURN_FALSE;
    }
    RETURN_LONG(fwrite(data, sizeof(char), data_len, fp));
}

PHP_FUNCTION(my_fread)
{
    zval* file_resource;
    zend_long data_len;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rl", &file_resource, &data_len) == FAILURE)
    {
        RETURN_NULL();
    }
    FILE* fp = (FILE*)zend_fetch_resource(Z_RES_P(file_resource), PHP_SAMPLE_DESCRIPTOR_RES_NAME, le_sample_descriptor);
    if (fp == NULL)
    {
        RETURN_FALSE;
    }
    if (buffer == NULL)
    {
        buffer = (char*)calloc(data_len+1, sizeof(char));
    }
    else
    {
        buffer = (char*)realloc(buffer, (data_len+1)*sizeof(char));
    }
    fread(buffer, sizeof(char), data_len, fp);
    RETURN_STRING(buffer);
}

PHP_FUNCTION(my_fclose)
{
    zval* file_resource;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "r", &file_resource) == FAILURE)
    {
        RETURN_NULL();
    }
    zend_list_close(Z_RES_P(file_resource));
    RETURN_TRUE;
}
