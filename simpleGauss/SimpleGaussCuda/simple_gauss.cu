//
// Created by denis on 09.12.2021.
//

#include "simple_gauss.cuh"

//template<typename T>
//__global__ void simple_gauss (T *g_mat, T *g_sol_mat, size_t rows, size_t cols)
//{
//
//}
//
//template<typename T>
//void simple_gauss(dim3 grid, dim3 block, T *g_mat, T *g_sol_mat, size_t rows, size_t cols)
//{
//    simple_gauss<T><<<grid, block>>>(g_mat, g_sol_mat, rows, cols);
//}

__global__ void simple_gauss (double  *g_mat, double  *g_sol_mat, size_t rows, size_t cols)
{

}

void simple_gauss(dim3 grid, dim3 block, double *g_mat, double *g_sol_mat, size_t rows, size_t cols)
{
    simple_gauss<<<grid, block>>>(g_mat, g_sol_mat, rows, cols);
}