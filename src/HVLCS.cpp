#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
using namespace std;

int main() {
    int K;
    cin >> K;

    unordered_map<char, int> val;
    for (int i = 0; i < K; i++) {
        char ch;
        int v;
        cin >> ch >> v;
        val[ch] = v;
    }

    string A, B;
    cin >> A >> B;

    auto start = chrono::high_resolution_clock::now();

    int n = A.size(), m = B.size();

    // dp[i][j] = max value of common subsequence of A[0..i-1] and B[0..j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i-1] == B[j-1]) {
                // Characters match: take it (add its value) or skip
                int charVal = val.count(A[i-1]) ? val[A[i-1]] : 0;
                dp[i][j] = max(dp[i-1][j-1] + charVal, max(dp[i-1][j], dp[i][j-1]));
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    string result = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (A[i-1] == B[j-1]) {
            int charVal = val.count(A[i-1]) ? val[A[i-1]] : 0;
            if (dp[i][j] == dp[i-1][j-1] + charVal) {
                result = A[i-1] + result;
                i--; j--;
            } else if (dp[i-1][j] >= dp[i][j-1]) {
                i--;
            } else {
                j--;
            }
        } else if (dp[i-1][j] >= dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed = end - start;

    cout << dp[n][m] << "\n";
    cout << result << "\n";
    //cout << "Time: " << elapsed.count() << " ms\n";

    return 0;
}