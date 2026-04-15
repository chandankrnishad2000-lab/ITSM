#include <iostream>
#include <algorithm>
using namespace std;

class Heap{
    int arr [100];
    int size;
public:
Heap(){
    size = 0;
}
void insert(int val){
    size++;
    arr[size] = val;
    int i = size;
    while (i > 1 && arr[i] > arr[i/2]) {
        swap(arr[i], arr[i/2]);
        i = i / 2;
    }
}
void print(){
    for (int i = 1; i <= size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void deleteFromHeap(){
    if (size == 0) {
        cout << "Heap is empty" << endl;
        return;
    }
    arr[1] = arr[size];
    size--;
    int i = 1;
    while (i < size) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int largest = i;        
        if (left <= size && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right <= size && arr[right] > arr[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(arr[i], arr[largest]);
            i = largest;
        } else {
            break;
        }
    }                                   
  }
};
int main() {
    Heap h;
    h.insert(3);
    h.insert(4);
    h.insert(9);
    h.insert(5);
    h.insert(2);
    
    // Optional: Print a message to verify
    cout << "Heap contents before deletion: ";
    h.print();
    
    h.deleteFromHeap();
    
    cout << "Heap contents after deletion: ";
    h.print();
    
    return 0;
}