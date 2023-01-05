class Solution {
    vector<vector<int>>ans;
    void backtr(vector<int>&path,int kRem,int nRem,int lastDig){
        if(kRem==0){
            if(nRem==0)
                ans.push_back(path);
            return;
        }
        if(nRem<0) return;
        for(int i = lastDig+1;i<10 && nRem-i>=0;i++){
                path.push_back(i);
                backtr(path,kRem-1,nRem-i,i);
                path.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear();
        vector<int>path;
        backtr(path,k,n,0);
        return ans;
    }
};