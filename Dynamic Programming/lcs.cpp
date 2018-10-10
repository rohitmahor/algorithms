#include <iostream>
using namespace std;

int lengthLCS(string str1, string str2, int ** dp, int m, int n){
    if(str1.empty() || str2.empty()){
        return 0;
    }

    if(dp[m][n] != -1){
        return dp[m][n];
    }

    if(str1[0] == str2[0]){
        return dp[m][n] = lengthLCS(str1.substr(1), str2.substr(1), dp, m-1, n-1)+1;
    }

    dp[m-1][n] = lengthLCS(str1.substr(1), str2, dp, m-1, n);
    dp[m][n-1] = lengthLCS(str1, str2.substr(1), dp, m, n-1);

    return dp[m][n] = max(dp[m-1][n], dp[m][n-1]);
}

int main() {
    int arr[] = {6,4,2,7,3,2,5};
    int n = 7;

    int ** dp = new int*[10]();
    for(int i=0;i<10;i++){
        dp[i] = new int[10]();

        for(int j=0;j<10;j++)
            dp[i][j] = -1;
    }
    
    cout << lengthLCS("AGGTAB", "GXTXAYB", dp, 6, 7);
}

