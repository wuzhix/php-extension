PHP_ARG_ENABLE(myclass, whether to enable myclass support,[--enable-myclass Enable myclass support])

if test "$PHP_MYCLASS" = "yes"; then
    AC_DEFINE(HAVE_MYCLASS, 1, [Whether you have myclass])
    PHP_NEW_EXTENSION(myclass, myclass.c, $ext_shared)
fi