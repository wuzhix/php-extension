PHP_ARG_ENABLE(myresource, whether to enable myresource support,[--enable-myresource Enable myresource support])

if test "$PHP_MYRESOURCE" = "yes"; then
    AC_DEFINE(HAVE_MYRESOURCE, 1, [Whether you have myresource])
    PHP_NEW_EXTENSION(myresource, myresource.c, $ext_shared)
fi