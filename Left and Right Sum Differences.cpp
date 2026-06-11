class Solution {
    public:
        vector<int> leftRightDifference(vector<int>& nums) {
            vector<int> ans(nums.size());
            ans[0] = 0;
            for(int i = 1;i < nums.size();i++){
                ans[i] = ans[i-1] + nums[i-1];
            }
            int suffixsum = 0;
            for(int i = nums.size()-1;i >= 0;i--){
                ans[i] = abs(ans[i]-suffixsum);
                suffixsum += nums[i];
            }
            return ans;
        }
    };