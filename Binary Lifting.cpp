// write code for it
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxJumps(vector<int>& arr, int d) {
            int n = arr.size();
            vector<int> dp(n, 1);
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j <= min(i + d, n - 1); j++) {
                    if (arr[i] > arr[j]) {
                        dp[i] = max(dp[i], 1 + dp[j]);
                    } else {
                        break;
                    }
                }
                for (int j = i - 1; j >= max(i - d, 0); j--) {
                    if (arr[i] > arr[j]) {
                        dp[i] = max(dp[i], 1 + dp[j]);
                    } else {
                        break;
                    }
                }
            }
            return *max_element(dp.begin(), dp.end());
        }
    };

int main() {
    Solution sol;
    vector<int> arr = {6, 4, 14, 6, 8, 13, 9, 7, 10, 6, 12};
    int d = 2;
    cout << sol.maxJumps(arr, d) << endl;
    return 0;
}
