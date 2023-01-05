class Solution {
    // [4,3,2,6]
    // sum = 15 -> all element sum
    // temp = f(0) = 25
    // For f1, temp = temp - 6*(nums.length()-1) + (sum-6)
    // for f2, temp = temp - 2 *(nums.length()-1) + (sum-2)
    // for f3, temp = temp - 3*(nums.length()-1) + (sum-3)
public:
    int maxRotateFunction(vector<int>& nums) {
        int temp = 0,sum = 0;
        int idx = 0;
        for(auto &it:nums){
            sum+=it;
            temp += it*idx++;
        }
        int res = temp;
        while(idx){
            temp += sum-nums[--idx]*(nums.size());
            res = max(res,temp);
        }
        return res;
    }
};