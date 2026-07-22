#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == key)
      return i;
  }

  return -1;
}

int binarySearch(int arr[], int n, int key) {
  int low = 0;
  int high = n - 1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[mid] == key)
      return mid;

    else if (arr[mid] < key)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

int main() {
  int n, key;

  cout << "Enter number of elements: ";
  cin >> n;

  int arr[n];

  cout << "Enter elements: ";
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << "Enter element to search: ";
  cin >> key;

  int index;

  index = linearSearch(arr, n, key);

  if (index != -1)
    cout << "Linear Search: Element found at index " << index << endl;
  else
    cout << "Linear Search: Element not found" << endl;

  index = binarySearch(arr, n, key);

  if (index != -1)
    cout << "Binary Search: Element found at index " << index << endl;
  else
    cout << "Binary Search: Element not found" << endl;

  return 0;
}