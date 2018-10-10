#include <iostream>
using namespace std;

int knapsack(int * weights, int * values, int maxWeight, int n, int ** dp){
    if(n  == 0){
        return 0;
    }

    if(dp[n][maxWeight] != -1){
        return dp[n][maxWeight];
    }

    if(maxWeight < weights[0]){
        return dp[n][maxWeight] = knapsack(weights+1, values+1, maxWeight, n-1,dp);
    }

    return dp[n][maxWeight] = max(knapsack(weights+1, values+1, maxWeight-weights[0], n-1,dp)+values[0],
           knapsack(weights+1, values+1, maxWeight, n-1,dp));
}

int main() {            
    int value[] = {60,100,120};
    int weight[] = {10,20,30};
    int W = 50;
    int n = 3;
    int ** dp = new int*[n+1]();
    for(int i=0;i<=3;i++){
        dp[i] = new int[W+1]();

        // for(int j=0;j<=W;j++)
        //     dp[i][j] = -1;
    }

    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }

    for(int i=0;i<=W;i++){
        dp[0][i] = 0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(weight[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j-weight[i-1]]+value[i-1], dp[i-1][j]);
            }
        }
    }


    // cout << knapsack(weight, value, W, 3, dp) << endl;
    cout << dp[n][W];
}

