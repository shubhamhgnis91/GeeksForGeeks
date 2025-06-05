class Solution {
  public:
    
    vector<vector<int>> dp;
    
    int kp(int W, vector<int> &val, vector<int> &wt, int n){
        
        if(n==0||W==0)
            return 0;
        
        if(dp[n][W] != -1)
            return dp[n][W];
            
        if(wt[n-1]<=W){
            int keep = val[n-1] + kp(W-wt[n-1], val, wt, n-1);
            int notkeep = kp(W, val, wt, n-1);
            
            return dp[n][W] = max(keep, notkeep);
        }
        
        return dp[n][W] = kp(W, val, wt, n-1);
        
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        
        dp.assign(val.size() + 1, vector<int>(W + 1, -1));
        
        return kp(W, val, wt, val.size());
        
    }
};