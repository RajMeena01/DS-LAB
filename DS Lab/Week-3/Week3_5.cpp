#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <chrono>
#include <algorithm>
#include <iomanip>
using namespace std;
using namespace std::chrono;
vector<int> randomVec, sortedVec, reverseSortedVec;
void generateRandomNumbers()
{
    randomVec.clear();
    sortedVec.clear();
    reverseSortedVec.clear();
    srand(time(0));
    for (int i = 0; i < 50; i++)
    {
        int num = (rand() % 100) + 1;
        randomVec.emplace_back(num);
        sortedVec.emplace_back(num);
        reverseSortedVec.emplace_back(num);
    }
    sort(sortedVec.begin(), sortedVec.end());
    sort(reverseSortedVec.begin(), reverseSortedVec.end(), greater<int>());
}
void printVector(const vector<int> &vec, const string &caption)
{
    cout << caption << ": ";
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << "\n";
}
int bubble_sort(const vector<int> &vec, const string &caption)
{
    vector<int> arr_copy = vec;
    size_t n = arr_copy.size();
    auto start = high_resolution_clock::now();

    for (size_t i = 0; i < n; ++i)
    {
        int sw = 0;
        for (size_t j = 0; j < n - i - 1; ++j)
        {
            if (arr_copy[j] > arr_copy[j + 1])
            {
                std::swap(arr_copy[j], arr_copy[j + 1]);
                sw++;
            }
        }
        if (sw == 0)
        {
            break;
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nBubble Sort (" << caption << "): " << duration.count() << " microseconds\n";
    printVector(arr_copy, "Sorted Vector");
    return 0;
}
int insertion_sort(const vector<int> &vec, const string &caption)
{
    vector<int> arr_copy = vec;
    size_t n = arr_copy.size();
    auto start = high_resolution_clock::now();

    for (size_t i = 1; i < n; i++)
    {
        int key = arr_copy[i];
        int j = i - 1;

        while (j >= 0 && arr_copy[j] > key)
        {
            arr_copy[j + 1] = arr_copy[j];
            j--;
        }
        arr_copy[j + 1] = key;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nInsertion Sort (" << caption << "): " << duration.count() << " microseconds\n";
    printVector(arr_copy, "Sorted Vector");
    return 0;
}
int selection_sort(const vector<int> &vec, const string &caption)
{
    vector<int> arr_copy = vec;
    size_t n = arr_copy.size();
    auto start = high_resolution_clock::now();

    for (size_t i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (size_t j = i + 1; j < n; j++)
        {
            if (arr_copy[j] < arr_copy[min_idx])
            {
                min_idx = j;
            }
        }
        swap(arr_copy[min_idx], arr_copy[i]);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nSelection Sort (" << caption << "): " << duration.count() << " microseconds\n";
    printVector(arr_copy, "Sorted Vector");
    return 0;
}
int main()
{
    generateRandomNumbers();
    cout << "\n------ Random Vector ------\n";
    printVector(randomVec, "Random Vector");
    bubble_sort(randomVec, "Random Vector");
    insertion_sort(randomVec, "Random Vector");
    selection_sort(randomVec, "Random Vector");
    cout << "\n------ Sorted Vector ------\n";
    printVector(sortedVec, "Sorted Vector");
    bubble_sort(sortedVec, "Sorted Vector");
    insertion_sort(sortedVec, "Sorted Vector");
    selection_sort(sortedVec, "Sorted Vector");
    cout << "\n------ Reverse Sorted Vector ------\n";
    printVector(reverseSortedVec, "Reverse Sorted Vector");
    bubble_sort(reverseSortedVec, "Reverse Sorted Vector");
    insertion_sort(reverseSortedVec, "Reverse Sorted Vector");
    selection_sort(reverseSortedVec, "Reverse Sorted Vector");
    return 0;
}