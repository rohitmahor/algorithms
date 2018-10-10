#include <iostream>
using namespace std;

int main() {            
    long long adjMatrix[4][4] = {{0,5,INT_MAX,10},
                        {INT_MAX, 0,3,INT_MAX},
                        {INT_MAX,INT_MAX,0,1},
                        {INT_MAX, INT_MAX, INT_MAX, 0}};
    long long shortestPath[4][4] = {{0,5,INT_MAX,10},
                        {INT_MAX, 0,3,INT_MAX},
                        {INT_MAX,INT_MAX,0,1},
                        {INT_MAX, INT_MAX, INT_MAX, 0}};

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                shortestPath[i][j] = min(shortestPath[i][j], shortestPath[i][k]+shortestPath[k][j]);
            }
        }
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout << shortestPath[i][j] << " ";
        }
        cout << endl;
    }
}

