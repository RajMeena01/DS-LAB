#include<iostream>
using namespace std;
int search(int arr[], int size, int key){
    int s=0;
    int e=size;
    int mid=s+(e-s)/2;
    while(s<e){
        if(arr[mid]>key){
            e=mid;
        }
        else if(arr[mid]<key){
            s=mid+1;
        }
        else{
            return true;
        }
        mid=s+(e-s)/2;
    }
    return false;
}
int main(){
    int arr[5]={1,2,3,4,5};
    int key;
    cout<<"Enter the key: ";
    cin>>key;
    cout<<search(arr, 5, key)<<endl;
}