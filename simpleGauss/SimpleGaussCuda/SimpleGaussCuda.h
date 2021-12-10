//
// Created by denis on 07.12.2021.
//

#ifndef SIMPLEGAUSS_SIMPLEGAUSSCUDA_H
#define SIMPLEGAUSS_SIMPLEGAUSSCUDA_H


#include "simpleGauss/ISimpleGauss.h"
#include "computationAPI/CudaAPI.h"
#include "matrix/DenseMat.h"
#include "simple_gauss.cuh"

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
        DenseMat<MatT> matSolution(1, mat.rowsSize());

        MatT* dev_mat = nullptr;
        size_t dev_mat_glob_size = mat.rowsSize() * mat.colsSize() * sizeof(MatT);
        cudaMalloc((void**)&dev_mat, dev_mat_glob_size);
        cudaMemcpy(dev_mat, mat.row(0), dev_mat_glob_size, cudaMemcpyHostToDevice);

        MatT* dev_mat_sol = nullptr;
        size_t dev_mat_sol_glob_size = mat.rowsSize() * sizeof(MatT);
        cudaMalloc((void**)&dev_mat_sol, dev_mat_sol_glob_size);
        cudaMemcpy(dev_mat_sol, mat.row(0), dev_mat_sol_glob_size, cudaMemcpyHostToDevice);

        int threadsPerBlockDim = 32;
        dim3 block(threadsPerBlockDim, threadsPerBlockDim, 1);
        int blocksPerGridDimX = ceilf(matSolution.colsSize() / (float)threadsPerBlockDim);
        int blocksPerGridDimY = ceilf(matSolution.rowsSize() / (float)threadsPerBlockDim);
        dim3 grid(blocksPerGridDimX, blocksPerGridDimY);
//        simple_gauss<MatT>(grid, block, dev_mat, dev_mat_sol, mat.rowsSize(), mat.colsSize());
        simple_gauss(grid, block, dev_mat, dev_mat_sol, mat.rowsSize(), mat.colsSize());

        cudaMemcpy(mat.row(0), dev_mat_sol, dev_mat_sol_glob_size, cudaMemcpyDeviceToHost);

        DenseMat<MatT> mat1(mat.rowsSize(), mat.colsSize());
        cudaMemcpy(mat1.row(0), dev_mat, dev_mat_glob_size, cudaMemcpyDeviceToHost);

        mat1.printMatInStdin(10);

        cudaFree(dev_mat);
        cudaFree(dev_mat_sol);

        return std::move(matSolution);
    }
};


#endif //SIMPLEGAUSS_SIMPLEGAUSSCUDA_H
