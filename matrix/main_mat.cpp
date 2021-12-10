//
// Created by denis on 05.12.2021.
//

#include "JsonMatIO.h"
#include "DenseMat.h"
#include <iostream>
#include <string>

int main()
{
    DenseMat<int> mat1(5, 4);
    std::string filename("./mat.json");
    auto mat = JsonMatIO<DenseMat<double>, double>::parseFile(filename);
    mat.printMatInStdin(10);
    mat[1][0] = 2;
    DenseMat<double>::BaseMat& basicMat = mat;
    auto matClone(mat);
    std::cout << JsonMatIO<DenseMat<double>, double>::stringify(matClone) << std::endl;
    auto row = mat.row(0);
    std::cout << row[0] << std::endl;
    return 0;
}
