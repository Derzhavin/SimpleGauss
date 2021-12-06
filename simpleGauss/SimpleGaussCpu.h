//
// Created by denis on 06.12.2021.
//

#ifndef SIMPLEGAUSS_SIMPLEGAUSSCPU_H
#define SIMPLEGAUSS_SIMPLEGAUSSCPU_H

#include "ISimpleGauss.h"
#include "computationAPI/SimpleCPUAPI.h"

template<class MatImpl>
class SimpleGaussCPU: public ISimpleGauss<SimpleGaussCPU<MatImpl>, MatImpl, SimpleCPUAPI> {
public:
    MatImpl solve(MatImpl& mat)
    {
        MatImpl matClone(mat);
        MatImpl matSolution(1, mat.rowsSize());

        size_t i, j, k;
        double coeff;

        // Прямой проход
        double pivot;
        for (k = 0; k < mat.rowsSize() - 1; ++k)
        {
            pivot = matClone[k][k];
            for (i = k + 1; i < mat.rowsSize(); ++i)
            {
                coeff = matClone[i][k] / pivot;
                for (j = k; j < mat.rowsSize() + 1; ++j)
                    matClone[i][j] -= coeff * matClone[k][j];
            }
        }

        // Обратный проход
        for (k = 0; k < mat.rowsSize(); ++k)
        {
            matSolution[0][mat.rowsSize() - 1 - k] = matClone[mat.rowsSize() - 1 - k][mat.rowsSize()];
            for (i = mat.rowsSize() - 1 - k; i < mat.rowsSize() - 1; ++i)
                matSolution[0][mat.rowsSize() - 1 - k] -= matClone[mat.rowsSize() - 1 - k][i + 1] * matSolution[0][i + 1];
            matSolution[0][mat.rowsSize() - 1 - k] /= matClone[mat.rowsSize() - 1 - k][mat.rowsSize() - 1 - k];
        }

        return std::move(matSolution);
    }
};
#endif //SIMPLEGAUSS_SIMPLEGAUSSCPU_H
