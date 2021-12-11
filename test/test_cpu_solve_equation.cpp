//
// Created by denis on 09.12.2021.
//

#include "simpleGauss/SimpleGaussCpu.h"
#include "matrix/DenseMat.h"
#include "matrix/JsonMatIO.h"

#include "gtest/gtest.h"

class SimpleCPUSolveEquationTest: public testing::Test {
public:
    SimpleGaussCPU<DenseMat<float>, float> solver;
};

TEST_F(SimpleCPUSolveEquationTest, SolveEquationTest0)
{
    std::string matTestPath = "./data/equation/test_0.json";
    DenseMat<float> matTest(JsonMatIO<DenseMat<float>, float>::parseFile(matTestPath));
    std::string matAnswerPath = "./data/equation/answer_0.json";
    DenseMat<float> matAnswer(JsonMatIO<DenseMat<float>, float>::parseFile(matAnswerPath));

    DenseMat<float> matSolution(solver.solve(matTest));

    ASSERT_TRUE(DenseMat<float>::cmp(matAnswer, matSolution));
}

TEST_F(SimpleCPUSolveEquationTest, SolveEquationTest1)
{
    std::string matTestPath = "./data/equation/test_1.json";
    DenseMat<float> matTest(JsonMatIO<DenseMat<float>, float>::parseFile(matTestPath));
    std::string matAnswerPath = "./data/equation/answer_1.json";
    DenseMat<float> matAnswer(JsonMatIO<DenseMat<float>, float>::parseFile(matAnswerPath));

    DenseMat<float> matSolution(solver.solve(matTest));

    ASSERT_TRUE(DenseMat<float>::cmp(matAnswer, matSolution));
}

TEST_F(SimpleCPUSolveEquationTest, SolveEquationTest2)
{
    std::string matTestPath = "./data/equation/test_2.json";
    DenseMat<float> matTest(JsonMatIO<DenseMat<float>, float>::parseFile(matTestPath));
    std::string matAnswerPath = "./data/equation/answer_2.json";
    DenseMat<float> matAnswer(JsonMatIO<DenseMat<float>, float>::parseFile(matAnswerPath));

    DenseMat<float> matSolution(solver.solve(matTest));

    ASSERT_TRUE(DenseMat<float>::cmp(matAnswer, matSolution));
}