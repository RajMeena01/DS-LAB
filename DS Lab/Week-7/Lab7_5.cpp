#include<iostream>
#include<stack>
using namespace std;
class MinStack {
    stack<int> obj;
public:
    int mini;
    void push(int val) {
        if(!obj.empty()){
            obj.push(val);
            mini= val;
        }
        else{
            if(val<mini){
                obj.push(2*val-mini);
                mini=val;
            }
            else{
                obj.push(val);
            }
        }
    }
    void pop() {
        if(!obj.empty()){ 
        int curr=obj.top();
        if(curr>mini){
            obj.pop();
        }
        else{
            int val=2*mini-curr;
            mini=val;
            obj.pop();
        }
    }
    }
    int top() {
        if(obj.empty()){
            return -1;
        }
        int curr=obj.top();
        if(curr<mini){
            return mini;
        }
        else{
            return curr;
        }
    }
    
    int getMin() {
        if(obj.empty()) return -1;
        else return mini;
    }
};
int main(){
     MinStack s;
     s.push(3);
     s.push(4);
     s.push(6);
     s.push(2);
     s.push(1);
     s.pop();
     s.pop();
     cout<<"Top of stack is :"<<s.top()<<endl;
     cout<<"Min element is : "<<s.getMin()<<endl;
}