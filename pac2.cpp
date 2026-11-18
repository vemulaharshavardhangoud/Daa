
#include <iostream>
using namespace std;

// Linear Search Function
int linearSearch(int arr[], int n, int key) {

    // Check each element one by one
    for (int i = 0; i < n; i++) {

        if (arr[i] == key)
            return i;  // Return index if found
    }

    return -1;  // Element not found
}

// Binary Search Function
int binarySearch(int arr[], int n, int key) {

    int low = 0;
    int high = n - 1;

    // Repeat until search range becomes empty
    while (low <= high) {

        // Find middle index
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;  // Element found

        // Search in right half
        else if (arr[mid] < key)
            low = mid + 1;

        // Search in left half
        else
            high = mid - 1;
    }

    return -1;  // Element not found
}

int main() {

    int n, key;

    // Get array size
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    // Read array elements
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Get search element
    cout << "Enter element to search: ";
    cin >> key;

    int index;

    // Perform Linear Search
    index = linearSearch(arr, n, key);

    if (index != -1)
        cout << "Linear Search: Element found at index "
             << index << endl;
    else
        cout << "Linear Search: Element not found" << endl;

    // Perform Binary Search
    index = binarySearch(arr, n, key);

    if (index != -1)
        cout << "Binary Search: Element found at index "
             << index << endl;
    else
        cout << "Binary Search: Element not found" << endl;

    return 0;
}
