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
    std::cout << JsonMatIO<FixedMat<int>>::stringify(fixedMat) << std::endl;
    std::string outfile("saved.json");
    JsonMatIO<FixedMat<int>>::saveMat(fixedMat, outfile);
    return 0;
}
