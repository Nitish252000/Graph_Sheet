class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n,0);
        for(auto i:edges){
            indegree[i[1]]++;
        }
        int chmpcnt =0;
        int chmp=-1;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                chmpcnt++;
                chmp=i;
            }
        }
        if(chmpcnt>1)return -1;
        else
        return chmp;
    }
};
