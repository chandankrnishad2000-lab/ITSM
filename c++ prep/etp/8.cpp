#include <iostream>
#include <iomanip>
using namespace std;
int main (){
    double sum = 0;
    for(int i=1;i<=4; i++){
        cout <<i << "/"<< (i+1);

        if(i<4){
            cout << "+";
        }   
        sum += (double)i/(i+1);
    }

    cout <<" = " << fixed << setprecision(4) << sum << endl;
    return 0;
}   