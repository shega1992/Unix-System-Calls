# Unix-System-Calls-and-Library-Functions
This repository holds the source code for my versions of Unix system calls and library functions. The idea for the project is taken from **Linux Programming Interface** book(See Exercise 5-4, 5-7, 6-3, 8-2, 18-3, 18-5) https://man7.org/tlpi/. I'm going to add new system calls and library functions in the future.
## How does it works?
Basically I used an approach that I had previously used in https://github.com/shega1992/memory-allocator. There is a set of functions(system calls) that are compiled as a library and can be used in your programs. 
### Current set of system calls
1) **wdup**
2) **wdup2**
3) **wreadv**
4) **wwritev**
### Current set of library functions
1) **wsetenv**
2) **wunsetenv**
3) **wgetpwnam**
4) **wrealpath**
5) **wgetcwd**

Note: all system calls are non-atomic and are prefixed with **w**, which distinguishes them from standard Unix versions. Library functions are also prefixed with **w**.
## How to use these system calls?
To compile: **make all**

Follow the procedure described in  https://github.com/shega1992/memory-allocator (***'How to use this allocator?'*** section).
## Tests directory
I attach a primitive program to each system call and library function to test it.
## Footnotes
From **valgrind**'s point of view, the combination of the **wsetenv** and **wunsetenv** functions obviously leads to a memory leak. The logical solution would be to implement memory freeing in **wunsetenv**. 
This would probably complicate the source code. In addition, forcing the programmer to use **wunsetenv** after **wsetenv** every time in order to avoid memory leaks is a bad idea. Ultimately, all of the program’s space is given back to the system when the process terminates.
