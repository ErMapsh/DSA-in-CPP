class Solution {
public:

    int coinChange(vector<int>& coins, int amt) {
        int n=coins.size();
         vector<vector<int>> dp(n+1,vector<int> (amt+1,INT_MAX-1));
         for(int i=0;i<=n;i++){
            dp[i][0]=0;
         }
         for(int i=1;i<=n;i++){
            for(int j=1;j<=amt;j++){
                dp[i][j]=dp[i-1][j];
                if(coins[i-1]<=j){
                     dp[i][j]=min(dp[i][j],1+dp[i][j-coins[i-1]]);
                }
               
            }
         }
         if(dp[n][amt]>=INT_MAX-1){
            dp[n][amt]=-1;
         }
         return dp[n][amt];
    }
};