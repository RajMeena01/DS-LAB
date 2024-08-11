#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int getMax(vector<int>& arr) {
    int max_val = arr[0];
    for (int num : arr)
        max_val = max(max_val, abs(num));
    return max_val;
}
void countSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[19] = {0};
    for (int num : arr)
        count[(num / exp) % 19 + 9]++;
    for (int i = 1; i < 19; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 19 + 9] - 1] = arr[i];
        count[(arr[i] / exp) % 19 + 9]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixSort(vector<int>& arr) {
    int max_val = getMax(arr);

    for (int exp = 1; max_val / exp > 0; exp *= 19)
        countSort(arr, exp);
}
int main() {
    vector<int> arr = {-5, 20, -15, 7, 35, -22};
    cout << "Original array: ";
    for (int num : arr)
        cout << num << " ";
    cout << "\n";
    radixSort(arr);
    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << "\n";
    return 0;
}