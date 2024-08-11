#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Radix Sort for positive integers
int getMax(vector<int>& arr) {
    int max_val = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max_val)
            max_val = arr[i];
    }
    return max_val;
}
void countSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    for (int num : arr)
        count[(num / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixSort(vector<int>& arr) {
    int max_val = getMax(arr);
    for (int exp = 1; max_val / exp > 0; exp *= 10)
        countSort(arr, exp);
}
int getMax(vector<string>& arr) {
    int max_len = 0;
    for (string str : arr)
        max_len = max(max_len, (int)str.length());
    return max_len;
}
void countSort(vector<string>& arr, int exp) {
    int n = arr.size();
    vector<string> output(n);
    int count[256] = {0};
    for (string str : arr)
        count[(int)(str[str.length() - exp / 8 - 1])]++;
    for (int i = 1; i < 256; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[(int)(arr[i][arr[i].length() - exp / 8 - 1])] - 1] = arr[i];
        count[(int)(arr[i][arr[i].length() - exp / 8 - 1])]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixSort(vector<string>& arr) {
    int max_len = getMax(arr);
    for (int exp = 8; max_len / exp > 0; exp *= 8)
        countSort(arr, exp);
}
int main() {
    vector<int> intArr = {170, 45, 75, 90, 802, 24, 2, 66};
    vector<string> strArr = {"apple", "banana", "cherry", "date", "elderberry"};
    cout << "Original integer array: ";
    for (int num : intArr)
        cout << num << " ";
    cout << "\n";
    radixSort(intArr);
    cout << "Sorted integer array: ";
    for (int num : intArr)
        cout << num << " ";
    cout << "\n\n";
    cout << "Original string array: ";
    for (string str : strArr)
        cout << str << " ";
    cout << "\n";
    radixSort(strArr);
    cout << "Sorted string array: ";
    for (string str : strArr)
        cout << str << " ";
    cout << "\n";
    return 0;
}