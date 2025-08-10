#include <iostream>
using namespace std;

void createArray(int arr[], int &n) {
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void displayArray(int arr[], int n) {
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement(int arr[], int &n) {
    int pos, val;
    cout << "Enter position and value: ";
    cin >> pos >> val;
    if (pos < 0 || pos > n) {
        cout << "Invalid position" << endl;
        return;
    }
    for (int i = n; i > pos; i--){
        arr[i] = arr[i-1];
    }
    arr[pos] = val;
    n++;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void deleteElement(int arr[], int &n) {
    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;
    if (pos < 0 || pos >= n) {
        cout << "Invalid position" << endl;
        return;
    }
    for (int i = pos; i < n-1; i++) arr[i] = arr[i+1];
    n--;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void linearSearch(int arr[], int n) {
    int key;
    cout << "Enter value to search: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Found at index " << i << endl;
            return;
        }
    }
    cout << "Not found" << endl;
}

int main() {
    int arr[100], n, choice;
    cout << "enter size of array : " << endl;
    cin >> n;

    createArray(arr, n);

        cout << "1..DISPLAY\n2.INSERT\n3.DELETE\n4.LINEAR SEARCH" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
             createArray(arr, n);
            case 1: displayArray(arr, n); break;
            case 2: insertElement(arr, n); break;
            case 3: deleteElement(arr, n); break;
            case 4: linearSearch(arr, n); break;
            default: cout << "Invalid choice" << endl;
        }
    return 0;
}
