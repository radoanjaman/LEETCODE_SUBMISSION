class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> prev(nums.size(), -1), length(nums.size() , 1);
        for(int i = 0;i<nums.size() ; i++)
        {
            for(int j = 0; j<i;j++)
            {
                if(nums[i] > nums[j] && length[i]<= length[j])
                {
                    length[i] = 1 + length[j];
                    prev[i] = j;
                }
            }
        }
        int max_idx = max_element(length.begin(),length.end())-length.begin();
        int max_value = length[max_idx];
        return max_value;
    }
};