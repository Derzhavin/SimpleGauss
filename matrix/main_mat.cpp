//
// Created by denis on 05.12.2021.
//

#include "JsonMatIO.h"
#include "FixedMat.h"
#include <iostream>
#include <string>

int main()
{
    std::string filename("../../mat.json");
    auto fixedMat = JsonMatIO<FixedMat<int>>::parseFile(filename);

    fixedMat[0][2] = 12;
    auto matClone(fixedMat);

    std::cout << JsonMatIO<FixedMat<int>>::stringify(matClone) << std::endl;
    std::string outfile("saved.json");
    JsonMatIO<FixedMat<int>>::saveMat(matClone, outfile);
    return 0;
}
