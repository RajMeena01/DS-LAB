#include <iostream>
#include <vector>
using namespace std;
void printVector(const vector<int> &vec)
{
    for (int num : vec)
    {
        cout << num << " ";
    }
    cout << "\n";
}
void selectionSort(vector<int> &vec)
{
    int n = vec.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        int min_idx = i;

        for (int j = i + 1; j < n; j++)
        {
            if (vec[j] < vec[min_idx])
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            swap(vec[min_idx], vec[i]);
            swapped = true;
        }

        if (!swapped)
        {
            break; // Early termination
        }
    }
}
int main()
{
    vector<int> vec = {5, 3, 8, 1, 9, 2, 7, 4, 6};
    cout << "Original vector: ";
    printVector(vec);
    selectionSort(vec);
    cout << "Sorted vector: ";
    printVector(vec);
    return 0;
}