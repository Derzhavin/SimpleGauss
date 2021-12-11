//
// Created by denis on 10.12.2021.
//

#include "matrix/DenseMat.h"
#include "SimpleGaussCpu.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "too few program arguments, need 1" << std::endl;
        return 0;
    }

    size_t n = strtol(argv[1], nullptr, 0);
    float low = -100;
    float high = 100;

    SimpleGaussCPU<DenseMat<float>, float> cpuSolver;

    DenseMat<float> mat(DenseMat<float>::genRandMat(n, n + 1, low, high));
    auto cpuSolution(cpuSolver.solve(mat));
    return 0;
}