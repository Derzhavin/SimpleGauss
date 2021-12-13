//
// Created by denis on 09.12.2021.
//

#ifndef SIMPLEGAUSS_SIMPLE_GAUSS_CUH
#define SIMPLEGAUSS_SIMPLE_GAUSS_CUH

//template<typename T>
//extern void simple_gauss_straight_passage(dim3 numBlocks, dim3 threadsPerBlock, T *g_mat, unsigned int rows, unsigned int cols);

//void simple_gauss_straight_passage(dim3 numBlocks, dim3 threadsPerBlock, double *g_mat, double *g_sol_mat, unsigned int rows, unsigned int cols);
void simple_gauss_straight_passage(float *g_mat, unsigned int rows, unsigned int cols);
#endif //SIMPLEGAUSS_SIMPLE_GAUSS_CUH
