#include <iostream>
using namespace std;
void cyclicRightRotate(int arr[], int n, int d)
{
    d = d % n;
    int temp[d];
    for (int i = n - d; i < n; ++i)
        temp[i - (n - d)] = arr[i];
    for (int i = n - 1; i >= d; --i)
        arr[i] = arr[i - d];
    for (int i = 0; i < d; ++i)
        arr[i] = temp[i];
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int steps = 2;
    printArray(arr, n);
    cyclicRightRotate(arr, n, steps);
    printArray(arr, n);
    return 0;
}
