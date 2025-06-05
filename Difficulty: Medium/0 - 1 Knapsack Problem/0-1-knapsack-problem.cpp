class Solution {
  public:
    
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        vector<vector<int>> dp(val.size() + 1, vector<int>(W + 1, 0));
        
        for(int i=0;i<val.size() + 1;i++)
            dp[i][0] = 0;
            
        for(int i=0;i<W + 1;i++)
            dp[0][i] = 0;
            
        
        for(int i=1;i<val.size() + 1; i++){
            for(int j=1; j< W + 1; j++){
                
                if(wt[i-1] <= j){
                    dp[i][j] = max(
                    (val[i-1] + dp[i-1][j-wt[i-1]]),
                    dp[i-1][j]
                    );
                }
                else
                    dp[i][j] = dp[i-1][j];
                
                
                
            }
        }
        
        
        
        return dp[val.size()][W];
        
    }
};