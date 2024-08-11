
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
int partition_r(vector<int>& arr, int low, int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);
 
    swap(arr[random], arr[high]);
 
    return partition(arr, low, high);
}
void quicksort(vector<int>& arr,int s,int e)
 {
   if( s< e){
    int p=partition_r(arr,s,e);
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