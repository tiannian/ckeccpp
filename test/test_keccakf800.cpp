#include <iostream>

using namespace std;

#include "keccakf.h"

using namespace NAMESPACE_NAME;

int main() {
    KeccakF<uint32_t> f1;
    
    f1.permute();
    
    uint32_t f1r1[25] = {
        0xE531D45D, 0xF404C6FB, 0x23A0BF99, 0xF1F8452F, 0x51FFD042,
        0xE539F578, 0xF00B80A7, 0xAF973664, 0xBF5AF34C, 0x227A2424,
        0x88172715, 0x9F685884, 0xB15CD054, 0x1BF4FC0E, 0x6166FA91,
        0x1A9E599A, 0xA3970A1F, 0xAB659687, 0xAFAB8D68, 0xE74B1015,
        0x34001A98, 0x4119EFF3, 0x930A0E76, 0x87B28070, 0x11EFE996,

    };
    
    for (auto i = 0; i != 25; i++) {
        assert(f1.state[i] == f1r1[i]);
    }
    
    f1.permute();
    
    uint32_t f1r2[25] = {
        0x75BF2D0D, 0x9B610E89, 0xC826AF40, 0x64CD84AB, 0xF905BDD6,
        0xBC832835, 0x5F8001B9, 0x15662CCE, 0x8E38C95E, 0x701FE543,
        0x1B544380, 0x89ACDEFF, 0x51EDB5DE, 0x0E9702D9, 0x6C19AA16,
        0xA2913EEE, 0x60754E9A, 0x9819063C, 0xF4709254, 0xD09F9084,
        0x772DA259, 0x1DB35DF7, 0x5AA60162, 0x358825D5, 0xB3783BAB,
    };
    
    for (auto i = 0; i != 25; i++) {
        assert(f1.state[i] == f1r2[i]);
    }
    
    
    return 0;
}
