//
// Created by denis on 09.12.2021.
//

#ifndef SIMPLEGAUSS_SIMPLE_GAUSS_CUH
#define SIMPLEGAUSS_SIMPLE_GAUSS_CUH

//template<typename T>
//extern void simple_gauss(dim3 grid, dim3 block, T *g_mat, T *g_sol_mat, size_t rows, size_t cols);

//void simple_gauss(dim3 grid, dim3 block, double *g_mat, double *g_sol_mat, size_t rows, size_t cols);
void simple_gauss(dim3 grid, dim3 block, float *g_mat, float *g_sol_mat, size_t rows, size_t cols);
#endif //SIMPLEGAUSS_SIMPLE_GAUSS_CUH
