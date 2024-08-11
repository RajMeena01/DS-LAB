#include <iostream>
using namespace std;
int nthSmallest(int arr[], int size, int n) {
    sort(arr, arr + size);
    return arr[n - 1];
}
int nthLargest(int arr[], int size, int n) {
    sort(arr, arr + size, greater<int>());
    return arr[n - 1];
}
int main() {
    int arr[] = {12, 45, 1, 51, 19, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int n = 3;
    cout << "Original Array: ";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
    cout << n << "rd smallest element: " << nthSmallest(arr, size, n) << endl;
    cout << n << "rd largest element: " << nthLargest(arr, size, n) << endl;
    return 0;
}
