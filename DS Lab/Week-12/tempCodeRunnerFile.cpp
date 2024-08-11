#include <bits/stdc++.h>
using namespace std;
string frequencySort(string s) {
    unordered_map<char, int> freqMap;
    for (char c : s) {
        freqMap[c]++;
    }
    priority_queue<pair<int, char>> maxHeap;
    for (auto& entry : freqMap) {
        maxHeap.push({entry.second, entry.first});
    }
    string result;
    while (!maxHeap.empty()) {
        auto top = maxHeap.top();
        maxHeap.pop();
        result.append(top.first, top.second);
    }
    return result;
}
int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    string sortedString = frequencySort(s);
    cout << "String sorted by frequency: " << sortedString << endl;

    return 0;
}
