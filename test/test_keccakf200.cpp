#include <iostream>

using namespace std;

#include "keccakf.h"

using namespace NAMESPACE_NAME;

int main() {
    KeccakF<uint8_t> f1;
    
    f1.permute();
    
    uint32_t f1r1[25] = {
        0x3C, 0x28, 0x26, 0x84, 0x1C,
        0xB3, 0x5C, 0x17, 0x1E, 0xAA,
        0xE9, 0xB8, 0x11, 0x13, 0x4C,
        0xEA, 0xA3, 0x85, 0x2C, 0x69,
        0xD2, 0xC5, 0xAB, 0xAF, 0xEA,
    };
    
    for (auto i = 0; i != 25; i++) {
        assert(f1.state[i] == f1r1[i]);
    }
    
    f1.permute();
    
    uint32_t f1r2[25] = {
        0x1B, 0xEF, 0x68, 0x94, 0x92,
        0xA8, 0xA5, 0x43, 0xA5, 0x99,
        0x9F, 0xDB, 0x83, 0x4E, 0x31,
        0x66, 0xA1, 0x4B, 0xE8, 0x27,
        0xD9, 0x50, 0x40, 0x47, 0x9E,

    };
    
    for (auto i = 0; i != 25; i++) {
        assert(f1.state[i] == f1r2[i]);
    }
    
    
    return 0;
}