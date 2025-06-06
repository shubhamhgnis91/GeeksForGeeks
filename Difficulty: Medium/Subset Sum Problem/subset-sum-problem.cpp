class Solution {
  public:
  
    vector<vector<int>> dp;
    int dpSS(vector<int> &arr, int sum, int n){
        if(sum==0)
            return true;
            
        if(n==0 && sum!=0)
            return false;
            
        if(dp[n][sum] != -1)
            return dp[n][sum];
        
        if(arr[n-1] <= sum){
            int add = dpSS(arr, sum - arr[n-1], n - 1);
            int notadd = dpSS(arr, sum, n - 1);
            
            return dp[n][sum] = (add || notadd);
        }
        
        return dp[n][sum] = dpSS(arr, sum, n - 1);
        
        
    }
  
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        
        dp.assign(arr.size() + 1, vector<int>(sum + 1, -1));
        
        int res = dpSS(arr, sum, arr.size());
        
        if(res == 1)
            return true;
        
        return false;
        
        
    }
};