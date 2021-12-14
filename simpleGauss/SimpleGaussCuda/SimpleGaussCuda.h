//
// Created by denis on 07.12.2021.
//

#ifndef SIMPLEGAUSS_SIMPLEGAUSSCUDA_H
#define SIMPLEGAUSS_SIMPLEGAUSSCUDA_H


#include "simpleGauss/ISimpleGauss.h"
#include "computationAPI/CudaAPI.h"
#include "matrix/DenseMat.h"
#include "simple_gauss.cuh"

#include <cmath>
#include <chrono>

template<typename MatT>
class SimpleGaussCuda: public ISimpleGauss<SimpleGaussCuda<MatT>, DenseMat<MatT>, MatT, CudaAPI> {
    friend class ISimpleGauss<SimpleGaussCuda<MatT>, DenseMat<MatT>, MatT, CudaAPI>;

public:
    explicit SimpleGaussCuda(bool warnings= false):
            ISimpleGauss<SimpleGaussCuda<MatT>, DenseMat<MatT>, MatT, CudaAPI>(warnings=warnings)
    {

    }

private:
    DenseMat<MatT> solveImpl(BaseMat<DenseMat<MatT>, MatT>& mat)
    {

        DenseMat<MatT> matSol(1, mat.rowsSize());
        DenseMat<MatT> matClone(static_cast<DenseMat<MatT>&>(mat));

        auto tBegin = std::chrono::system_clock::now();
        simple_gauss(matClone.row(0), matSol.row(0), mat.rowsSize());
        std::cout << "cuda exec time (us): " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - tBegin).count() << std::endl;

        return std::move(matSol);
    }
};


#endif //SIMPLEGAUSS_SIMPLEGAUSSCUDA_H
