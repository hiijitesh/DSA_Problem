class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        return longestCommonSubsequence(s1,s2);
    }
    
      int longestCommonSubsequence(string s1, string s2) 
    {
        
        int m = s1.size();
        int n = s2.size();
        
        int dp[m+1][n+1];
        for(int i = 0; i < m+1; i++)
        {
            for(int j = 0; j < n+1; j++)
            {
                if(i == 0 or j == 0)
                    dp[i][j] = 0;
            }
        }
        
        
        for(int i = 1; i <m+1; i++)
        {
            for(int j = 1; j <n+1; j++)
            {
                if(s1[i-1] ==s2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                
                else
                {
                    dp[i][j] =  max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        
        return dp[m][n];
    }
};