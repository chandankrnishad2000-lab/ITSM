#include <iostream>
using namespace std;
int main (){
    int arr[21]{};
    for (int i=0; i<21; i++){
        arr[i] = i;

        cout << arr[i] << " ";

        for (int j=0; j<21; j++){
            if(arr[i] == arr[j]){
                cout << "Found: " << arr[i] << endl;
                break;
            }   
        }
        if (arr[i] <2)
        continue;

        bool isPrime = true;
        for (int k=2; k<=arr[i]/2; k++){
            if(arr[i] % k == 0){
                isPrime = false;
                break;  

    }
}
if (isPrime){
    cout << arr[i] << " Number  is a prime number." << endl;
}
    }
    return 0;
}