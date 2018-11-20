#pragma once


#ifdef MP_BUILD_DLL
#define MASTER_API __declspec(dllexport)
#else 
#define MASTER_API __declspec(dllimport)
#endif
