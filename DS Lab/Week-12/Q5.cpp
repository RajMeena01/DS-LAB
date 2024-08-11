#include<bits/stdc++.h>
using namespace std;
class Median {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>> maxHeap;
public:
    void addNum(int num) {
        if (maxHeap.size() == 0 || num <= maxHeap.top())  maxHeap.push(num);
        else minHeap.push(num);

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) return (maxHeap.top() + minHeap.top()) / 2.0;
        else  return maxHeap.top();
    }
};

int main() {
    Median m;

    m.addNum(1);
    m.addNum(2);
    m.addNum(3);
    m.addNum(4);
    m.addNum(5);
    cout << "Median is: " << m.findMedian() << endl;
    return 0;
}