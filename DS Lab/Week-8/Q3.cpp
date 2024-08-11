#include<bits/stdc++.h>
using namespace std;
int main() {
    queue<int> q1;
    stack<int> st;
    int n;
    cout << "Enter the number of elements to insert: ";
    cin >> n;
    cout << "Enter " << n << " numbers to insert into the queue:\n";
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        q1.push(num);
    }
    while (!q1.empty()) {
        st.push(q1.front());
        q1.pop();
    }
    while (!st.empty()) {
        int top = st.top();
        st.pop();
        q1.push(top);
    }
    cout << "Queue after reversal: ";
    while (!q1.empty()) {
        cout << q1.front() << " ";
        q1.pop();
    }
    cout<<endl;
    return 0;
}