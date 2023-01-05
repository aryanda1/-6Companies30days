class Solution {
    //Similar to longest increasing subsequence
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int dp[1000]={0};
        int child[1001]={0};//used to keep track of child of node from which max subset came from
        for(int i = nums.size()-1;i>=0;i--){
            int idx = i;//used to keep track of idx with longest subset size
            int maxx = 0;//used to keep track of max (dp[i+1],..,dp[n-1]) which divided nums[i]
            for(int j = i+1;j<nums.size();j++){
                if(nums[j]%nums[i]==0)
                    if(maxx<dp[j]){
                        maxx = dp[j];
                        idx = j;
                    }
            }
            dp[i] = 1+maxx;
            child[i] = idx;
        }
        auto idx = max_element(dp,dp+nums.size()) - dp;
        vector<int>ans = {nums[idx]};
        while(child[idx]!=idx){
            idx = child[idx];
            ans.push_back(nums[idx]);
        }
        return ans;
    }
};