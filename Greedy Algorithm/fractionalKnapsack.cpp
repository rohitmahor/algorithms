#include <bits/stdc++.h>
using namespace std;

struct item{
    int weight;
    int value;
};

bool compare(item a, item b){
    return float(a.value)/a.weight > float(b.value)/b.weight;
}

int main() {      
    int n = 3;
    item arr[] = {{10,60},{20,100},{30,120}};
    int W = 50;
    sort(arr, arr+n, compare);
    int i = 0, remW = W, ans = 0;
    while(arr[i].weight < remW && i < n){
        ans += arr[i].value;
        remW = remW - arr[i].weight;
        i++;
    }

    if(i < n){
        ans += float(float(arr[i].value)/arr[i].weight)*remW;
    }

    cout << ans << endl;

}

