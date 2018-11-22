#pragma once


#ifdef MP_BUILD_DLL
#define MASTER_API __declspec(dllexport)
#elif MP_BUILD_STATIC
#define MASTER_API
#else
#define MASTER_API __declspec(dllimport)


#endif
