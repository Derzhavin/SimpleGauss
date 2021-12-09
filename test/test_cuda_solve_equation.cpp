//
// Created by denis on 09.12.2021.
//

#include "simpleGauss/SimpleGaussCuda/SimpleGaussCuda.h"
#include "matrix/DenseMat.h"
#include "matrix/JsonMatIO.h"

#include "gtest/gtest.h"

class CudaSolveEquationTest: public testing::Test {
public:
    SimpleGaussCuda<DenseMat<double>, double> solver;
};

TEST_F(CudaSolveEquationTest, SolveEquationTest0)
{
    std::string matTestPath = "../../../data/straight_passage/test_0.json";
    DenseMat<double> matTest(JsonMatIO<DenseMat<double>, double>::parseFile(matTestPath));
    std::string matAnswerPath = "../../../data/straight_passage/answer_0.json";
    DenseMat<double> matAnswer(JsonMatIO<DenseMat<double>, double>::parseFile(matAnswerPath));

    DenseMat<double> matSolution(solver.solve(matTest));

    ASSERT_EQ(matAnswer, matSolution);
}

TEST_F(CudaSolveEquationTest, SolveEquationTest1)
{
    std::string matTestPath = "../../../data/equation/test_1.json";
    DenseMat<double> matTest(JsonMatIO<DenseMat<double>, double>::parseFile(matTestPath));
    std::string matAnswerPath = "../../../data/equation/answer_1.json";
    DenseMat<double> matAnswer(JsonMatIO<DenseMat<double>, double>::parseFile(matAnswerPath));

    DenseMat<double> matSolution(solver.solve(matTest));

    ASSERT_EQ(matAnswer, matSolution);
}