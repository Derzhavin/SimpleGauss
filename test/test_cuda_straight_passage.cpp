//
// Created by denis on 09.12.2021.
//

#include "simpleGauss/SimpleGaussCuda/SimpleGaussCuda.h"
#include "matrix/DenseMat.h"
#include "matrix/JsonMatIO.h"

#include "gtest/gtest.h"

class CudaStraightPassageTest: public testing::Test {

    void SetUp( ) override {
    }

    void TearDown( ) override {
    }

public:
    SimpleGaussCuda<DenseMat<double>, double> solver;
};

TEST_F(CudaStraightPassageTest, StraightPassageTest0)
{
    std::string matTestPath = "../../data/straight_passage/test_0.json";
    DenseMat<double> matTest(JsonMatIO<DenseMat<double>, double>::parseFile(matTestPath));
    std::string matAnswerPath = "../../data/straight_passage/answer_0.json";
    DenseMat<double> matAnswer(JsonMatIO<DenseMat<double>, double>::parseFile(matAnswerPath));

    DenseMat<double> matSolution(solver.solve(matTest));

    ASSERT_EQ(&matAnswer, &matSolution);
}

TEST_F(CudaStraightPassageTest, StraightPassageTest1)
{
    std::string matTestPath = "../../data/straight_passage/test_1.json";
    DenseMat<double> matTest(JsonMatIO<DenseMat<double>, double>::parseFile(matTestPath));
    std::string matAnswerPath = "../../data/straight_passage/answer_1.json";
    DenseMat<double> matAnswer(JsonMatIO<DenseMat<double>, double>::parseFile(matAnswerPath));

    DenseMat<double> matSolution(solver.solve(matTest));

    ASSERT_EQ(&matAnswer, &matSolution);
}