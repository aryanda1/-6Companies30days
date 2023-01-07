class Solution {
public:
    bool canFinish(int numC, vector<vector<int>>& preReq) {
        int indeg[2000]={0};
        vector<int>adj[2000];
        for(auto &it:preReq){
            indeg[it[0]]++;
            adj[it[1]].push_back(it[0]);
        }
        
        queue<int>q;
        
        for(int i = 0;i<numC;i++)
            if(indeg[i]==0)
                q.push(i);
        
        while(q.size()){
            auto top = q.front();q.pop();
            numC--;
            for(auto &child:adj[top]){
                if(--indeg[child]==0)
                    q.push(child);
            }
        }
        return numC==0;
    }
};