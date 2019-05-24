#ifndef CKECCPP_UTILS
#define CKECCPP_UTILS

template<class T>
struct round_map {};

template<>
struct round_map<uint64_t> {
    static const size_t value = 3;
};

template<>
struct round_map<uint32_t> {
    static const size_t value = 2;
};

template<>
struct round_map<uint16_t> {
    static const size_t value = 1;
};

template<>
struct round_map<uint8_t> {
    static const size_t value = 0;
};

#endif
