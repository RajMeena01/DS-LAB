#include<iostream>
using namespace std;
void merge(int *arr,int s,int e)
{
    int mid=s+(e-s)/2;
    int l1=mid-s+1;
    int l2=e-mid;
    int *first=new int[l1];
    int *second=new int[l2];
    int mainarrayindex=s;
    for(int i=0;i<l1;i++)
    {
        first[i]=arr[mainarrayindex++];
    }
     mainarrayindex=mid+1;
    for(int i=0;i<l2;i++)
    {
        second[i]=arr[mainarrayindex++];
    }
    int index1=0;
    int index2=0;
    mainarrayindex=s;
    while(index1<l1 &&index2<l2)
    {
        if(first[index1]<second[index2])
        {
            arr[mainarrayindex++]=first[index1++];
        }
        else{
            arr[mainarrayindex++]=second[index2++];
        }
    }
    while(index1<l1)
    {
        arr[mainarrayindex++]=first[index1++];
    }
    while(index2<l2)
    {
        arr[mainarrayindex++]=second[index2++];
    }
    delete []first;
    delete []second;
}
void mergesort(int *arr,int s,int e)
{
    if(s>=e)  return ;
    int mid=s+(e-s)/2;

    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,e);
}
int main()
{
    int n;
    cout<<"enter the size of array:";
    cin>>n;
    int arr[n];
    cout<<" \n enter the "<<n<<" elements:";
    for(int i =0 ; i<n ; i++){
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}