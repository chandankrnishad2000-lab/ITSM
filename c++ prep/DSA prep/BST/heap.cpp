#include <iostream>
using namespace std;

class MaxHeap {
    int arr[100];
    int size;

public:
    MaxHeap() {
        size = 0;
    }

    void insert(int x) {
        size++;
        arr[size] = x;
        int i = size;
        while (i > 1) {
            int parent = i / 2;
            if (arr[parent] < arr[i]) {
                swap(arr[parent], arr[i]);
                i = parent;
            } else {
                return;
            }
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap h;
    h.insert(3);
    h.insert(4);
    h.insert(9);
    h.insert(5);
    h.insert(2);
    
    // Optional: Print a message to verify
    cout << "Heap contents: ";
    h.print();
    
    return 0;
}