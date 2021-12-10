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
//
#include <cstdio>

#define CHECK(call)                                                            \
{                                                                              \
    const cudaError_t error = call;                                            \
    if (error != cudaSuccess)                                                  \
    {                                                                          \
        fprintf(stderr, "Error: %s:%d, ", __FILE__, __LINE__);                 \
        fprintf(stderr, "code: %d, reason: %s\n", error,                       \
                cudaGetErrorString(error));                                    \
    }                                                                          \
}

__global__ void simple_gauss_kernel (float  *g_mat, float  *g_mat_sol, unsigned int rows, unsigned int cols)

//__global__ void simple_gauss_kernel (double  *g_mat, double  *g_mat_sol, unsigned int rows, unsigned int cols)
{
    unsigned int i = blockIdx.y * blockDim.y + threadIdx.y;
    unsigned int j = blockIdx.x * blockDim.x + threadIdx.x;
    unsigned int k;

    // Прямой проход
    for (k = 0; k < rows - 1; ++k)
    {
        if ( i > k && j < cols)
        {
            float pivot = g_mat[k * cols + k];
            float coeff = g_mat[i * cols + k];
            coeff /= pivot;
            float mat_kj = g_mat[k * cols + j];
            g_mat[i * cols + j] -= coeff * mat_kj;
        }
        __syncthreads();
    }

    __syncthreads();

    // Обратный проход
    for (k = 0; k < rows; ++k)
    {
        if (i == rows - 1 - k && j == 0)
        {
            g_mat_sol[rows - 1 - k] = g_mat[(rows - 1 - k) * cols + rows];
        }
        __syncthreads();

        if (i == k && j >= rows - 1 - k && j < rows - 1)
        {
             atomicAdd(&g_mat_sol[rows - 1 - k], -(g_mat[(rows - 1 - k) * cols + j + 1] * g_mat_sol[j + 1]));
        }
        __syncthreads();

       if (i == rows - 1 - k && j == 0)
       {
           g_mat_sol[rows - 1 - k] /= g_mat[(rows - 1 - k) * cols + rows - 1 - k];
       }
        __syncthreads();
    }
}
void simple_gauss(dim3 grid, dim3 block, float *g_mat, float *g_sol_mat, size_t rows, size_t cols)

//void simple_gauss(dim3 grid, dim3 block, double *g_mat, double *g_sol_mat, size_t rows, size_t cols)
{
//    cudaDeviceSynchronize();
    simple_gauss_kernel<<<grid, block>>>(g_mat, g_sol_mat, rows, cols);
    CHECK(cudaDeviceSynchronize());
}