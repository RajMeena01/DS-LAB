#include <bits/stdc++.h>
using namespace std;
class MinHeap {
public:
    int arr[1000];
    int size;

    MinHeap() {
        arr[0] = -1; // Dummy value at index 0 for easier calculations
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

    void increase_key(int index, int val) {
        if (index > size) {
            cout << "This index doesn't exist" << endl;
            return;
        }
        arr[index] = val;
        heapify(index);
    }

    void decrease_key(int index, int val) {
        if (index > size) {
            cout << "This index doesn't exist" << endl;
            return;
        }
        arr[index] = val;
        upwardMovement(index);
    }

    void upwardMovement(int index) {
        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] > arr[index]) { // For min-heap, parent should be greater than the child
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

int main() {
    MinHeap h;
    h.insert(3);
    h.insert(1);
    h.insert(6);
    h.insert(5);
    h.insert(9);
    h.insert(8);

    cout << "Heap after inserts: ";
    h.print_heap();

    h.deleteFromHeap();
    cout << "Heap after delete: ";
    h.print_heap();

    h.decrease_key(3, 2);
    cout << "Heap after decreasing key at index 3 to 2: ";
    h.print_heap();

    h.increase_key(2, 10);
    cout << "Heap after increasing key at index 2 to 10: ";
    h.print_heap();

    return 0;
}
