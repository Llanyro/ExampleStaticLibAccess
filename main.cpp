// main.cpp

#include <iostream>
#include "manager.hpp"

class Potato : public Item {
    public:
        virtual const char* getName() override { return "Potato"; }
        virtual int getPrice() override { return 10; }
};

#if defined(_WIN32)
#include <Windows.h>

typedef HMODULE ll_lib_t;
#define load_lib(a) LoadLibrary(a)
#define get_lib_address GetProcAddress
#define close_lib FreeLibrary
#define LIB_STR "dll.dll"

inline const char* dlerror() { return ""; }

#elif defined(__unix__)
#include <dlfcn.h>

typedef void* ll_lib_t;
//#define load_lib(a) dlopen(a, RTLD_NOW)
//#define load_lib(a) dlopen(a, RTLD_LOCAL | RTLD_LAZY)
#define load_lib(a) dlopen(a, RTLD_LAZY)
#define get_lib_address dlsym
#define close_lib dlclose
#define LIB_STR "./dll.so"

#endif


int main() {
    // Not needed in MinGW, but needed(prob) in Visual Studio (not Visual Code)
    // Converts an ASCII string to Unicode
    ///int size = MultiByteToWideChar(CP_ACP, 0, "dll.dll", -1, NULL, 0);
    ///wchar_t* buffer = new wchar_t[size];
    ///MultiByteToWideChar(CP_ACP, 0, "dll.dll", -1, buffer, size);

    // Load DLL/so
    ///ll_lib_t hModule = LoadLibrary(buffer);
    ll_lib_t hModule = load_lib(LIB_STR);
    if (hModule == NULL) {
        std::cout << "Error al cargar la DLL" << std::endl;
        ///delete[] buffer;
        return 1;
    }
    ///delete[] buffer;

    // Get create Apple funtion from dll/so
    typedef Item* (*Create)();
    Create createApple = (Create)get_lib_address(hModule, "createApple");
    if (createApple == NULL) {
        std::cout << "Error getting address of function createApple" << std::endl;
        close_lib(hModule);
        return 1;
    }

    // Now we create the manager that manages Items
    Manager* m = Manager::getInstance();
    // And an item defined in this file (Potato)
    Item* potato = new Potato();
    // And last, we instance an iten created in the dll/so
    Item* apple = createApple();

    // We add both to the manager
    m->addItem(apple);
    m->addItem(potato);

    // And we test that the item is ok, has overloaded 'Item' functions
    //   and is correctly used as an imported object
    ///auto items = m->getItems();
    for (auto& item : m->items)
        std::cout << item.second->getName() << ": " << item.second->getPrice() << std::endl;

    // Last thing is to remove all items and memoy generated
    ///m->removeItem(apple);
    ///m->removeItem(patata);
    delete apple;
    delete potato;

    // And remember to close the dll/so
    close_lib(hModule);

    return 0;
}
