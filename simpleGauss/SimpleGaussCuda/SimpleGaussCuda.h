//
// Created by denis on 07.12.2021.
//

#ifndef SIMPLEGAUSS_SIMPLEGAUSSCUDA_H
#define SIMPLEGAUSS_SIMPLEGAUSSCUDA_H


#include "simpleGauss/ISimpleGauss.h"
#include "computationAPI/CudaAPI.h"

template<class MatImpl, typename MatT>
class SimpleGaussCuda: public ISimpleGauss<SimpleGaussCuda<MatImpl, MatT>, MatImpl, MatT, CudaAPI> {
    friend class ISimpleGauss<SimpleGaussCuda<MatImpl, MatT>, MatImpl, MatT, CudaAPI>;

public:
    explicit SimpleGaussCuda(bool warnings= false):
            ISimpleGauss<SimpleGaussCuda<MatImpl, MatT>, MatImpl, MatT, CudaAPI>(warnings=warnings)
    {

    }

private:
    MatImpl solveImpl(BaseMat<MatImpl, MatT>& mat)
    {
        MatImpl matSolution(1, mat.rowsSize());
        BaseMat<MatImpl, MatT>& baseMatSolution = matSolution;

        return std::move(matSolution);
    }
};


#endif //SIMPLEGAUSS_SIMPLEGAUSSCUDA_H
