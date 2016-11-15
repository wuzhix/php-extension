PHP_ARG_ENABLE(mycallback, whether to enable mycallback support,[--enable-mycallback Enable mycallback support])

if test "$PHP_MYCALLBACK" = "yes"; then
    AC_DEFINE(HAVE_MYCALLBACK, 1, [Whether you have variable])
    PHP_NEW_EXTENSION(mycallback, mycallback.c, $ext_shared)
fi