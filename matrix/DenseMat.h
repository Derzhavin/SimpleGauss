//
// Created by denis on 05.12.2021.
//

#ifndef SIMPLEGAUSS_DENSEMAT_H
#define SIMPLEGAUSS_DENSEMAT_H

#include "BaseMat.h"

template<typename MatT>
class DenseMat: public BaseMat<DenseMat<MatT>, MatT>
{
    friend class BaseMat<DenseMat<MatT>, MatT>;
    using Base = BaseMat<DenseMat<MatT>, MatT>;

    MatT** _arr;
public:
    DenseMat(size_t rows, size_t cols):
            BaseMat<DenseMat<MatT>, MatT>(rows, cols), _arr(new MatT * [rows])
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
    DenseMat(DenseMat&& other) noexcept : DenseMat()
    {
        this->swap(other);
    }
    DenseMat(DenseMat const & other):
            BaseMat<DenseMat<MatT>, MatT>(other.Base::rowsSize(), other.Base::colsSize()),
            _arr(new MatT * [Base::rowsSize()])
    {
        _arr[0] = new MatT [Base::rowsSize() * Base::colsSize()] {0};
        for (size_t i = 1; i != Base::rowsSize() ; ++i)
            _arr[i] = _arr[i - 1] + Base::colsSize();

        std::copy(other._arr[0], other._arr[0] + Base::rowsSize() * Base::colsSize(), _arr[0]);
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

    void swap(DenseMat& other) noexcept
    {
        _arr = other._arr;
        Base::_rowsSize = other.rowsSize();
        Base::_colsSize = other.colsSize();

        other._arr = nullptr;
        other._rowsSize = 0;
        other._colsSize = 0;
    }
    inline MatT * const rowImpl(size_t i)
    {
        return _arr[i];
    }
    DenseMat(): BaseMat<DenseMat<MatT>, MatT>(0, 0), _arr(nullptr) {}
};


#endif //SIMPLEGAUSS_DENSEMAT_H
