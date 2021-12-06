//
// Created by denis on 05.12.2021.
//

#include "JsonMatIO.h"
#include "DenseMat.h"
#include <iostream>
#include <string>

int main()
{
    DenseMat<double> mat(5, 4);
    auto matClone(mat);
    std::cout << JsonMatIO<DenseMat<double>, double>::stringify(matClone) << std::endl;
    auto row = mat.IMat<DenseMat<double>,double>::row(0);
    std::cout << row[0] << std::endl;
    return 0;
}
