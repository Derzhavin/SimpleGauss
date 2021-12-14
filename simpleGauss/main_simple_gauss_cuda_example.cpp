//
// Created by denis on 07.12.2021.
//

#include "matrix/DenseMat.h"
#include "matrix/JsonMatIO.h"
#include "SimpleGaussCuda/SimpleGaussCuda.h"
#include "SimpleGaussCpu.h"

int main()
{
    SimpleGaussCuda<double> solver(true);

    std::string filename("./data/equation/test_1.json");
    auto mat(JsonMatIO<DenseMat<double>, double>::parseFile(filename));

    auto matSolution(solver.solve(mat));

    std:: cout << JsonMatIO<DenseMat<double>, double>::stringify(matSolution) << std:: endl;

    return 0;
}