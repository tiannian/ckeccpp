#ifndef CKECCPP_CONFIG_H
#define CKECCPP_CONFIG_H

#define NAMESPACE_NAME ckeccpp

#define CKECCPP_DEBUG 1

#include <cstring>
using std::memcpy;
using std::memset;

#include <cassert>

#if CKECCPP_DEBUG == 1

#include <iostream>

#define DEBUG(x) std::cout << x << std::endl

#endif

#endif

