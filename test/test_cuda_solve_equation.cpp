//
// Created by denis on 09.12.2021.
//

#include "simpleGauss/SimpleGaussCuda/SimpleGaussCuda.h"
#include "matrix/DenseMat.h"
#include "matrix/JsonMatIO.h"

#include "gtest/gtest.h"

class CudaSolveEquationTest: public testing::Test {
public:
    SimpleGaussCuda<float> solver;
};

TEST_F(CudaSolveEquationTest, SolveEquationTest0)
{
    std::string matTestPath = "./data/equation/test_0.json";
    DenseMat<float> matTest(JsonMatIO<DenseMat<float>, float>::parseFile(matTestPath));
    std::string matAnswerPath = "./data/equation/answer_0.json";
    DenseMat<float> matAnswer(JsonMatIO<DenseMat<float>, float>::parseFile(matAnswerPath));

    DenseMat<float> matSolution(solver.solve(matTest));

    ASSERT_TRUE(DenseMat<float>::cmp(matAnswer, matSolution));
}

TEST_F(CudaSolveEquationTest, SolveEquationTest1)
{
    std::string matTestPath = "./data/equation/test_1.json";
    DenseMat<float> matTest(JsonMatIO<DenseMat<float>, float>::parseFile(matTestPath));
    std::string matAnswerPath = "./data/equation/answer_1.json";
    DenseMat<float> matAnswer(JsonMatIO<DenseMat<float>, float>::parseFile(matAnswerPath));

    DenseMat<float> matSolution(solver.solve(matTest));

    ASSERT_TRUE(DenseMat<float>::cmp(matAnswer, matSolution));
}

TEST_F(CudaSolveEquationTest, SolveEquationTest2)
{
    std::string matTestPath = "./data/equation/test_2.json";
    DenseMat<float> matTest(JsonMatIO<DenseMat<float>, float>::parseFile(matTestPath));
    std::string matAnswerPath = "./data/equation/answer_2.json";
    DenseMat<float> matAnswer(JsonMatIO<DenseMat<float>, float>::parseFile(matAnswerPath));

    DenseMat<float> matSolution(solver.solve(matTest));

    ASSERT_TRUE(DenseMat<float>::cmp(matAnswer, matSolution));
}