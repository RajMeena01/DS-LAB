#include <iostream>
using namespace std;
int firstOccurence(int arr[], int size, int key)
{
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;
    int ans=-1;
    while (s <= e)
    {
         if (arr[mid] == key)
        {
            ans=mid;
            e = mid - 1;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;   
}
int lastOccurence(int arr[], int size, int key){
    int s=0;
    int e=size-1;
    int mid=s+(e-s)/2;
    int ans=-1;
    while (s<=e){
        if(arr[mid]==key){
            ans=mid;
            s=mid+1;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int main()
{
    int arr[11] = {1, 2, 2, 4, 5, 6, 8, 9, 10, 12, 12};
    int key;
    cout<<"Enter the key: ";
    cin>>key;
    cout<<"First occurence of "<<key<<" is: "<<firstOccurence(arr, 11, key) << endl;
    cout<<"Last occurence of "<<key<<" is: "<<lastOccurence(arr, 11, key)<<endl;
}