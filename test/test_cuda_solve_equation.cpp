//
// Created by denis on 09.12.2021.
//

#include "simpleGauss/SimpleGaussCuda/SimpleGaussCuda.h"
#include "simpleGauss/SimpleGaussCpu.h"
#include "matrix/DenseMat.h"
#include "matrix/JsonMatIO.h"
#include "simpleGauss/solutionChecker.h"

#include "gtest/gtest.h"
class CudaSolveEquationTest: public testing::Test {
public:
    SimpleGaussCuda<double> cudaSolver;
    SimpleGaussCPU<DenseMat<double>, double> cpuSolver;
};

TEST_F(CudaSolveEquationTest, SolveEquationTest0)
{
    std::string matTestPath = "./data/equation/test_0.json";
    DenseMat<double> matTest(JsonMatIO<DenseMat<double>, double>::parseFile(matTestPath));
    std::string matAnswerPath = "./data/equation/answer_0.json";
    DenseMat<double> matAnswer(JsonMatIO<DenseMat<double>, double>::parseFile(matAnswerPath));

    DenseMat<double> cudaSolutionution(cudaSolver.solve(matTest));

    ASSERT_TRUE(DenseMat<double>::cmp(matAnswer, cudaSolutionution));
}

TEST_F(CudaSolveEquationTest, SolveEquationTest1)
{
    std::string matTestPath = "./data/equation/test_1.json";
    DenseMat<double> matTest(JsonMatIO<DenseMat<double>, double>::parseFile(matTestPath));
    std::string matAnswerPath = "./data/equation/answer_1.json";
    DenseMat<double> matAnswer(JsonMatIO<DenseMat<double>, double>::parseFile(matAnswerPath));

    DenseMat<double> cudaSolutionution(cudaSolver.solve(matTest));

    cudaSolutionution.printMatInStdin(10);

    ASSERT_TRUE(DenseMat<double>::cmp(matAnswer, cudaSolutionution));
}

TEST_F(CudaSolveEquationTest, SolveEquationTest2)
{
    std::string matTestPath = "./data/equation/test_2.json";
    DenseMat<double> matTest(JsonMatIO<DenseMat<double>, double>::parseFile(matTestPath));
    std::string matAnswerPath = "./data/equation/answer_2.json";
    DenseMat<double> matAnswer(JsonMatIO<DenseMat<double>, double>::parseFile(matAnswerPath));

    DenseMat<double> cudaSolutionution(cudaSolver.solve(matTest));
    ASSERT_TRUE(DenseMat<double>::cmp(matAnswer, cudaSolutionution));
}

TEST_F(CudaSolveEquationTest, SolveEquationTest3)
{
    double low = -50;
    double high = 50;
    size_t n = 14;
    DenseMat<double> mat(DenseMat<double>::genRandMat(n, n + 1, low, high));

    auto cudaSolution(cudaSolver.solve(mat));
    

    ASSERT_TRUE(solChecker(mat, cudaSolution));
}

TEST_F(CudaSolveEquationTest, SolveEquationTest4)
{
    double low = -50;
    double high = 50;
    size_t n = 64;
    DenseMat<double> mat(DenseMat<double>::genRandMat(n, n + 1, low, high));

    auto cudaSolution(cudaSolver.solve(mat));
    

    cudaSolution.printMatInStdin(10);
    

    ASSERT_TRUE(solChecker(mat, cudaSolution));
}

TEST_F(CudaSolveEquationTest, SolveEquationTest5)
{
    double low = -50;
    double high = 50;
    size_t n = 31;
    DenseMat<double> mat(DenseMat<double>::genRandMat(n, n + 1, low, high));

    auto cudaSolution(cudaSolver.solve(mat));
    

    cudaSolution.printMatInStdin(10);
    

    ASSERT_TRUE(solChecker(mat, cudaSolution));
}

TEST_F(CudaSolveEquationTest, SolveEquationTest6)
{
    double low = -50;
    double high = 50;
    size_t n = 63;
    DenseMat<double> mat(DenseMat<double>::genRandMat(n, n + 1, low, high));

    auto cudaSolution(cudaSolver.solve(mat));
    

    cudaSolution.printMatInStdin(10);
    

    ASSERT_TRUE(solChecker(mat, cudaSolution));
}

TEST_F(CudaSolveEquationTest, SolveEquationTest7)
{
    double low = -50;
    double high = 50;
    size_t n = 111;
    DenseMat<double> mat(DenseMat<double>::genRandMat(n, n + 1, low, high));

    auto cudaSolution(cudaSolver.solve(mat));
    

    cudaSolution.printMatInStdin(10);
    

    ASSERT_TRUE(solChecker(mat, cudaSolution));
}

TEST_F(CudaSolveEquationTest, SolveEquationTest8)
{
    double low = -50;
    double high = 50;
    size_t n = 112;
    DenseMat<double> mat(DenseMat<double>::genRandMat(n, n + 1, low, high));

    auto cudaSolution(cudaSolver.solve(mat));
    

    cudaSolution.printMatInStdin(10);
    

    ASSERT_TRUE(solChecker(mat, cudaSolution));
}

TEST_F(CudaSolveEquationTest, SolveEquationTest9)
{
    double low = -50;
    double high = 50;
    size_t n = 127;
    DenseMat<double> mat(DenseMat<double>::genRandMat(n, n + 1, low, high));

    auto cudaSolution(cudaSolver.solve(mat));
    

    cudaSolution.printMatInStdin(10);
    

    ASSERT_TRUE(solChecker(mat, cudaSolution));
}

TEST_F(CudaSolveEquationTest, SolveEquationTest10)
{
    double low = -50;
    double high = 50;
    size_t n = 244;
    DenseMat<double> mat(DenseMat<double>::genRandMat(n, n + 1, low, high));

    auto cudaSolution(cudaSolver.solve(mat));
    

    cudaSolution.printMatInStdin(10);
    

    ASSERT_TRUE(solChecker(mat, cudaSolution));
}

TEST_F(CudaSolveEquationTest, SolveEquationTest11)
{
    double low = -50;
    double high = 50;
    size_t n = 255;
    DenseMat<double> mat(DenseMat<double>::genRandMat(n, n + 1, low, high));

    auto cudaSolution(cudaSolver.solve(mat));
    

    cudaSolution.printMatInStdin(10);
    

    ASSERT_TRUE(solChecker(mat, cudaSolution));
}

TEST_F(CudaSolveEquationTest, SolveEquationTest12)
{
    double low = -50;
    double high = 50;
    size_t n = 537;
    DenseMat<double> mat(DenseMat<double>::genRandMat(n, n + 1, low, high));

    auto cudaSolution(cudaSolver.solve(mat));
    

    cudaSolution.printMatInStdin(10);
    

    ASSERT_TRUE(solChecker(mat, cudaSolution));
}

TEST_F(CudaSolveEquationTest, SolveEquationTest13)
{
    double low = -50;
    double high = 50;
    size_t n = 1023;
    DenseMat<double> mat(DenseMat<double>::genRandMat(n, n + 1, low, high));

    auto cudaSolution(cudaSolver.solve(mat));
    

    cudaSolution.printMatInStdin(10);
    

    ASSERT_TRUE(solChecker(mat, cudaSolution));
}

TEST_F(CudaSolveEquationTest, SolveEquationTest14)
{
    double low = -50;
    double high = 50;
    size_t n = 1024;
    DenseMat<double> mat(DenseMat<double>::genRandMat(n, n + 1, low, high));

    auto cudaSolution(cudaSolver.solve(mat));
    

    cudaSolution.printMatInStdin(10);
    

    ASSERT_TRUE(solChecker(mat, cudaSolution));
}

TEST_F(CudaSolveEquationTest, SolveEquationTest15)
{
    double low = -50;
    double high = 50;
    size_t n = 1025;
    DenseMat<double> mat(DenseMat<double>::genRandMat(n, n + 1, low, high));

    auto cudaSolution(cudaSolver.solve(mat));
    

    cudaSolution.printMatInStdin(10);
    

    ASSERT_TRUE(solChecker(mat, cudaSolution));
}