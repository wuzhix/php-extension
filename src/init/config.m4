PHP_ARG_ENABLE(myinit, whether to enable init and shutdown support,[--enable-myinit Enable init and shutdown support])

if test "$PHP_MYINIT" = "yes"; then
    AC_DEFINE(HAVE_MYINIT, 1, [Whether you have init and shutdown])
    PHP_NEW_EXTENSION(myinit, myinit.c, $ext_shared)
fi