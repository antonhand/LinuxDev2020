#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([Number Guess], [0.0.0], [go@to.xyz])
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_SRCDIR([num_guess.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([libintl.h string.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([strcasecmp])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT


define(COMM, [\/\* COMMENT:: AC_PACKAGE_NAME, VERSION:: AC_PACKAGE_VERSION, DATE:: `date` \*\/])

sed -is "1s/.*COMMENT::.*VERSION::.*DATE.*//"  *.{c,h}
sed -is "1s/^/COMM\n/" *.{c,h}