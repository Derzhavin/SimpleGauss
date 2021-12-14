//
// Created by denis on 09.12.2021.
//

#include "simple_gauss.cuh"

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

__global__ void simple_gauss_straight_passage_kernel (double  *g_mat, unsigned int n, unsigned int number_row, unsigned int number_col)

//__global__ void simple_gauss_kernel (double  *g_mat, double  *g_mat_sol, unsigned int rows, unsigned int cols)
{
    unsigned int i = blockIdx.y * blockDim.y + threadIdx.y;
    unsigned int j = blockIdx.x * blockDim.x + threadIdx.x;

    if ( i > number_row && j < n + 1)
    {
        double pivot = g_mat[number_row * (n  + 1) + number_row];
        double coeff = g_mat[i * (n  + 1) + number_row];
        coeff /= pivot;
        double mat_kj = g_mat[number_row * (n  + 1) + j];
        double res = coeff * mat_kj;
        g_mat[i * (n  + 1) + j] -= res;
    }
}

//__global__ void simple_gauss_backward_passage_kernel(double  *g_mat, double  *g_mat_sol, unsigned int n, unsigned int number_row, unsigned int number_col)
//{
//    unsigned int i = blockIdx.y * blockDim.y + threadIdx.y;
//    unsigned int j = blockIdx.x * blockDim.x + threadIdx.x;
//
//    if (i == n - 1 - number_row  && j >= number_row && j < n - 1)
//    {
//        atomicAdd(&g_mat_sol[number_row], -(g_mat[number_row * (n + 1) + j + 1] * g_mat_sol[j + 1]));
//    }
//    __syncthreads();
//
//    if (i == number_row && j == 0)
//    {
//        g_mat_sol[number_row] += g_mat[number_row * (n + 1) + n];
//        g_mat_sol[number_row] /= g_mat[number_row * (n + 1) + number_row];
//    }
//}
void simple_gauss(double *h_mat, double *h_mat_sol, unsigned int n)
{
    double *d_mat;
    cudaMalloc((void **) &d_mat, n * (n + 1) * sizeof(double));
    cudaMemcpy(d_mat, h_mat, n * (n + 1) * sizeof(double), cudaMemcpyHostToDevice);

//    double *d_mat_sol;
//    cudaMalloc((void **) &d_mat_sol, n * sizeof(double));
//    cudaMemcpy(d_mat, h_mat, n * sizeof(double), cudaMemcpyHostToDevice);

    int threadsPerBlockDim = 16;
    dim3 block(threadsPerBlockDim, threadsPerBlockDim, 1);
    int blocksPerGridDimX = ceilf((n + 1) / (double)threadsPerBlockDim);
    int blocksPerGridDimY = ceilf(n / (double)threadsPerBlockDim);
//    printf("%d, %d\n", blocksPerGridDimY, blocksPerGridDimX);
    dim3 grid(blocksPerGridDimX, blocksPerGridDimY, 1);

    for (int i = 0; i < n - 1; ++i)
    {
        simple_gauss_straight_passage_kernel<<<grid, block>>>(d_mat, n, i, i);
//        CHECK(cudaDeviceSynchronize());
        CHECK(cudaStreamSynchronize(0));
        CHECK(cudaGetLastError());
    }
//    for (int i = 0; i < n; ++i)
//    {
//        simple_gauss_backward_passage_kernel<<<grid, block>>>(d_mat, d_mat_sol, n, n - 1 - i, n - 1 - i);
//        CHECK(cudaDeviceSynchronize());
//        CHECK(cudaGetLastError());
//    }
//    cudaMemcpy(h_mat_sol, d_mat_sol, n * sizeof(double), cudaMemcpyDeviceToHost);
    cudaMemcpy(h_mat, d_mat, n * (n + 1) * sizeof(double), cudaMemcpyDeviceToHost);

    for (size_t k = 0, i; k < n; ++k)
    {
        h_mat_sol[n - 1 - k] = h_mat[(n - 1 - k) * (n + 1) + n];
        for (i = n - 1 - k; i < n - 1; ++i)
            h_mat_sol[n - 1 - k] -= h_mat[(n - 1 - k) * (n + 1) + i + 1] * h_mat_sol[i + 1];
        h_mat_sol[n - 1 - k] /= h_mat[(n - 1 - k) * (n + 1) + n - 1 - k];
    }

    cudaFree(d_mat);
//    cudaFree(d_mat_sol);
}