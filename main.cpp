#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n + 2);
    a[0] = 1;  // Virtual card at position 0
    a[n + 1] = 1;  // Virtual card at position n+1

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // dp[i][j] = maximum value when burning all cards in interval [i, j]
    vector<vector<long long>> dp(n + 2, vector<long long>(n + 2, 0));

    // len is the length of the interval
    for (int len = 1; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;

            // Try burning each card k in interval [i, j] as the last card to burn
            for (int k = i; k <= j; k++) {
                long long value = 0;

                // If k is the last card to burn in [i, j]
                // All cards in [i, k-1] and [k+1, j] are already burned
                // The cards adjacent to k are at positions i-1 and j+1
                value = dp[i][k-1] + dp[k+1][j] + a[i-1] * a[k] * a[j+1];

                dp[i][j] = max(dp[i][j], value);
            }
        }
    }

    cout << dp[1][n] << endl;

    return 0;
}
