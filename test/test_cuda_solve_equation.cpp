//
// Created by denis on 09.12.2021.
//

#include "simpleGauss/SimpleGaussCuda/SimpleGaussCuda.h"
#include "simpleGauss/SimpleGaussCpu.h"
#include "matrix/DenseMat.h"
#include "matrix/JsonMatIO.h"

#include "gtest/gtest.h"

class CudaSolveEquationTest: public testing::Test {
public:
    SimpleGaussCuda<float> cudaSolver;
    SimpleGaussCPU<DenseMat<float>, float> cpuSolver;
};

TEST_F(CudaSolveEquationTest, SolveEquationTest0)
{
    std::string matTestPath = "./data/equation/test_0.json";
    DenseMat<float> matTest(JsonMatIO<DenseMat<float>, float>::parseFile(matTestPath));
    std::string matAnswerPath = "./data/equation/answer_0.json";
    DenseMat<float> matAnswer(JsonMatIO<DenseMat<float>, float>::parseFile(matAnswerPath));

    DenseMat<float> matSolution(cudaSolver.solve(matTest));

    ASSERT_TRUE(DenseMat<float>::cmp(matAnswer, matSolution));
}

TEST_F(CudaSolveEquationTest, SolveEquationTest1)
{
    std::string matTestPath = "./data/equation/test_1.json";
    DenseMat<float> matTest(JsonMatIO<DenseMat<float>, float>::parseFile(matTestPath));
    std::string matAnswerPath = "./data/equation/answer_1.json";
    DenseMat<float> matAnswer(JsonMatIO<DenseMat<float>, float>::parseFile(matAnswerPath));

    DenseMat<float> matSolution(cudaSolver.solve(matTest));

    ASSERT_TRUE(DenseMat<float>::cmp(matAnswer, matSolution));
}

TEST_F(CudaSolveEquationTest, SolveEquationTest2)
{
    std::string matTestPath = "./data/equation/test_2.json";
    DenseMat<float> matTest(JsonMatIO<DenseMat<float>, float>::parseFile(matTestPath));
    std::string matAnswerPath = "./data/equation/answer_2.json";
    DenseMat<float> matAnswer(JsonMatIO<DenseMat<float>, float>::parseFile(matAnswerPath));

    DenseMat<float> matSolution(cudaSolver.solve(matTest));

    ASSERT_TRUE(DenseMat<float>::cmp(matAnswer, matSolution));
}

TEST_F(CudaSolveEquationTest, SolveEquationTest3)
{
    float low = -100;
    float high = 100;
    size_t n = 14;
    DenseMat<float> mat(DenseMat<float>::genRandMat(n, n + 1, low, high));

    auto cudaSolution(cudaSolver.solve(mat));
    auto cpuSolution(cpuSolver.solve(mat));

    ASSERT_TRUE(DenseMat<float>::cmp(cudaSolution, cpuSolution));
}

TEST_F(CudaSolveEquationTest, SolveEquationTest4)
{
    float low = -100;
    float high = 100;
    size_t n = 16;
    DenseMat<float> mat(DenseMat<float>::genRandMat(n, n + 1, low, high));

    auto cudaSolution(cudaSolver.solve(mat));
    auto cpuSolution(cpuSolver.solve(mat));

    ASSERT_TRUE(DenseMat<float>::cmp(cudaSolution, cpuSolution));
}

TEST_F(CudaSolveEquationTest, SolveEquationTest5)
{
    float low = -100;
    float high = 100;
    size_t n = 31;
    DenseMat<float> mat(DenseMat<float>::genRandMat(n, n + 1, low, high));

    auto cudaSolution(cudaSolver.solve(mat));
    auto cpuSolution(cpuSolver.solve(mat));

    ASSERT_TRUE(DenseMat<float>::cmp(cudaSolution, cpuSolution));
}

TEST_F(CudaSolveEquationTest, SolveEquationTest6)
{
    float low = -100;
    float high = 100;
    size_t n = 63;
    DenseMat<float> mat(DenseMat<float>::genRandMat(n, n + 1, low, high));

    auto cudaSolution(cudaSolver.solve(mat));
    auto cpuSolution(cpuSolver.solve(mat));

    ASSERT_TRUE(DenseMat<float>::cmp(cudaSolution, cpuSolution));
}