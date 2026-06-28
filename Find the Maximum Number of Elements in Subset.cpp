class Solution {
    public:
        int maximumLength(vector<int>& nums) {
            int ans = 1;
            unordered_map<int, int> mp;
            for(auto it:nums) mp[it]++;
            for(auto it:mp){
                if(it.first == 1) continue;
                int ele = it.first, cnt = 0;
                while(ele <= 31622 && mp.count(pow(ele, 2)) && mp[ele] > 1){
                    ele = pow(ele, 2);
                    cnt++;
                    ans = max(ans, 2*cnt+1);
                }
            }
            if(mp[1]%2) ans = max(ans, mp[1]);
            return max(ans, mp[1]-1);
        }
    };
    