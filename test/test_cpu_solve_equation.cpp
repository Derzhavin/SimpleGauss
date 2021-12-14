//
// Created by denis on 09.12.2021.
//

#include "simpleGauss/SimpleGaussCpu.h"
#include "simpleGauss/solutionChecker.h"
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

TEST_F(SimpleCPUSolveEquationTest, SolveEquationTest3)
{
    float low = -50;
    float high = 50;
    size_t n = 14;
    DenseMat<float> mat(DenseMat<float>::genRandMat(n, n + 1, low, high));

    
    auto cpuSolution(solver.solve(mat));

    ASSERT_TRUE(solChecker(mat, cpuSolution));
}

TEST_F(SimpleCPUSolveEquationTest, SolveEquationTest4)
{
    float low = -50;
    float high = 50;
    size_t n = 64;
    DenseMat<float> mat(DenseMat<float>::genRandMat(n, n + 1, low, high));

    
    auto cpuSolution(solver.solve(mat));

    
    cpuSolution.printMatInStdin(10);

    ASSERT_TRUE(solChecker(mat, cpuSolution));
}

TEST_F(SimpleCPUSolveEquationTest, SolveEquationTest5)
{
    float low = -50;
    float high = 50;
    size_t n = 31;
    DenseMat<float> mat(DenseMat<float>::genRandMat(n, n + 1, low, high));

    
    auto cpuSolution(solver.solve(mat));

    
    cpuSolution.printMatInStdin(10);

    ASSERT_TRUE(solChecker(mat, cpuSolution));
}

TEST_F(SimpleCPUSolveEquationTest, SolveEquationTest6)
{
    float low = -50;
    float high = 50;
    size_t n = 63;
    DenseMat<float> mat(DenseMat<float>::genRandMat(n, n + 1, low, high));

    
    auto cpuSolution(solver.solve(mat));

    
    cpuSolution.printMatInStdin(10);

    ASSERT_TRUE(solChecker(mat, cpuSolution));
}

TEST_F(SimpleCPUSolveEquationTest, SolveEquationTest7)
{
    float low = -50;
    float high = 50;
    size_t n = 111;
    DenseMat<float> mat(DenseMat<float>::genRandMat(n, n + 1, low, high));

    
    auto cpuSolution(solver.solve(mat));

    
    cpuSolution.printMatInStdin(10);

    ASSERT_TRUE(solChecker(mat, cpuSolution));
}

TEST_F(SimpleCPUSolveEquationTest, SolveEquationTest8)
{
    float low = -50;
    float high = 50;
    size_t n = 112;
    DenseMat<float> mat(DenseMat<float>::genRandMat(n, n + 1, low, high));

    
    auto cpuSolution(solver.solve(mat));

    
    cpuSolution.printMatInStdin(10);

    ASSERT_TRUE(solChecker(mat, cpuSolution));
}

TEST_F(SimpleCPUSolveEquationTest, SolveEquationTest9)
{
    float low = -50;
    float high = 50;
    size_t n = 127;
    DenseMat<float> mat(DenseMat<float>::genRandMat(n, n + 1, low, high));

    
    auto cpuSolution(solver.solve(mat));

    
    cpuSolution.printMatInStdin(10);

    ASSERT_TRUE(solChecker(mat, cpuSolution));
}

TEST_F(SimpleCPUSolveEquationTest, SolveEquationTest10)
{
    float low = -50;
    float high = 50;
    size_t n = 244;
    DenseMat<float> mat(DenseMat<float>::genRandMat(n, n + 1, low, high));

    
    auto cpuSolution(solver.solve(mat));

    
    cpuSolution.printMatInStdin(10);

    ASSERT_TRUE(solChecker(mat, cpuSolution));
}

TEST_F(SimpleCPUSolveEquationTest, SolveEquationTest11)
{
    float low = -50;
    float high = 50;
    size_t n = 255;
    DenseMat<float> mat(DenseMat<float>::genRandMat(n, n + 1, low, high));

    
    auto cpuSolution(solver.solve(mat));

    
    cpuSolution.printMatInStdin(10);

    ASSERT_TRUE(solChecker(mat, cpuSolution));
}

TEST_F(SimpleCPUSolveEquationTest, SolveEquationTest12)
{
    float low = -50;
    float high = 50;
    size_t n = 537;
    DenseMat<float> mat(DenseMat<float>::genRandMat(n, n + 1, low, high));

    
    auto cpuSolution(solver.solve(mat));

    
    cpuSolution.printMatInStdin(10);

    ASSERT_TRUE(solChecker(mat, cpuSolution));
}

TEST_F(SimpleCPUSolveEquationTest, SolveEquationTest13)
{
    float low = -50;
    float high = 50;
    size_t n = 1023;
    DenseMat<float> mat(DenseMat<float>::genRandMat(n, n + 1, low, high));

    
    auto cpuSolution(solver.solve(mat));

    
    cpuSolution.printMatInStdin(10);

    ASSERT_TRUE(solChecker(mat, cpuSolution));
}

TEST_F(SimpleCPUSolveEquationTest, SolveEquationTest14)
{
    float low = -50;
    float high = 50;
    size_t n = 1024;
    DenseMat<float> mat(DenseMat<float>::genRandMat(n, n + 1, low, high));

    
    auto cpuSolution(solver.solve(mat));

    
    cpuSolution.printMatInStdin(10);

    ASSERT_TRUE(solChecker(mat, cpuSolution));
}

TEST_F(SimpleCPUSolveEquationTest, SolveEquationTest15)
{
    float low = -50;
    float high = 50;
    size_t n = 1025;
    DenseMat<float> mat(DenseMat<float>::genRandMat(n, n + 1, low, high));

    
    auto cpuSolution(solver.solve(mat));

    
    cpuSolution.printMatInStdin(10);

    ASSERT_TRUE(solChecker(mat, cpuSolution));
}