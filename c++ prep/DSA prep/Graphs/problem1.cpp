#include <iostream>
using namespace std;

int main(){
    int  n = 4;
    int adj [4][4] = {0};
    adj[0][1] = 1;
    adj[1][0] = 1;
    adj[1][2] = 1;
    adj[2][1] = 1;  
    adj[2][3] = 1;
    adj[3][2] = 1;
    for(int i =0; i<n; i++){
        for (int j =0; j<n; j++){
            cout << adj [i][j] << " ";

        }
    }

}

