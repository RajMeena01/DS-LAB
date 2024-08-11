#include <iostream>
using namespace std;
void intersection(int arr1[], int arr2[], int m, int n) {
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr2[j] < arr1[i]) {
            j++;
        } else {
            cout << arr2[j] << " ";
            i++;
            j++;
        }
    }
}
int main() {
    int arr1[] = {1, 2, 2, 3, 4};
    int arr2[] = {2, 2, 4, 6};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Intersection: ";
    intersection(arr1, arr2, m, n);
    cout << endl;
    return 0;
}

