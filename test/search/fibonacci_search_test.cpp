#include "search.h"
#include "search_test_helpers.h"

#include "gtest/gtest.h"

using namespace wingmann::algorithms::search;

TEST(fibonacci_search, empty)
{
    EXPECT_EQ(std::nullopt, fibonacci_search(std::vector<int>{}, 1));
}

TEST(fibonacci_search, one_value)
{
    EXPECT_EQ(0, fibonacci_search(std::vector<int>{64}, 64).value());
}

TEST(fibonacci_search, several_values)
{
    std::vector<int> data;
    int target;
    int searched_target;

    for (std::size_t i = 0; i < 100; i++) {
        data = get_sorted_vector_with_random_values<int>();
        target = get_value<int>(data);
        searched_target = data[fibonacci_search(data, target).value()];

        EXPECT_EQ(target, searched_target);
    }
}
