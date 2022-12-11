
#include<bits/stdc++.h>

int minSkips(vector<int>& dist, int speed, int reachTime) 
{
    int n = dist.size();
    double time[n];
    
    for(int i=0; i<n ; i++)
    {
        time[i] = dist[i]*1.0/speed;
    }
    
    
    double dp[n][n];
    memset(dp, 0, sizeof(dp));
    
    double eps = 0.00000001;
    
    for(int i=0;i<n;i++)
    {
        
        for(int j=0;j<=i;j++)
        {
            
            if(i == 0 && j == 0) 
                dp[i][j]=time[i];

            else if (j == 0) 
                dp[i][0] = ceil(dp[i-1][0]- eps)+time[i];

            else if (i == j) 
                dp[i][j] = dp[i-1][j-1]+time[i];

            else 
                dp[i][j] = min( ceil (dp[i-1][j] - eps), dp[i-1][j-1]) + time[i];
        } 
    }
      
    for(int j=0;j<n;j++)
    {
        if( dp[n-1][j] <= reachTime ) 
            return j;
    }
    
    return -1;
}