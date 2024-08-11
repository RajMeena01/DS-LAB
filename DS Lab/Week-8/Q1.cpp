#include <iostream>
#include <queue>
using namespace std;
void generateBinaryNumbers(int n) {
    queue<string> q;
    q.push("1");
    for (int i = 0; i < n; ++i) {
        string front = q.front();
        q.pop();
        cout << front << endl;

        q.push(front + "0");
        q.push(front + "1");
    }
}
int main() {
    int n;
    cout << "Enter the number of binary numbers to generate: ";
    cin >> n;
    cout << "First " << n << " binary numbers are:" << endl;
    generateBinaryNumbers(n);
    return 0;
}
