//
// Created by denis on 06.12.2021.
//

#ifndef SIMPLEGAUSS_SIMPLEGAUSSCPU_H
#define SIMPLEGAUSS_SIMPLEGAUSSCPU_H

#include "computationAPI/SimpleCPUAPI.h"
#include <chrono>
template<class MatImpl, typename MatT>
class SimpleGaussCPU: public ISimpleGauss<SimpleGaussCPU<MatImpl, MatT>, MatImpl,MatT, SimpleCPUAPI> {
        friend class ISimpleGauss<SimpleGaussCPU<MatImpl, MatT>, MatImpl,MatT, SimpleCPUAPI>;

public:
    explicit SimpleGaussCPU(bool warnings= false):
        ISimpleGauss<SimpleGaussCPU<MatImpl, MatT>, MatImpl, MatT, SimpleCPUAPI>(warnings=warnings)
    {

    }
private:
        MatImpl solveImpl(BaseMat<MatImpl, MatT>& mat)
    {
        MatImpl matClone(static_cast<MatImpl&>(mat));
        BaseMat<MatImpl, MatT>& baseMatClone = matClone;

        MatImpl matSolution(1, mat.rowsSize());
        BaseMat<MatImpl, MatT>& baseMatSolution = matSolution;

        auto tBegin = std::chrono::system_clock::now();

        size_t i, j, k;
        double coeff;

        // Прямой проход
        double pivot;
        for (k = 0; k < mat.rowsSize() - 1; ++k)
        {
            pivot = baseMatClone[k][k];
            for (i = k + 1; i < mat.rowsSize(); ++i)
            {
                coeff = baseMatClone[i][k] / pivot;
                for (j = k; j < mat.rowsSize() + 1; ++j)
                    baseMatClone[i][j] -= coeff * baseMatClone[k][j];
            }
        }

        // Обратный проход
        for (k = 0; k < mat.rowsSize(); ++k)
        {
            baseMatSolution[0][mat.rowsSize() - 1 - k] = baseMatClone[mat.rowsSize() - 1 - k][mat.rowsSize()];
            for (i = mat.rowsSize() - 1 - k; i < mat.rowsSize() - 1; ++i)
                baseMatSolution[0][mat.rowsSize() - 1 - k] -= baseMatClone[mat.rowsSize() - 1 - k][i + 1] * baseMatSolution[0][i + 1];
            baseMatSolution[0][mat.rowsSize() - 1 - k] /= baseMatClone[mat.rowsSize() - 1 - k][mat.rowsSize() - 1 - k];
        }

        std::cout << "cpu exec time (us): " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - tBegin).count() << std::endl;

        return std::move(matSolution);
    }
};
#endif //SIMPLEGAUSS_SIMPLEGAUSSCPU_H