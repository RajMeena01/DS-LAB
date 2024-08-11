#include <iostream>
#include <vector>
using namespace std;
int comparison_count = 0;
int binarySearch(const vector<int> &arr, int key, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        comparison_count++; 
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
void insertionSortWithBinarySearch(vector<int> &arr)
{
    comparison_count = 0; 
    int n = arr.size();
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        int pos = binarySearch(arr, key, 0, j);
        while (j >= pos)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void insertionSort(vector<int> &arr)
{
    comparison_count = 0; 
    int n = arr.size();
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            comparison_count++; 
        }
        arr[j + 1] = key;
    }
}
int main()
{
    vector<int> nums = {32, 2, 45, 12, 11, 13, 5, 6};
    cout << "Native insertion sort:"
         << "\n";
    insertionSort(nums);
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << "\n";
    cout << "Number of comparisons: " << comparison_count << "\n";
    int x = comparison_count;
    cout << "\nInsertion sort with binary search:"
         << "\n";
    vector<int> nums2 = {32, 2, 45, 12, 11, 13, 5, 6};
    insertionSortWithBinarySearch(nums2);
    for (int num : nums2)
    {
        cout << num << " ";
    }
    cout << "\n";
    cout << "Number of comparisons: " << comparison_count << "\n";
    int y = comparison_count;
    int d = x - y;
    cout << "\n";
    cout << "Comparison difference: " << d << "\n";
    return 0;
}
