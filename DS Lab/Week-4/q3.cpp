#include <bits/stdc++.h>
using namespace std;
 int partition(vector<int>& arr,int s, int e)
 {
    int pivot=arr[e];
  int i = s-1;
  for(int j =s ; j <= e-1 ; j++){
    if(arr[j]<=pivot){
        i++;
        swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[e]);
    return (i+1); 
 }
 void quicksort(vector<int>& arr,int s,int e)
 {
   if( s< e){
    int p=partition(arr,s,e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
   }
 }
 int main()
 {
     int n;
    cout<<"enter the size of array:";
    cin>>n;
    vector<int>arr(n);
    cout<<" \n enter the "<<n<<" elements:";
    for(int i =0 ; i<n ; i++){
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
 }