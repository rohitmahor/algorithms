#include <bits/stdc++.h>
using namespace std;

struct item{
    int start;
    int finish;
    int profit;
};

bool compare(item a, item b){
    return a.finish <= b.finish;
}

int findNext(item arr[], int i){
    for(int j=i-1;j>=0;j--){
        if(arr[i-1].start >= arr[j].finish){
            return j;
        }
    }

    return -1;
}

int jobScheduling(item arr[], int n, int * dp){
    if(n == 1){
        return dp[0] = arr[0].profit;
    }

    if(dp[n-1] != -1){
        return dp[n-1];
    }

    int j = findNext(arr, n);
    int inc = arr[n-1].profit;
    if(j != -1){
        dp[j] = jobScheduling(arr, j+1, dp);
        inc += dp[j];
    }

    return dp[n-1] =  max(jobScheduling(arr, n-1, dp), inc);
}

int main() {      
    int n = 4;
    item arr[] = {{1, 2, 50}, {3, 5, 20}, {6, 19, 100}, {2, 100, 200}};
   
    sort(arr, arr+n, compare);

    int * dp = new int[n];
    for(int i=0;i<n;i++){
        dp[i] = -1;
    }
    cout << jobScheduling(arr, n, dp);

}

