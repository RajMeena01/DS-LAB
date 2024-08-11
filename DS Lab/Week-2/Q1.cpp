#include<iostream>
using namespace std;
int search(int arr[], int size, int key){
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            return true;
        }
    }
    return false;
}
int main(){
    int arr[5]={2,3,1,5,4};
    int key;
    cout<<"Enter the key: ";
    cin>>key;
    cout<<search(arr, 5, key)<<endl;
}