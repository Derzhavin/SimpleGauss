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
        DenseMat<MatT> matClone(mat.rowsSize(), mat.colsSize());
        auto tBegin = std::chrono::system_clock::now();

        MatT* dev_mat = nullptr;
        size_t dev_mat_glob_size = mat.rowsSize() * mat.colsSize() * sizeof(MatT);
        cudaMalloc((void**)&dev_mat, dev_mat_glob_size);
        cudaMemcpy(dev_mat, mat.row(0), dev_mat_glob_size, cudaMemcpyHostToDevice);


//        simple_gauss_straight_passage<MatT>(numBlocks, threadsPerBlock, dev_mat, mat.rowsSize(), mat.colsSize());
        simple_gauss_straight_passage(dev_mat, mat.rowsSize(), mat.colsSize());

        cudaMemcpy(matClone.row(0), dev_mat, dev_mat_glob_size, cudaMemcpyDeviceToHost);

        // Обратный проход
        for (size_t k = 0, i; k < mat.rowsSize(); ++k)
        {
            for (i = mat.rowsSize() - 1 - k; i < mat.rowsSize() - 1; ++i)
                matSol[0][mat.rowsSize() - 1 - k] -= matClone[mat.rowsSize() - 1 - k][i + 1] * matSol[0][i + 1];
            matSol[0][mat.rowsSize() - 1 - k] =
                    (matSol[0][mat.rowsSize() - 1 - k] + matClone[mat.rowsSize() - 1 - k][mat.rowsSize()]) / matClone[mat.rowsSize() - 1 - k][mat.rowsSize() - 1 - k];
        }

        cudaFree(dev_mat);

        std::cout << "cuda exec time (us): " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - tBegin).count() << std::endl;

        return std::move(matSol);
    }
};


#endif //SIMPLEGAUSS_SIMPLEGAUSSCUDA_H
