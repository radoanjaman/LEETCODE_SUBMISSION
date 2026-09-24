#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<climits>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if(strs.size() == 0) return " ";
         //else if(strs.size() == 1) return strs[0];

        string k = strs[0];
        string m;
        int size = INT_MAX;
        for(auto i:strs)
        {
            size = min(size , (int)i.length());
        }
        for(int j = 0; j<size; j++)
        {
            for(int i = 1 ; i < strs.size(); i++)
            {
                if(strs[i][j] != k[j])
                {
                    return m = k.substr(0,j);
                }
        }

    }
    return m = k.substr(0,size);
    }
};
int main()
{
    Solution s;
     vector<string>strs = {"a"};
    cout<<s.longestCommonPrefix(strs);

}
