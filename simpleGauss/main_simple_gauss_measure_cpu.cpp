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
    double low = -100;
    double high = 100;

    SimpleGaussCPU<DenseMat<double>, double> cpuSolver;

    DenseMat<double> mat(DenseMat<double>::genRandMat(n, n + 1, low, high));
    auto cpuSolution(cpuSolver.solve(mat));
    return 0;
}