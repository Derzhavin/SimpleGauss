//
// Created by denis on 05.12.2021.
//

#ifndef SIMPLEGAUSS_IMATRIX_H
#define SIMPLEGAUSS_IMATRIX_H

#include <utility>
#include <stddef.h>

template<class MatImplT, typename MatT>
class IMat {
public:
    inline MatT * const operator [] (size_t i)
    {
        return static_cast<MatImplT*>(this)->row(i);
    }
    inline std::pair<size_t, size_t> dim()
    {
        return static_cast<MatImplT*>(this)->dim();
    }
    inline size_t colsSize()
    {
        return static_cast<MatImplT*>(this)->colsSize();
    }
    inline size_t rowsSize()
    {
        return static_cast<MatImplT*>(this)->rowsSize();
    }
    inline MatT * const row(size_t i)
    {
        return static_cast<MatImplT*>(this)->row(i);
    }
};


#endif //SIMPLEGAUSS_IMATRIX_H
