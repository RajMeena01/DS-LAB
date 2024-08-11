#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class node{
    public:
    int data;
    node * left, *right;
    node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
vector<int> minmax(vector<int> arr, int n){
    int lvl = 0;
    int mi = INT_MAX,ma = INT_MIN;
    while(1<<lvl < n){
        for(int j = lvl!=0?1<<(lvl-1):0;j<1<<(lvl);j++){
            mi = min(mi,arr[j]);
            ma = max(ma,arr[j]);
        }
        lvl++;
    }
    for(int i = 1<<(lvl-1);i < n;i++){
        mi = min(mi,arr[i]);
        ma = max(ma,arr[i]);
    }
    vector<int> result;
    result.push_back(mi);
    result.push_back(ma);
    return result;
}
 void print(node * head){
    if(head == NULL)return;
    cout<<head->data<<" ";
    print(head->left);
    print(head->right);
}
int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(8);
    arr.push_back(12);
    arr.push_back(42);
    
    int s = arr.size();
    vector<int> a = minmax(arr,s);
    cout<<a[0]<<" "<<a[1]<<endl;
}