#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void countingSort(vector<int>& arr) {
    int n = arr.size();
    int max_val = *max_element(arr.begin(), arr.end());
    vector<int> count(max_val + 1, 0);
    vector<int> output(n);
    for (int num : arr) {
        count[num]++;
    }
    for (int i = 1; i <= max_val; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}
void countingSort(string& str) {
    int n = str.length();
    vector<int> count(256, 0);  
    vector<char> output(n);
    for (char c : str) {
        count[c]++;
    }
    for (int i = 1; i < 256; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        output[count[str[i]] - 1] = str[i];
        count[str[i]]--;
    }
    for (int i = 0; i < n; i++) {
        str[i] = output[i];
    }
}
int main() {
    vector<int> arr = {5, 3, 2, 8, 7, 6, 5, 3, 1};
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";
    countingSort(arr);
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n\n";
    string str1 = "bcdaec";
    string str2 = "learningcpp";
    string str3 = "sortingalgorithms";
    cout << "Original string 1: " << str1 << "\n";
    countingSort(str1);
    cout << "Sorted string 1: " << str1 << "\n";
    cout << "Original string 2: " << str2 << "\n";
    countingSort(str2);
    cout << "Sorted string 2: " << str2 << "\n";
    cout << "Original string 3: " << str3 << "\n";
    countingSort(str3);
    cout << "Sorted string 3: " << str3 << "\n";
    return 0;
}