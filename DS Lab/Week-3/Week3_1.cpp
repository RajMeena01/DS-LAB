#include <bits/stdc++.h>
using namespace std;
int main(){
 int k;
    cout << "Enter the number of elements: ";
    cin >> k;

    vector<int> nums(k);

    cout << "Enter " << k << " elements: ";
    for (int i = 0; i < k; ++i)
    {
        cin >> nums[i];
    }
    int count =0;

    for(int i =0 ; i< k ; i++){
        int flag =0;
        for(int j = 0; j< k-i-1; j++){
            if(nums[j+1]<nums[j]){
                swap(nums[j], nums[j+1]);
                count++;
                flag =1;
            }
        }
        if(flag ==0){
            break;
        }
    }
     for (int i = 0; i < k; ++i)
    {
        cout<< nums[i]<<" ";
    }
    cout<<endl<<"no of swaps is :"<<count<<endl;
}