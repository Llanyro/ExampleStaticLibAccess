# ExampleStaticLibAccess
## What is this?
This is an example / test of a method to develop software for c/c++ with the feature that anyone can create libs(mods or plug-ins) to the main core
Also, this tests is mods/plug-ins can override functions (of interfaces classes) to use new functions (thats the thing of a mod/plug-in)

This code was tested in Ubuntu 20 (or 22, idk) and Windows 10

### How to compile this example with gcc(g++)
```bash
g++ -fPIC -c -o main.o main.cpp
g++ -o main main.o -ldl
g++ -fPIC -c -o dll.o dll.cpp
g++ -shared -o dll.so dll.o
```

### How to compile this example with MinGW
```bash
g++ -c -DDLL_EXPORTS dll.cpp
g++ -shared -o dll.dll dll.o -Wl,--out-implib,libdll.a
g++ main.cpp -o main.exe
main.exe
```
Prob it can be compiled with Visual Studio (not Visual Code)


# Important notes
Remember that including a dll/so in this way by default is not a vulnerability, BUT, is a hole that need to be controled depending the use of the technique.
For example, if you load <strong>N</strong> libs, that are in a folder, like a folder of mods, someone can add other "mod" that can do malicious things in the computer.
An example could be "dll hijacking", so be careful.
