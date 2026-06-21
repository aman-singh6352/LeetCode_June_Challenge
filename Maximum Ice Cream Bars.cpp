class Solution {
    public:
        int maxIceCream(vector<int>& costs, int coins) {
            int maxelement = *max_element(begin(costs), end(costs));
            int n = costs.size(), sum = 0, cnt = 0;
            vector<int> arr(maxelement+1, 0), ans(n);
            for(auto &it:costs){
                arr[it]++;
            }
            // prefix sum
            for(int i = 2;i < arr.size();i++){
                arr[i] += arr[i-1];
            }
            for(int i = 0;i < costs.size();i++){
                ans[arr[costs[i]]-1] = costs[i];
                arr[costs[i]]--;
            }
            for(int i = 0;i < n;i++){
                sum += ans[i];
                if(sum > coins) break;
                else cnt++;
            }
            return cnt;
        }
    };