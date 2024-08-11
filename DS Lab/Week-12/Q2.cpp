#include <bits/stdc++.h>
using namespace std;
class MinHeap {
public:
    int arr[1000];
    int size;

    MinHeap() {
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
            if (arr[parent] > arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }
    void heapify(int index) {
        int smallest = index;
        int left = 2 * index;
        int right = 2 * index + 1;

        if (left <= size && arr[smallest] > arr[left]) {
            smallest = left;
        }
        if (right <= size && arr[smallest] > arr[right]) {
            smallest = right;
        }
        if (smallest != index) {
            swap(arr[smallest], arr[index]);
            heapify(smallest);
        }
    }

    void print_heap() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
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

    void print_heap() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    int n;
    cout << "Enter the number of elements to be inserted: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the Kth element to find: ";
    cin >> k;

    // Finding Kth smallest element using MinHeap
    MinHeap minHeap;
    for (int i = 0; i < n; i++) {
        minHeap.insert(arr[i]);
    }
    for (int i = 1; i < k; i++) {
        minHeap.deleteFromHeap();
    }
    cout << "Kth smallest element is: " << minHeap.arr[1] << endl;

    // Finding Kth largest element using MaxHeap
    MaxHeap maxHeap;
    for (int i = 0; i < n; i++) {
        maxHeap.insert(arr[i]);
    }
    for (int i = 1; i < k; i++) {
        maxHeap.deleteFromHeap();
    }
    cout << "Kth largest element is: " << maxHeap.arr[1] << endl;

    return 0;
}
