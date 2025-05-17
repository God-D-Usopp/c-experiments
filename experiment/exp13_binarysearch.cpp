#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int n, key;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter sorted elements:\n";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << "Enter key to search: ";
    cin >> key;

    int result = binarySearch(arr, n, key);
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found.\n";
    return 0;
}
/*
binary search that uses quick sort
#include <iostream>
using namespace std;

// Quick Sort Functions
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];  // pivot element
        int i = low - 1;

        for (int j = low; j <= high - 1; ++j) {
            if (arr[j] < pivot) {
                ++i;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Binary Search Function
int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Main Function
int main() {
    int n, key;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    // Sorting the array using Quick Sort
    quickSort(arr, 0, n - 1);

    // Display sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Input target key
    cout << "Enter the element to search for: ";
    cin >> key;

    // Perform Binary Search
    int result = binarySearch(arr, n, key);
    if (result != -1)
        cout << "Element found at index " << result << " (0-based index)" << endl;
    else
        cout << "Element not found in the array.\n";

    return 0;
}
*/
