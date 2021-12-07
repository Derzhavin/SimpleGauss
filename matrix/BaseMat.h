//
// Created by denis on 05.12.2021.
//

#ifndef SIMPLEGAUSS_IMATRIX_H
#define SIMPLEGAUSS_IMATRIX_H

#include <utility>
#include <stddef.h>
#include <iostream>
#include <iomanip>

template<class MatImplT, typename MatT>
class BaseMat {
protected:
    size_t _colsSize;
    size_t _rowsSize;

public:
    BaseMat(size_t rows, size_t cols): _rowsSize(rows), _colsSize(cols) {}

    inline MatT * const operator [] (size_t i)
    {
        return impl()->rowImpl(i);
    }
    inline std::pair<size_t, size_t> dim() const
    {
        return std::make_pair(_rowsSize, _colsSize);
    }
    inline size_t colsSize() const
    {
        return _colsSize;
    }
    inline size_t rowsSize() const
    {
        return _rowsSize;
    }
    inline MatT * const row(size_t i)
    {
        return impl()->rowImpl(i);
    }
    void printMatInStdin(size_t fieldWidth)
    {
        for (size_t j, i = 0; i < rowsSize(); ++i)
        {
            for (j = 0; j < colsSize(); ++j)
                std::cout << std::setw(fieldWidth) << (*this)[i][j] << " ";
            std::cout << std::endl;
        }
    }
private:
    inline MatImplT* impl()
    {
        return static_cast<MatImplT*>(this);
    }
};


#endif //SIMPLEGAUSS_IMATRIX_H
