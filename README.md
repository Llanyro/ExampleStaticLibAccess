# ExampleStaticLibAccess
## What is this?
This is an example/test of a method for developing C/C++ software with the feature that anyone can create libraries (mods or plugins) for the main core.
Additionally, this test verifies that mods/plugins can override functions (of interface classes) to use new functions (that's the purpose of a mod/plugin).

This code has been tested on Ubuntu 20 (or 22, unsure) and Windows 10.

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
It's important to note that incorporating a dll/so in this manner is not inherently a vulnerability, but it does create a potential security hole that needs to be carefully managed, depending on the usage of the technique.
For example, if you load multiple libraries from a folder, such as a folder containing mods, someone could potentially add a malicious "mod" that could cause harm to the computer.
One example of this could be "dll hijacking," so it's crucial to exercise caution.
