#include <iostream>
using namespace std;

int main() {
    int sum = 0;

    for(int i = 1; i <= 10; i++) {
        cout << i;

        if(i < 10)
            cout << "+";

        sum += i;
    }

    cout << "=" << sum << endl;

    return 0;
}
