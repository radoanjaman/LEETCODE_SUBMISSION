class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
    int i = m-1; //a
    int j = n-1; //b
    int idx = m+n -1; //a
    while(i>=0 && j>=0)
    {
        if(A[i] >= B[j])
        {
            A[idx] = A[i];
            idx--;
            i--;
        }
        else 
        {
            A[idx] = B[j];
            idx--;
            j--;
        }

    }
    while(j>=0)
        {
           A[idx] = B[j];
            idx--;
            j--;
        }
    
    
    
    }
};