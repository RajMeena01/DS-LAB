#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
public:
    int arr[1000];
    int size;

    MaxHeap() {
        arr[0] = -1; 
        size = 0;
    }
    void insert(int val) {
        size = size + 1;
        int index = size;
        arr[size] = val;
        upwardMovement(index);
    }
    void deleteFromHeap() {
        if (size == 0) {
            cout << "Heap is empty" << endl;
            return;
        }
        arr[1] = arr[size];
        size--;
        heapify(1);
    }
    void upwardMovement(int index) {
        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) { 
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }
    void heapify(int index) {
        int largest = index;
        int left = 2 * index;
        int right = 2 * index + 1;

        if (left <= size && arr[largest] < arr[left]) {
            largest = left;
        }
        if (right <= size && arr[largest] < arr[right]) {
            largest = right;
        }
        if (largest != index) {
            swap(arr[largest], arr[index]);
            heapify(largest);
        }
    }
    void buildHeap(int arr[], int n) {
        size = n;
        for (int i = 1; i <= n; i++) {
            this->arr[i] = arr[i - 1];
        }
        for (int i = size / 2; i > 0; i--) {
            heapify(i);
        }
    }
    void print_heap() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
void heapSort(int arr[], int n) {
    MaxHeap maxHeap;
    maxHeap.buildHeap(arr, n);

    while (maxHeap.size > 1) {
        swap(maxHeap.arr[1], maxHeap.arr[maxHeap.size]);
        maxHeap.size--;
        maxHeap.heapify(1);
    }

    for (int i = 0; i < n; i++) {
        arr[i] = maxHeap.arr[n - i];
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    heapSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
