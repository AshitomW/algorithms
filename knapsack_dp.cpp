#include <iostream>
#include <vector>
#include <algorithm>

int knapsack(int W, const std::vector<int>& wt, const std::vector<int>& val, int n) {
    // Create a 2D DP table initialized to 0
    // dp[item_count + 1][capacity + 1]
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));

    // Building the table in a bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                // Max of (Value of current item + Value of remaining space) OR (Value without current item)
                dp[i][w] = std::max(val[i - 1] + dp[i - 1][w - wt[i - 1]], 
                                    dp[i - 1][w]);
            } else {
                // Current item is too heavy i dont carea bout it basically, carry forward previous value
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W]; // Bottom-right cell contains the answer
}

int main() {
    std::vector<int> values = {60, 100, 120};
    std::vector<int> weights = {10, 20, 30};
    int W = 50;
    int n = values.size();

    std::cout << "Maximum value in Knapsack = " << knapsack(W, weights, values, n) << std::endl;

    return 0;
}
