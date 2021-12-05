//
// Created by denis on 05.12.2021.
//

#ifndef SIMPLEGAUSS_FIXEDMAT_H
#define SIMPLEGAUSS_FIXEDMAT_H

#include "IMat.h"

#include <iostream>

template<typename MatT>
class FixedMat: public IMat<FixedMat<MatT>, MatT>
{
    friend class IMat<FixedMat<MatT>, MatT>;
    size_t _colsSize;
    size_t _rowsSize;
    MatT** _arr;
public:
    FixedMat(size_t rows, size_t cols):
        IMat<FixedMat<MatT>, MatT>(), _rowsSize(rows), _colsSize(cols)
    {
        _arr = new MatT * [_rowsSize];
        _arr[0] = new MatT [_rowsSize * _colsSize] {0};
        for (size_t i = 1; i != _rowsSize ; ++i)
            _arr[i] = _arr[i - 1] + _colsSize;
    }
    virtual ~FixedMat()
    {
#ifdef DEBUG_FIXED_MAT
        std::cout << "~FixedMat()" << std::endl;
#endif
        if (_arr)
        {
            delete _arr[0];
            delete [] _arr;
        }
    }
    FixedMat(FixedMat&& other)
    {
#ifdef DEBUG_FIXED_MAT
        std::cout << "FixedMat(FixedMat&& other)" << std::endl;
#endif
        _arr = other._arr;
        _colsSize = other._colsSize;
        _rowsSize = other._rowsSize;
        other._colsSize = 0;
        other._rowsSize = 0;
        other._arr = nullptr;
    }

    inline MatT * const row(size_t i)
    {
        return _arr[i];
    }
    std::pair<size_t, size_t> dim()
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
};


#endif //SIMPLEGAUSS_FIXEDMAT_H
