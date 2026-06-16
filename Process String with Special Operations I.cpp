class Solution {
    public:
        string processStr(string s) {
            string ans;
            for(auto &it:s){
                if(it == '*') {
                    if(ans.size()) 
                        ans.pop_back();
                }
                else if(it == '#') ans += ans;
                else if(it == '%') reverse(begin(ans), end(ans));
                else ans.push_back(it);
            }
            return ans;
        }
    };