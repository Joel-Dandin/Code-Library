
#include <stdio.h>
#include <string.h>

#define MAX 1010

int dp[MAX][MAX]; 
int max(int a, int b){
    return (a>b)?a:b;
}
int lps(const char s[], int i, int j) {

    if(i > j) return 0;

    if(dp[i][j] > -1) return dp[i][j];

    if(s[i] == s[j]) {
        int equalCharacters = 2 - (i == j);
        return dp[i][j] = equalCharacters + lps(s, i+1, j-1);
    }
    return dp[i][j] = max( lps(s, i+1, j), lps(s, i, j-1) );
}

int longest_palindrome(const char s[]) {

    memset(dp, -1, sizeof dp);
    return lps(s, 0, strlen(s)-1);
}

int main() {
    
    printf("%d\n",longest_palindrome("bbabcbcab")); 
    printf("%d\n",longest_palindrome("abbaab"));    
    printf("%d\n",longest_palindrome("opengenus")); 
    return 0;
}