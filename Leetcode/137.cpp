class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0, common = 0, num = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            num = nums[i];
            
            two |= (one&num);
            one ^= num;
            common = ~(two&one);
            two &= common;
            one &= common;
            
        }
        
        return one;
    }
};