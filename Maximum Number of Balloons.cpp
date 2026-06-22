class Solution {
    public:
        int maxNumberOfBalloons(string text) {
            int minchar = INT_MAX;
            unordered_map<char, int> mp;
            for(auto &it:text){
                if(it == 'b')  mp[it]++;
                else if(it == 'a') mp[it]++;
                else if(it == 'l') mp[it]++;
                else if(it == 'o') mp[it]++;
                else if(it == 'n') mp[it]++;
            }
            minchar = min(minchar, mp['b']);
            minchar = min(minchar, mp['a']);
            minchar = min(minchar, mp['n']);
            minchar = min(minchar, mp['l']/2);
            minchar = min(minchar, mp['o']/2);
            return minchar;
        }
    };