//
// Created by denis on 06.12.2021.
//

#include "ISimpleGauss.h"
#include "SimpleGaussCpu.h"
#include "matrix/FixedMat.h"
#include "matrix/JsonMatIO.h"

#include <string>

int main()
{
    std::string filename("../../mat.json");
    auto mat = JsonMatIO<FixedMat<double>>::parseFile(filename);

    SimpleGaussCPU<FixedMat<double>> solver;
    auto matSolution(solver.solve(mat));

    std::string fileSolution("solution.json");
    JsonMatIO<FixedMat<double>>::saveMat(matSolution, fileSolution);
    return 0;
}
