#include "search.h"

#include "gtest/gtest.h"

namespace search = wingmann::algorithms::search;

TEST(algorithms_search, binary_search_1)
{
    // Arrange.
    std::vector data{1, 3, 5, 7, 9, 8, 6, 4, 2};

    // Act.
    std::sort(data.begin(), data.end());

    auto expected{3};
    auto actual = search::binary_search(data, 4);

    // Assert.
    EXPECT_EQ(expected, actual);
}

TEST(algorithms_search, binary_search_2)
{
    std::vector data{1, 31, 231, 12, 2, 5, 51, 21, 23, 12, 3};
    std::sort(data.begin(), data.end());

    auto expected{8};
    auto actual = search::binary_search(data, 31);

    EXPECT_EQ(expected, actual);
}

TEST(algorithms_search, binary_search_3)
{
    std::vector<int> data{};
    std::sort(data.begin(), data.end());

    auto expected = std::numeric_limits<std::size_t>::max();
    auto actual = search::binary_search(data, 1);

    EXPECT_EQ(expected, actual);
}