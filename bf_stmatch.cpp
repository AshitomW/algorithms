#include <iostream>
#include <string>
#include <vector>

using namespace std;

void bruteForceSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    // Slide the pattern over the text like a magnifying glass
    for (int i = 0; i <= n - m; i++) {
        int j;

        // Check for a match at the current position 'i'
        for (j = 0; j < m; j++) {
            // If characters don't match, give up on this spot
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        // If the inner loop finished, we found the whole pattern!
        if (j == m) {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

int main() {
    string text = "ABAAABCDBABC";
    string pattern = "ABC";

    cout << "Searching for: " << pattern << endl;
    bruteForceSearch(text, pattern);

    return 0;
}
