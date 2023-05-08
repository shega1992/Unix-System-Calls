# Unix-System-Calls
This repository holds the source code for my versions of Unix system calls. The idea for the project is taken from **Linux Programming Interface** book(See Exercise 5-4, 5-7) https://man7.org/tlpi/. I'm going to add new system calls in the future.
## How does it works?
Basically I used an approach that I had previously used in https://github.com/shega1992/memory-allocator. There is a set of functions(system calls) that are compiled as a library and can be used in your programs. 
### Current set of system calls
1) **wdup**
2) **wdup2**
3) **wreadv**
4) **wwritev**

Note: all system calls are non-atomic and are prefixed with **w**, which distinguishes them from standard Unix versions. 
## How to use these system calls?
To compile: **gcc -shared -fPIC wdup.c wreadv_wwritev.c -o libwl.so** (Makefile will be added in the future)

Follow the procedure described in  https://github.com/shega1992/memory-allocator (***'How to use this allocator?'*** section).
# Tests directory
I attach a primitive program to each system call to test it.
