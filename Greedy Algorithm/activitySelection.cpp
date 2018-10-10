#include <bits/stdc++.h>
using namespace std;



struct activity{
    int start;
    int finish;
};

bool compare(activity a, activity b){
    if(a.finish == b.finish){
      return a.start < b.start;
    }
    return a.finish < b.finish;
}

int main() {
  int n = 6;
  activity arr[] = {{1,2},{3,4},{0,6},{5,7},{8,9},{5,9}};
  sort(arr, arr+n, compare);

  int finish = arr[0].finish;
  vector<activity> vect;
  vect.push_back(arr[0]);
  for(int i=1;i<n;i++){
      if(arr[i].start >= finish){
          vect.push_back(arr[i]);
          finish = arr[i].finish;
      }
  }

  for(auto x:vect){
      cout << x.start << " " << x.finish << endl;
  }
}
