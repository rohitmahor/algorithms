#include <iostream>
using namespace std;

long binomial(int n, int k, long dp[][50]){

    if(k==0 || k == n){
        return dp[n][k] = 1;
    }

    if(dp[n][k] != -1){
        return dp[n][k];
    }

    dp[n-1][k-1]  = binomial(n-1, k-1, dp);
    dp[n-1][k] = binomial(n-1, k, dp);

    return dp[n][k] = dp[n-1][k-1]+dp[n-1][k];
}

int main() {            
    long dp[50][50];

    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            dp[i][j] = -1;
        }
    }
    cout << binomial(5,2, dp);
}

