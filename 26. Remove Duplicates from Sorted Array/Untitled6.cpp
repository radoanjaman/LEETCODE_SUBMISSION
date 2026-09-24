#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        for(int i = 0 ; i< nums.size()-1;i++)
        {
            if(nums[i] != nums[i+1])
            {
                temp.push_back(nums[i]);
            }
            else continue;
        }
        temp.push_back(nums[nums.size()-1]);
        nums = temp;
        return temp.size();
    }
};
int main()
{
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    Solution s;
    cout<<s.removeDuplicates(nums)<<endl;
    for(auto i : nums)
    {
        cout<<i<<" ";
    }
}
