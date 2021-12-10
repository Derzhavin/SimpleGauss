//
// Created by denis on 10.12.2021.
//

#include "matrix/DenseMat.h"
#include "SimpleGaussCuda/SimpleGaussCuda.h"
#include "SimpleGaussCpu.h"

int main(int argc, char *argv[])
{
    size_t n = strtol(argv[1], nullptr, 0);
    float low = -100;
    float high = 100;

    SimpleGaussCuda<float> cudaSolver(true);
    SimpleGaussCPU<DenseMat<float>, float> cpuSolver(true);

    DenseMat<float> mat(DenseMat<float>::genRandMat(n, n + 1, low, high));

    cudaSolver.solve(mat);
    cpuSolver.solve(mat);
    return 0;
}