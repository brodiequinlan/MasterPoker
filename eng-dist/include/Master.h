#pragma once

/*
	you can either include this file in any project using this library to automatically pull the lib files from whereever you set them up

	or manually add the lib files (peng-mt for release builds and peng-mt-gd for debug builds) and pull in required headers as needed.
*/

#if defined(_DEBUG)
#pragma comment(lib, "peng-mt-gd")
#elif !defined(_DEBUG)
#pragma comment(lib, "peng-mt")
#endif

#include <Master/Card.hpp>
#include <Master/Hand.hpp>
#include <Master/Deck.hpp>