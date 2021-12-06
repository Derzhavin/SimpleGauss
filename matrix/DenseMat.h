//
// Created by denis on 05.12.2021.
//

#ifndef SIMPLEGAUSS_DENSEMAT_H
#define SIMPLEGAUSS_DENSEMAT_H

#include "BasicMat.h"

#include <iostream>

template<typename MatT>
class DenseMat: public BasicMat<DenseMat<MatT>, MatT>
{
    friend class BasicMat<DenseMat<MatT>, MatT>;
    using Base = BasicMat<DenseMat<MatT>, MatT>;

    MatT** _arr;
public:
    DenseMat(size_t rows, size_t cols):
            BasicMat<DenseMat<MatT>, MatT>(rows, cols), _arr(new MatT * [rows])
    {
        _arr[0] = new MatT [rows * cols] {0};
        for (size_t i = 1; i != rows ; ++i)
            _arr[i] = _arr[i - 1] + cols;
    }
    ~DenseMat()
    {
        if (_arr)
        {
            delete _arr[0];
            delete [] _arr;
        }
    }
    DenseMat(DenseMat&& other): DenseMat()
    {
        this->swap(other);
    }
    DenseMat(DenseMat const & other):
            BasicMat<DenseMat<MatT>, MatT>(other._rowsSize, other._colsSize),
            _arr(new MatT * [Base::_rowsSize])
    {
        _arr[0] = new MatT [Base::_rowsSize * Base::_colsSize] {0};
        for (size_t i = 1; i != Base::_rowsSize ; ++i)
            _arr[i] = _arr[i - 1] + Base::_colsSize;

        std::copy(other._arr[0], other._arr[0] + Base::_rowsSize * Base::_colsSize, _arr[0]);
    }

    DenseMat& operator=(DenseMat const& other)
    {
        if(this != &other)
            DenseMat(other).swap(*this);
        return *this;
    }
    DenseMat& operator=(DenseMat other)
    {
        this->swap(other);
        return *this;
    }

    void swap(DenseMat& other) throw()
    {
        _arr = other._arr;
        Base::_rowsSize = other._rowsSize;
        Base::_colsSize = other._colsSize;

        other._arr = nullptr;
        other._rowsSize = 0;
        other._colsSize = 0;
    }
    inline MatT * const row(size_t& i)
    {
        return _arr[i];
    }
private:
    DenseMat(): BasicMat<DenseMat<MatT>, MatT>(0, 0), _arr(nullptr) {}
};


#endif //SIMPLEGAUSS_DENSEMAT_H
