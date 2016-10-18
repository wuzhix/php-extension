PHP_ARG_ENABLE(myvariable, whether to enable myvariable support,[--enable-myvariable Enable myvariable support])

if test "$PHP_MYVARIABLE" = "yes"; then
    AC_DEFINE(HAVE_MYVARIABLE, 1, [Whether you have variable])
    PHP_NEW_EXTENSION(myvariable, myvariable.c, $ext_shared)
fi