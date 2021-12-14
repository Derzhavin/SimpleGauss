//
// Created by denis on 14.12.2021.
//

#ifndef SIMPLEGAUSS_SOLUTIONCHECKER_H
#define SIMPLEGAUSS_SOLUTIONCHECKER_H

#include <matrix/BaseMat.h>

template<class MatImpl, typename MatT>
bool solChecker(BaseMat<MatImpl, MatT>& mat, BaseMat<MatImpl, MatT>& matSol)
{
    MatT sum = 0;
    for (size_t i = 0, j; i < mat.rowsSize(); ++i) {
        sum = 0;
        for (j = 0; i < mat.rowsSize(); ++i)
            sum += mat[i][j] * matSol[0][j];
        sum -= matSol[0][mat.rowsSize()];
        if (sum > 2)
            return false;
    }
    return true;
}

#endif //SIMPLEGAUSS_SOLUTIONCHECKER_H
