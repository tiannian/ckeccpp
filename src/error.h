#ifndef CKECCPP_ERROR_H
#define CKECCPP_ERROR_H

namespace NAMESPACE_NAME {

enum class Err {
    OK,
};

template<class T>
struct Result {
    Err err;
    T result;
};

template<>
struct Result<void> {
    Err err;
};

}

#endif
