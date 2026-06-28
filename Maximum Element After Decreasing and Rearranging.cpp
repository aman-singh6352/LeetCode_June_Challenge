class Solution {
    public:
        int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
            sort(begin(arr), end(arr));
            int cnt = 0;
            for(auto it:arr){
                if(it > cnt) cnt++;
            }
            return cnt;
        }
    };