class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int,int>> counter;
    vector<int>temp;
    for(int i = 1; i<=n*n;i++)
    {
        counter.push_back({i,0});
    }
    for(int i = 0;i<n;i++)
    {

        for(int j = 0; j<n ;j++)
        {
            if(grid[i][j] == counter[grid[i][j]-1].first)
            {

                counter[grid[i][j]-1].second++;
            }
        }
    }
     for(auto j : counter)
     {
         if(j.second > 1)
         {
             temp.push_back(j.first);
         }

     }
     for(auto j : counter)
     {
         if(j.second == 0)
         {
             temp.push_back(j.first);
         }

     }
     return temp;
    }
    
};