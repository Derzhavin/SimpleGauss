//
// Created by denis on 05.12.2021.
//

#ifndef SIMPLEGAUSS_JSONMATIO_H
#define SIMPLEGAUSS_JSONMATIO_H

#include "IMat.h"

#include <fstream>
#include <nlohmann/json.hpp>

template<class MatImpl>
class JsonMatIO {
public:
    static MatImpl parseJSON(nlohmann::json& jsonObj)
    {
        size_t rowsSize = jsonObj["rowsSize"];
        size_t colsSize = jsonObj["colsSize"];
        nlohmann::json matJf = jsonObj["matrix"];

        MatImpl mat(rowsSize, colsSize);

        for (size_t i = 0, j; i < rowsSize; ++i)
            for (j = 0; j < colsSize; ++j)
                mat[i][j] = matJf[i][j];

        return std::move(mat);
    }

    static nlohmann::json loadJSON(MatImpl& mat)
    {
        nlohmann::json jsonObj;

        jsonObj["rowsSize"] = mat.rowsSize();
        jsonObj["colsSize"] = mat.colsSize();

        nlohmann::json jRows = nlohmann::json::array();;
        for (size_t i = 0, j; i < mat.rowsSize(); ++i)
        {
            nlohmann::json jCols = nlohmann::json::array();
            for (j = 0; j < mat.colsSize(); ++j)
                jCols.push_back(mat[i][j]);
            jRows.push_back(jCols);
        }
        jsonObj["matrix"] = jRows;
        return std::move(jsonObj);
    }


    static MatImpl parseStr(std::string& str)
    {
        nlohmann::json js = nlohmann::json::parse(str);
        return std::move(parseJSON(js));
    }

    static MatImpl parseFile(std::string& filename)
    {
        std::ifstream ifs(filename);
        nlohmann::json jf = nlohmann::json::parse(ifs);
        MatImpl mat = parseJSON(jf);
        return std::move(mat);
    }

    static std::string stringify(MatImpl& mat)
    {
        return std::move(loadJSON(mat).dump());
    }
    static void saveMat(MatImpl& mat, std::string& filename)
    {
        std::ofstream file(filename);
        file << loadJSON(mat);
    }
};


#endif //SIMPLEGAUSS_JSONMATIO_H
