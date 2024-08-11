#include <bits/stdc++.h>
using namespace std;
void merge(vector<string>& arr, int left , int right, int mid){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<string> l1(n1), l2(n2);
    for(int i = 0; i < n1; i++){
        l1[i] = arr[left + i];
    }
    for(int i = 0; i < n2; i++){
        l2[i] = arr[mid + i + 1];
    }
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
        if(l1[i] < l2[j]){
            arr[k++] = l1[i++];
        }
        else{
            arr[k++] = l2[j++];
        }
    }
    while(i < n1){
        arr[k++] = l1[i++];
    }
    while(j < n2){
        arr[k++] = l2[j++];
    }
}
void mergesort(vector<string>& arr, int s, int e){
    if(s >= e)  
        return;
    int mid = s + (e - s) / 2;
    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);
    merge(arr, s, e, mid);
}
int main() {
    vector<string> arr = {"banana", "apple", "orange", "grape", "pineapple"};
    int n = arr.size();
    mergesort(arr, 0, n - 1);
    cout << "Sorted array:" << endl;
    for (const string& s : arr) {
        cout << s << endl;
    }
}
