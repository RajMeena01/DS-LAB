#include <iostream>
#include <vector>
using namespace std;
int findKthSmallest(vector<int> &arr, int k)
{
    int n = arr.size();
    if (k < 0 || k >= n)
    {
        cout << "Invalid value of k." << endl;
        return -1;
    }
    for (int i = 0; i < k; ++i)
    {
        int min_index = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(arr[i], arr[min_index]);
        }
    }
    return arr[k - 1];
}
int main()
{
    vector<int> arr = {12, 11, 13, 5, 6};
    int k = 3;
    cout << "Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
    int kth_smallest = findKthSmallest(arr, k);
    cout << "The " <<  k << " numbered smallest element is: " << kth_smallest << endl;
    return 0;
}
