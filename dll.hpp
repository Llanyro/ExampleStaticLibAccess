// dll.hpp

#ifndef DLL_HPP_
#define DLL_HPP_

#if defined(__unix__)
#define DLL_API

#elif defined(DLL_EXPORTS)
#define DLL_API __declspec(dllexport)

#else
#define DLL_API __declspec(dllimport)

#endif

#include "item.hpp"

extern "C" {
	// Creates an Apple thats inherited of item
	DLL_API Item* createApple();
}

#endif // !DLL_HPP_
