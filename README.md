# C - Libraries

Collection of some of the function as a library.

Some ideas were taken from various python modules.

Libraries written in C language.

How to compile??
----------------

- compile header_file.c to a shared object or dynamically linked library

`gcc -shared -fPIC header_file.c -o libheader_file.so`

- copy libheader_file.so to /usr/lib/

`sudo cp libheader_file.so /usr/lib/`

- copy header_file.h to /usr/include/

`sudo cp header_file.h /usr/include/`
