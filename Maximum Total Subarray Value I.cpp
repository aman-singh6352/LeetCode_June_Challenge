class Solution {
    public:
        long long maxTotalValue(vector<int>& nums, int k) {
            long long ans, maxe, mine;
            maxe = *max_element(nums.begin(), nums.end());
            mine = *min_element(nums.begin(), nums.end());
            return k * (maxe-mine);
        }
    };