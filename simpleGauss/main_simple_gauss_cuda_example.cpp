//
// Created by denis on 07.12.2021.
//

#include "matrix/DenseMat.h"
#include "matrix/JsonMatIO.h"
#include "SimpleGaussCuda/SimpleGaussCuda.h"

int main()
{
    SimpleGaussCuda<double> solver(true);

    for (int i = 0; i < 5; ++i) {
        std::string filename("../../data/equation/test_0.json");
        auto mat(JsonMatIO<DenseMat<double>, double>::parseFile(filename));

        auto matSolution(solver.solve(mat));

        std:: cout << JsonMatIO<DenseMat<double>, double>::stringify(matSolution) << std:: endl;

        std::string fileSolution("solution.json");
        JsonMatIO<DenseMat<double>, double>::saveMat(matSolution, fileSolution);
    }

    return 0;
}