#include "keccakf.h"

#define REPEAT5(e) e e e e e
#if KECCAK_OPT_FOR_SIZE // Size + 0 bytes, speed x 1/2
#    define FOR51(v, e) v = 0; REPEAT5(e; v += 1;)
#    define FOR55(v, e) for (v=0; v<25; v+= 5) { e; }
#    define REPEAT24(e) {int _j=0; for (_j=0; _j<24; _j++) { e }}
#elif KECCAK_OPT_FOR_SPEED // Size + 600 bytes, speed x1
#    define FOR51(v, e) v = 0; REPEAT5(e; v += 1;)
#    define FOR55(v, e) v = 0; REPEAT5(e; v += 5;)
#    define REPEAT24(e) e e e e e e e e e e e e e e e e e e e e e e e e
#elif KECCAK_OPT_FOR_SIZE_AGGRESSIVE // Terrible.  Actually makes things bigger
#    define FOR51(v, e) for (v=0; v<5; v++) { e; }
#    define FOR55(v, e) for (v=0; v<25; v+= 5) { e; }
#    define REPEAT24(e) {int _j=0; for (_j=0; _j<24; _j++) { e }}
#else // Size + 100 bytes, speed x 3/4
#    define FOR51(v, e) v = 0; REPEAT5(e; v += 1;)
#    define FOR55(v, e) for (v=0; v<25; v+= 5) { e; }
#    define REPEAT24(e) e e e e e e e e e e e e e e e e e e e e e e e e
#endif

namespace NAMESPACE_NAME {

template<class T>
KeccakF<T>::KeccakF() {
    memset(state,0,nbytes);
}

template<class T>
KeccakF<T>::KeccakF(const KeccakF& f) {
    memcpy(state, f.state, nbytes);
}

template<class T>
inline auto KeccakF<T>::rol(T x, int s) -> T {
    static const int WBITS = 8*sizeof(T);
    s %= WBITS;
    return (x << s) | (x >> (WBITS - s));
}

static const uint8_t pi[24] = {
    10, 7,  11, 17, 18, 3, 5,  16, 8,  21, 24, 4,
    15, 23, 19, 13, 12, 2, 20, 14, 22, 9,  6,  1
};

template<class T>
void KeccakF<T>::permute() {
    uint16_t x,y;
    for (int i = 0; i != nround; i++) {
        T b[5] = {0}, t, u;
        // Theta
        FOR51(x, b[x] = 0;)
        FOR55(y, FOR51(x, b[x] ^= state[x + y];))
        FOR55(y, FOR51(x,
            state[y + x] ^= b[(x + 4) % 5] ^ rol(b[(x + 1) % 5], 1);
        ))
        
        // Rho and pi
        t = state[1];
        x = y = 0;
        REPEAT24(u = state[pi[x]]; y += x+1; state[pi[x]] = rol(t, y); t = u; x++; )
        
        // Chi
        FOR55(y,
             FOR51(x, b[x] = state[y + x];)
             FOR51(x, state[y + x] = b[x] ^ ((~b[(x + 1) % 5]) & b[(x + 2) % 5]);)
        )
        
        // Iota
        state[0] ^= RC[i];
    }
}


template class KeccakF<uint64_t>;
template class KeccakF<uint32_t>;
template class KeccakF<uint16_t>;
template class KeccakF<uint8_t>;

}
