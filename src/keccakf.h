#ifndef CKECCPP_KECCAKF
#define CKECCPP_KECCAKF

#include "config.h"
#include "utils.h"

namespace NAMESPACE_NAME {

#define RC_B(x,n) ((((x##ull)>>n)&1)<<((1<<n)-1))
#define RC_X(T,x) ((T)(RC_B(x,0)|RC_B(x,1)|RC_B(x,2)|RC_B(x,3)|RC_B(x,4)|RC_B(x,5)|RC_B(x,6)))

/*
 1600 uint64_t 8  1 >> 3
 800  uint32_t 4  1 >> 2
 400  uint16_t 2  1 >> 1
 200  uint8_t  1  1 >> 0
 */
template <class T>
class KeccakF {
    public:
        T state[25];
    public:
        KeccakF();
        KeccakF(const KeccakF&);
        ~KeccakF() = default;
    public:
        void permute();
    public:
        const size_t nbytes = sizeof(T) * 25;
        const size_t nbits = nbytes * 8;
        const size_t nround = round_map<T>::value * 2 + 18;
        const T RC[24] = {
            RC_X(T, 0x01), RC_X(T, 0x1a), RC_X(T, 0x5e), RC_X(T, 0x70),
            RC_X(T, 0x1f), RC_X(T, 0x21), RC_X(T, 0x79), RC_X(T, 0x55),
            RC_X(T, 0x0e), RC_X(T, 0x0c), RC_X(T, 0x35), RC_X(T, 0x26),
            RC_X(T, 0x3f), RC_X(T, 0x4f), RC_X(T, 0x5d), RC_X(T, 0x53),
            RC_X(T, 0x52), RC_X(T, 0x48), RC_X(T, 0x16), RC_X(T, 0x66),
            RC_X(T, 0x79), RC_X(T, 0x58), RC_X(T, 0x21), RC_X(T, 0x74),
        };
    private:
        inline auto rol(T x, int s) -> T;
};

}

#endif
