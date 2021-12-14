//
// Created by denis on 05.12.2021.
//

#ifndef SIMPLEGAUSS_IMATRIX_H
#define SIMPLEGAUSS_IMATRIX_H

#include <utility>
#include <cstddef>
#include <iostream>
#include <iomanip>
#include <random>

constexpr double myEps = 1e-1;

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
    inline std::pair<size_t, size_t> dim()
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
    inline MatT *  const row(size_t i)
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

    static bool cmp(BaseMat<MatImplT, MatT> &a, BaseMat<MatImplT, MatT> &b)
    {
        if (a.colsSize() != b.colsSize() || a.rowsSize() != b.rowsSize())
            return false;
        for (size_t i = 0, j; i < a.rowsSize(); ++i)
            for (j = 0; j < a.colsSize(); ++j)
                if ((std::isnan(a[i][j]) && !std::isnan(b[i][j]))
                    || (std::isnan(b[i][j]) && !std::isnan(a[i][j]))
                   || (std::isinf(b[i][j]) && !std::isinf(a[i][j]))
                      || (std::isinf(a[i][j]) && !std::isinf(b[i][j]))
                    || std::abs(a[i][j] - b[i][j]) > myEps)
                    return false;
        return true;
    }

    static MatImplT genRandMat(size_t n, size_t m, MatT low, MatT high)
    {
        std::random_device rd;
        std::default_random_engine eng(rd());
        std::uniform_real_distribution<MatT> distribution(low, high);

        MatImplT mat(n, m);

        for (size_t i = 0, j; i < n; ++i)
            for (j = 0; j < m; ++j)
                mat[i][j] = distribution(eng);

        return std::move(mat);
    }

private:
    inline MatImplT* impl()
    {
        return static_cast<MatImplT*>(this);
    }
};

#endif //SIMPLEGAUSS_IMATRIX_H
