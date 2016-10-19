PHP_ARG_ENABLE(myarray, whether to enable myarray support,[--enable-myarray Enable myarray support])

if test "$PHP_MYARRAY" = "yes"; then
    AC_DEFINE(HAVE_MYARRAY, 1, [Whether you have variable])
    PHP_NEW_EXTENSION(myarray, myarray.c, $ext_shared)
fi