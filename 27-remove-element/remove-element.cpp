void rmv(vector<int>&arr, int k )
{
    if(find(arr.begin(),arr.end(),k) == arr.end()) /*base case, i.e if not in the vector it will return a null. and as vec.end() points to null at the very last.*/
        return;
    auto it = find(arr.begin(),arr.end(),k);
    arr.erase(it);
    rmv(arr, k);
}
class Solution {
public:
    int removeElement(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        rmv(arr,k);
        return arr.size();
    }
};