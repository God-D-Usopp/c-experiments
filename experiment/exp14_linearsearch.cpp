#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == key)
            return i;  // return index if found
    }
    return -1;  // not found
}

int main() {
    int n, key;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << "Enter the element to search: ";
    cin >> key;

    int result = linearSearch(arr, n, key);
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found in the array.\n";

    return 0;
}
