/*
An autonomous driving vehicle is driving along a one way street and picking up passengers. Along the street,
there are N locations, and the distance between neighboring locations is 1. At each location, there can be 0
or 1 passenger waiting for pickup. The autonomous driving vehicle can choose to pick up the passenger at a
location and drop off at the passenger’s destination, or pass by the location without picking up the
passenger.

The street is represented as an array of non-negative integers. 0 means there are no passengers at the
location; a positive integer represents the distance from the current location to the passenger’s
destination. If picked up, the passenger will pay $1.0 + $0.50 * travel_distance. The autonomous driving
vehicle starts from the beginning of the array. When the destination is within the range of the array, the
autonomous driving vehicle can pick up another passenger at the same location. When the destination is out of
the range of the array, the passenger will be dropped off beyond the street and we will get the full payment.

Question: No ride sharing is allowed. Find the maximum payment that the autonomous driving vehicle can get.
Please use the algorithm with the best run time complexity possible.

example
Input : [0, 2]
Output : 2.0

*/

#include <iostream>
#include <vector>

float solve(const std::vector<int>& input) {
    // dp[i] means the max payment at or before i-th location. Ready to 
    // pick up a new passenger at i.
    // dp[input.size()]: Last passenger whose destination is out of range.
    std::vector<float> dp(input.size() + 1, 0.f);

    float maxPayment = 0.f;
    for (int i = 0; i < input.size(); ++i) {
        dp[i] = i == 0 ? 0.f : std::max(dp[i], dp[i - 1]);
        if (input[i] == 0) {
            continue;
        }
        const int dest = std::min(i + input[i], (int)input.size());
        const float payment = 1.f + 0.5f * input[i];
        dp[dest] = std::max(dp[dest], dp[i] + payment);
        maxPayment = std::max(maxPayment, dp[i]);
    }
    // For the last passenger that is out of range
    // maxPayment = std::max(maxPayment, dp.back());
    maxPayment = std::max(dp[input.size()], dp[input.size()-1]);
    return maxPayment;
}

int main()
{
    {
        std::vector<int> input = {
            0, 2
        };
        // 1 + 2 * 0.5 = 2
        std::cout << "Expect: 2.0, Result: " << solve(input) << std::endl;
    }
    {
        std::vector<int> input = {
            5
        };
        // 1 + 5 * 0.5 = 3.5
        std::cout << "Expect: 3.5, Result: " << solve(input) << std::endl;
    }
    {
        std::vector<int> input = {
            1, 3, 4, 5
        };
        // (1 + 1 * 0.5) + (1 + 5 * 0.5) = 5
        std::cout << "Expect: 5, Result: " << solve(input) << std::endl;
    }
    {
        std::vector<int> input = {
            6, 1, 1, 1
        };
        // (1 + 1 * 0.5) * 3 = 4.5
        std::cout << "Expect: 4.5, Result: " << solve(input) << std::endl;
    }
    {
        std::vector<int> input = {
            8, 1, 1, 1
        };
        // 1 + 8 * 0.5 = 5
        std::cout << "Expect: 5, Result: " << solve(input) << std::endl;
    }
}