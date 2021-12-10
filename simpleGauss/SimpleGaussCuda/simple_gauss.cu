//
// Created by denis on 09.12.2021.
//

#include "simple_gauss.cuh"

//template<typename T>
//__global__ void simple_gauss_kernel (T *g_mat, T *g_sol_mat, size_t rows, size_t cols)
//{
//
//}
//
//template<typename T>
//void simple_gauss(dim3 grid, dim3 block, T *g_mat, T *g_sol_mat, size_t rows, size_t cols)
//{
//    simple_gauss_kernel<T><<<grid, block>>>(g_mat, g_sol_mat, rows, cols);
//}

__global__ void simple_gauss_kernel (double  *g_mat, double  *g_sol_mat, unsigned int rows, unsigned int cols)
{
    unsigned int i = blockIdx.y * blockDim.y + threadIdx.y;
    unsigned int j = blockIdx.x * blockDim.x + threadIdx.x;
    for (unsigned int k = 0; k < rows - 1; ++k)
    {
        if ( i > k)
        {
            double pivot = g_mat[k * cols + k];
            double coeff = g_mat[i * cols + k];
            coeff /= pivot;
            double mat_kj = g_mat[k * cols + j];
            g_mat[i * cols + j] -= coeff * mat_kj;
        }
    }
}

void simple_gauss(dim3 grid, dim3 block, double *g_mat, double *g_sol_mat, size_t rows, size_t cols)
{
    simple_gauss_kernel<<<grid, block>>>(g_mat, g_sol_mat, rows, cols);
}