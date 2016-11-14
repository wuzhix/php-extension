PHP_ARG_ENABLE(myini, whether to enable myini support,[--enable-myini Enable myini support])

if test "$PHP_MYINI" = "yes"; then
    AC_DEFINE(HAVE_MYINI, 1, [Whether you have variable])
    PHP_NEW_EXTENSION(myini, myini.c, $ext_shared)
fi