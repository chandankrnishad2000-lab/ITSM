#include <iostream>
using namespace std;
int main (){
    int sum=0;
    for (int i=1; i<=7; i++){
        if(i % 2==1){
            sum += i;
            cout << i;

        }else{
            sum -= i;
            cout << "-" << i;
        }

        if (i<7 && i % 2 ==1 ){
            cout << "+";
        }   

    }
    cout << "=" << sum << endl;
    return 0;
}