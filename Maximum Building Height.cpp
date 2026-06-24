class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        int maxheight = 0;
        restrictions.push_back({1, 0});
        int m = restrictions.size();
        sort(begin(restrictions), end(restrictions));
        for(int i = 1;i < m;i++){
            int bestHeight = restrictions[i-1][1] + restrictions[i][0] - restrictions[i-1][0];
            restrictions[i][1] = min(restrictions[i][1], bestHeight);
        }
        for(int i = m-2;i >= 0;i--){
            int bestHeight = restrictions[i+1][1] + restrictions[i+1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1], bestHeight);
        }
        for(int i = 1;i < m;i++){
            int temp = max(restrictions[i-1][1], restrictions[i][1]) + (restrictions[i][0]-restrictions[i-1][0] - abs(restrictions[i-1][1]-restrictions[i][1]))/2;
            maxheight = max(maxheight, temp);
        }
        int faltu = n - restrictions.back()[0] + restrictions.back()[1];
        return max(maxheight, faltu);
    }
};