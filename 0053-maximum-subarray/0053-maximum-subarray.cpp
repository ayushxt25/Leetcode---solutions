class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int best = INT_MIN;

        for(int x : nums){
            sum += x;
            best = max(best, sum);

            if(sum < 0){
                sum = 0;
            }
        }
        return best;
    }
};