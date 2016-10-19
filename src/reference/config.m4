PHP_ARG_ENABLE(myreference, whether to enable myreference support,[--enable-myreference Enable myreference support])

if test "$PHP_MYREFERENCE" = "yes"; then
    AC_DEFINE(HAVE_MYREFERENCE, 1, [Whether you have myreference])
    PHP_NEW_EXTENSION(myreference, myreference.c, $ext_shared)
fi