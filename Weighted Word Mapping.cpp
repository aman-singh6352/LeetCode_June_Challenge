class Solution {
    public:
        string mapWordWeights(vector<string>& words, vector<int>& weights) {
            string ans;
            for(auto& it:words){
                int temp = 0;
                for(auto &s:it){
                    temp += weights[s - 'a'];
                }
                ans.push_back((char)(25 - temp%26 + 'a'));
            }
            return ans;
        }
    };