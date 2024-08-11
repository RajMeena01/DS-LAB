#include<iostream>
#include<vector>
using namespace std;

vector<int> findPeakElements(const vector<int> &nums)
{
    vector<int> peaks;
    int n = nums.size();

    if (n == 0)
        return peaks;

    if ( nums[0] >= nums[1])
        peaks.push_back(nums[0]);

    for (int i = 1; i < n - 1; ++i)
    {
        if (nums[i] >= nums[i - 1] && nums[i] >= nums[i + 1])
            peaks.push_back(nums[i]);
    }

    if (nums[n - 1] >= nums[n - 2] )
        peaks.push_back(nums[n - 1]);

    return peaks;
}

int main()
{
    int k;
    cout << "Enter the number of elements: ";
    cin >> k;

    vector<int> nums(k);

    cout << "Enter " << k << " elements: ";
    for (int i = 0; i < k; ++i)
    {
        cin >> nums[i];
    }
    vector<int> peakElements = findPeakElements(nums);

    cout << "Peak elements: ";
    for (int peak : peakElements)
    {
        cout << peak << " ";
    }
    cout << endl;
}