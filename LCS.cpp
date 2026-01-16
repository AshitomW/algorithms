#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Global or passed memo table
// Using -1 to indicate that the subproblem need to be solved !!!!
std::vector<std::vector<int>> memo;

int lcsMemo(const std::string& s1, const std::string& s2, int m, int n) {
    // Base Case: If either string have been exhausted?
    if (m == 0 || n == 0) {
        return 0;
    }

    // Value is already computer?
    if (memo[m][n] != -1) {
        return memo[m][n];
    }

    // Do characters match?
    if (s1[m - 1] == s2[n - 1]) {
        memo[m][n] = 1 + lcsMemo(s1, s2, m - 1, n - 1);
    } 
    // If characters do not match
    else {
        memo[m][n] = std::max(lcsMemo(s1, s2, m, n - 1), 
                              lcsMemo(s1, s2, m - 1, n));
    }

    return memo[m][n];
}

int main() {
    std::string s1 = "AGGTAB";
    std::string s2 = "GXTXAYB";
    int m = s1.length();
    int n = s2.length();

    // Initialize memo table with -1
    memo.assign(m + 1, std::vector<int>(n + 1, -1));

    std::cout << "Length of LCS is " << lcsMemo(s1, s2, m, n) << std::endl;

    return 0;
}
