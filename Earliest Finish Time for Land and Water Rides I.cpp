class Solution {
    public:
        int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
            int ans = INT_MAX;
            for(int i = 0;i < landStartTime.size();i++){
                int timetaken = landStartTime[i] + landDuration[i];
                for(int j = 0;j < waterStartTime.size();j++){
                    int nexttime = timetaken;
                    if(waterStartTime[j] > timetaken) nexttime = waterStartTime[j];
                    nexttime += waterDuration[j];
                    ans = min(ans, nexttime);
                }
            }
            for(int i = 0;i < waterStartTime.size();i++){
                int timetaken = waterStartTime[i] + waterDuration[i];
                for(int j = 0;j < landStartTime.size();j++){
                    int nexttime = timetaken;
                    if(landStartTime[j] > timetaken) nexttime = landStartTime[j];
                    nexttime += landDuration[j];
                    ans = min(ans, nexttime);
                }
            }
            return ans;
        }
    };