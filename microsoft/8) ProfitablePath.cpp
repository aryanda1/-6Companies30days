class Solution {
    
    int time[100000]={0};
    vector<int>adj[100000];
    //First finding timestamp of closest path of bob
    bool bobdfs(int bobPos,int par,int t){
        time[bobPos] = t;
        if(bobPos==0) return 1;
        for(auto &child:adj[bobPos]){
            if(child!=par)
                if(bobdfs(child,bobPos,t+1))
                    return 1;
        }
        time[bobPos] = INT_MAX;
        return 0;
    }
    //Than traversing whole graph to find max income for alice
    int ans;
    void dfs(int pos,vector<int>&amt,int t,int par,int sum){
        if(adj[pos].size()==1 && adj[pos][0]==par){//Leaf node
            ans = max(ans,sum);
            return;
        }
        
        for(auto &child:adj[pos]){
            if(child!=par){
                dfs(child,amt,t+1,pos,sum+(time[child]<t?0:(time[child]==t?amt[child]/2:amt[child])));
            }
        }
    }
    
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        for(auto &edg:edges){
            adj[edg[0]].push_back(edg[1]);
            adj[edg[1]].push_back(edg[0]);
        }
        for(int i = 0;i<=edges.size();i++) time[i] = INT_MAX;
        bobdfs(bob,-1,0);

        ans = INT_MIN;
        dfs(0,amount,1,-1,0==bob?amount[0]/2:amount[0]);
        return ans;
    }
};