#include <bits/stdc++.h>
using namespace std;

int pivot(vector<int> &nums, int n)
{
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        int mid = s + (e - s) / 2;
        if (nums[mid] >= nums[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }
    return s;
}
int binarySearch(vector<int> &nums, int s, int e, int target)
{
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
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
    int target;
    cout << "enter the target element " << endl;
    cin >> target;
    int index =-1;
    int piv = pivot(nums, k);
    if(nums[piv]<=target && target <=nums[k-1]){
        index = binarySearch(nums, piv,k-1 ,target);
        cout<<"index of target is : "<<index;
    }
    else{
        index = binarySearch(nums, 0,piv-1 ,target);
        cout<<"index of target is : "<<index;
    }
}