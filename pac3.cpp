#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

// MAX HEAP
void maxHeapify(vector<int> &a, int size, int pos)
{
    int big = pos;
    int left = 2 * pos + 1;
    int right = 2 * pos + 2;

    if (left < size && a[left] > a[big])
        big = left;

    if (right < size && a[right] > a[big])
        big = right;

    if (big != pos)
    {
        swap(a[pos], a[big]);
        maxHeapify(a, size, big);
    }
}

void maxHeapSort(vector<int> &a)
{
    int size = a.size();

    for (int i = size / 2 - 1; i >= 0; i--)
        maxHeapify(a, size, i);

    for (int i = size - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        maxHeapify(a, i, 0);
    }
}

// MIN HEAP
void minHeapify(vector<int> &a, int size, int pos)
{
    int small = pos;
    int left = 2 * pos + 1;
    int right = 2 * pos + 2;

    if (left < size && a[left] < a[small])
        small = left;

    if (right < size && a[right] < a[small])
        small = right;

    if (small != pos)
    {
        swap(a[pos], a[small]);
        minHeapify(a, size, small);
    }
}

void minHeapSort(vector<int> &a)
{
    int size = a.size();

    for (int i = size / 2 - 1; i >= 0; i--)
        minHeapify(a, size, i);

    for (int i = size - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        minHeapify(a, i, 0);
    }

    reverse(a.begin(), a.end());
}

int main()
{
    int count;

    cout << "Enter number of elements: ";
    cin >> count;

    vector<int> data(count);

    srand(time(0));

    for (int i = 0; i < count; i++)
        data[i] = rand() % 100000;

    vector<int> maxArray = data;
    vector<int> minArray = data;

    // MAX HEAP SORT
    auto start1 = high_resolution_clock::now();

    maxHeapSort(maxArray);

    auto end1 = high_resolution_clock::now();

    // MIN HEAP SORT
    auto start2 = high_resolution_clock::now();

    minHeapSort(minArray);

    auto end2 = high_resolution_clock::now();

    // TIME
    auto nano1 = duration_cast<nanoseconds>(end1 - start1);
    auto micro1 = duration_cast<microseconds>(end1 - start1);
    auto milli1 = duration_cast<milliseconds>(end1 - start1);

    auto nano2 = duration_cast<nanoseconds>(end2 - start2);
    auto micro2 = duration_cast<microseconds>(end2 - start2);
    auto milli2 = duration_cast<milliseconds>(end2 - start2);

    cout << "\n========== MAX HEAP SORT ==========\n";
    cout << "Nanoseconds  : " << nano1.count() << " ns\n";
    cout << "Microseconds : " << micro1.count() << " us\n";
    cout << "Milliseconds : " << milli1.count() << " ms\n";

    cout << "\n========== MIN HEAP SORT ==========\n";
    cout << "Nanoseconds  : " << nano2.count() << " ns\n";
    cout << "Microseconds : " << micro2.count() << " us\n";
    cout << "Milliseconds : " << milli2.count() << " ms\n";

    return 0;
}