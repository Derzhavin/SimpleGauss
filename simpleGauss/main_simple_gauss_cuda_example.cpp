//
// Created by denis on 07.12.2021.
//

#include "matrix/DenseMat.h"
#include "matrix/JsonMatIO.h"
#include "SimpleGaussCuda/SimpleGaussCuda.h"
#include "SimpleGaussCpu.h"

int main()
{
    SimpleGaussCuda<float> solver(true);

    std::string filename("./data/equation/test_2.json");
    auto mat(JsonMatIO<DenseMat<float>, float>::parseFile(filename));

    auto matSolution(solver.solve(mat));

    std:: cout << JsonMatIO<DenseMat<float>, float>::stringify(matSolution) << std:: endl;

    return 0;
}