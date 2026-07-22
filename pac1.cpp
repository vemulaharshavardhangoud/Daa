#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>


using namespace std;
using namespace std::chrono;

void bubbleSort(vector<int> &a) {
  int n = a.size();

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1])
        swap(a[j], a[j + 1]);
    }
  }
}

void selectionSort(vector<int> &a) {
  int n = a.size();

  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;

    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[minIndex])
        minIndex = j;
    }

    swap(a[i], a[minIndex]);
  }
}

void insertionSort(vector<int> &a) {
  int n = a.size();

  for (int i = 1; i < n; i++) {
    int key = a[i];
    int j = i - 1;

    while (j >= 0 && a[j] > key) {
      a[j + 1] = a[j];
      j--;
    }

    a[j + 1] = key;
  }
}

void merge(vector<int> &a, int left, int mid, int right) {
  vector<int> temp;

  int i = left;
  int j = mid + 1;

  while (i <= mid && j <= right) {
    if (a[i] <= a[j])
      temp.push_back(a[i++]);
    else
      temp.push_back(a[j++]);
  }

  while (i <= mid)
    temp.push_back(a[i++]);

  while (j <= right)
    temp.push_back(a[j++]);

  for (int k = left; k <= right; k++)
    a[k] = temp[k - left];
}

void mergeSort(vector<int> &a, int left, int right) {
  if (left >= right)
    return;

  int mid = (left + right) / 2;

  mergeSort(a, left, mid);
  mergeSort(a, mid + 1, right);

  merge(a, left, mid, right);
}

int partition(vector<int> &a, int low, int high) {
  int pivot = a[high];
  int i = low;

  for (int j = low; j < high; j++) {
    if (a[j] < pivot) {
      swap(a[i], a[j]);
      i++;
    }
  }

  swap(a[i], a[high]);

  return i;
}

void quickSort(vector<int> &a, int low, int high) {
  if (low < high) {
    int p = partition(a, low, high);

    quickSort(a, low, p - 1);
    quickSort(a, p + 1, high);
  }
}

int main() {
  int n = 100;

  vector<int> arr(n), temp;

  srand(time(0));

  for (int i = 0; i < n; i++)
    arr[i] = rand() % 1000;

  auto start = high_resolution_clock::now();
  temp = arr;
  bubbleSort(temp);
  auto end = high_resolution_clock::now();
  cout << "Bubble Sort : " << duration_cast<microseconds>(end - start).count()
       << " microseconds" << endl;

  start = high_resolution_clock::now();
  temp = arr;
  selectionSort(temp);
  end = high_resolution_clock::now();
  cout << "Selection Sort : "
       << duration_cast<microseconds>(end - start).count() << " microseconds"
       << endl;

  start = high_resolution_clock::now();
  temp = arr;
  insertionSort(temp);
  end = high_resolution_clock::now();
  cout << "Insertion Sort : "
       << duration_cast<microseconds>(end - start).count() << " microseconds"
       << endl;

  start = high_resolution_clock::now();
  temp = arr;
  mergeSort(temp, 0, n - 1);
  end = high_resolution_clock::now();
  cout << "Merge Sort : " << duration_cast<microseconds>(end - start).count()
       << " microseconds" << endl;

  start = high_resolution_clock::now();
  temp = arr;
  quickSort(temp, 0, n - 1);
  end = high_resolution_clock::now();
  cout << "Quick Sort : " << duration_cast<microseconds>(end - start).count()
       << " microseconds" << endl;

  return 0;
}