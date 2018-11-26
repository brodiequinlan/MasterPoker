#pragma once

//uncomment when building static
//comment out when building as dll, if you want to have compile time optimizations. If this is not commented out, wont tell compiler that the DLL is going to export the function pointer directly rather than just an entry in the IAT of the DLL but will still build as dynamic if library is set to build that way

#define MP_BUILD_STATIC true

#include "MasterPoker/card.hpp"
#include "MasterPoker/enums.hpp"
#include "MasterPoker/hand_strength.hpp"
#include "MasterPoker/hands.hpp"
#include "MasterPoker/helper.hpp"
#include "MasterPoker/Deck.hpp"
#include "MasterPoker/Parser.h"