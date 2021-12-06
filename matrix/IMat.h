//
// Created by denis on 05.12.2021.
//

#ifndef SIMPLEGAUSS_IMATRIX_H
#define SIMPLEGAUSS_IMATRIX_H

#include <utility>
#include <stddef.h>

template<class MatImplT, typename MatT>
class IMat {
protected:
    size_t _colsSize;
    size_t _rowsSize;

public:
    IMat(size_t rows, size_t cols): _rowsSize(rows), _colsSize(cols) {}

    inline MatT * const operator [] (size_t i)
    {
        return impl()->row(i);
    }
    inline std::pair<size_t, size_t> dim()
    {
        return std::make_pair(_rowsSize, _colsSize);
    }
    inline size_t colsSize()
    {
        return _colsSize;
    }
    inline size_t rowsSize()
    {
        return _rowsSize;
    }
    inline MatT * const row(size_t i)
    {
        return impl()->row(i);
    }
private:
    inline MatImplT* impl()
    {
        return static_cast<MatImplT*>(this);
    }
};


#endif //SIMPLEGAUSS_IMATRIX_H
