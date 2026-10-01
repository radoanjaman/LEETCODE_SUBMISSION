class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int missing = -1;
        int repeated = -1;
        vector<pair<int,int>> counter;
    
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
             repeated = j.first;
         }
         else if(j.second == 0)
         {
            missing= j.first;
         }

     }
     return {repeated, missing};
    }
    
};