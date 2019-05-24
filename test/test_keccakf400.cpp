#include <iostream>

using namespace std;

#include "keccakf.h"

using namespace NAMESPACE_NAME;

int main() {
    KeccakF<uint16_t> f1;
    
    f1.permute();
    
    uint32_t f1r1[25] = {
        0x09F5, 0x40AC, 0x0FA9, 0x14F5, 0xE89F,
        0xECA0, 0x5BD1, 0x7870, 0xEFF0, 0xBF8F,
        0x0337, 0x6052, 0xDC75, 0x0EC9, 0xE776,
        0x5246, 0x59A1, 0x5D81, 0x6D95, 0x6E14,
        0x633E, 0x58EE, 0x71FF, 0x714C, 0xB38E,
    };
    
    for (auto i = 0; i != 25; i++) {
        assert(f1.state[i] == f1r1[i]);
    }
    
    f1.permute();
    
    uint32_t f1r2[25] = {
        0xE537, 0xD5D6, 0xDBE7, 0xAAF3, 0x9BC7,
        0xCA7D, 0x86B2, 0xFDEC, 0x692C, 0x4E5B,
        0x67B1, 0x15AD, 0xA7F7, 0xA66F, 0x67FF,
        0x3F8A, 0x2F99, 0xE2C2, 0x656B, 0x5F31,
        0x5BA6, 0xCA29, 0xC224, 0xB85C, 0x097C,
    };
    
    for (auto i = 0; i != 25; i++) {
        assert(f1.state[i] == f1r2[i]);
    }
    
    
    return 0;
}