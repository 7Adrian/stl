#include <vector>

#include "arithmeticAverage.hpp"
#include "gtest/gtest.h"

constexpr double epsilon = 0.001;

TEST(arithmeticAverageTest, ShouldCalculateArithmeticAverage) {
    std::vector<int> first{-5, 4, 2, -5, 2, 4, 6, 7};
    std::vector<int> second{3, 5, -2, 6, 7, -3, 6, 9};
    EXPECT_NEAR(ArithmeticAverage(first, second), 2.875, epsilon);

    first = {};
    second = {};
    double expected = 0.0;
    EXPECT_NEAR(ArithmeticAverage(first, second), expected, epsilon);

    first = {1};
    second = {5};
    expected = 3.0;
    EXPECT_NEAR(ArithmeticAverage(first, second), expected, epsilon);

    first = {1, 3};
    second = {5, 3};
    expected = 3.0;
    EXPECT_NEAR(ArithmeticAverage(first, second), expected, epsilon);

    first = {1, 3, -6};
    second = {5, 3, -6};
    expected = 0.0;
    EXPECT_NEAR(ArithmeticAverage(first, second), expected, epsilon);

    first = {1, 3, -6, 10, 5, -7};
    second = {5, 3, -6};
    expected = 0.888;
    EXPECT_NEAR(ArithmeticAverage(first, second), expected, epsilon);
}

TEST(arithmeticAverageTest, ShouldCalculateDistance) {
    std::vector<int> first{7, 4, 3};
    std::vector<int> second{17, 6, 2};
    double expected = 10.247;
    EXPECT_NEAR(Distance(first, second), expected, epsilon);

    first = {7, 4, 3, 13};
    second = {17, 6, 2, -2};
    expected = 18.16590212458495;
    EXPECT_NEAR(Distance(first, second), expected, 0.00001);

    first = {};
    second = {};
    expected = 0.0;
    EXPECT_NEAR(Distance(first, second), expected, epsilon);

    first = {5};
    second = {3};
    expected = 2.0;
    EXPECT_NEAR(Distance(first, second), expected, epsilon);

    first = {5};
    second = {5};
    expected = 0.0;
    EXPECT_NEAR(Distance(first, second), expected, epsilon);

    first = {4, 5};
    second = {1, 1};
    expected = 5.0;
    EXPECT_NEAR(Distance(first, second), expected, epsilon);
}
