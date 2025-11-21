#include <iostream>
using namespace std;

const int MAXN = 100;
void inputArray(int arr[], int &n) {
    cout << "Enter number of elements (<= " << MAXN << "): ";
    cin >> n;
    if (n > MAXN) {
        cout << "Too many elements! Setting n = " << MAXN << endl;
        n = MAXN;
    }
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void copyArray(int dest[], int src[], int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

// ---------- a) Selection Sort ----------
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// ---------- b) Insertion Sort ----------
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];    
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;  
    }
}

// ---------- c) Bubble Sort ----------
void bubbleSort(int arr[], int n) {
    for (int pass = 0; pass < n - 1; pass++) {
        bool swapped = false;   
        for (int i = 0; i < n - 1 - pass; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;   
    }
}

// ---------- d) Merge Sort (recursive) ----------
void mergeArrays(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  
    int n2 = right - mid;      

    int L[MAXN], R[MAXN];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        mergeArrays(arr, left, mid, right);
    }
}

// ---------- e) Quick Sort (recursive) ----------
int partitionArray(int arr[], int left, int right) {
    int pivot = arr[right];    
    int i = left - 1;           

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;

    return i + 1;               
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pi = partitionArray(arr, left, right);
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}

// ---------- 2) Improved Selection Sort (min & max each pass) ----------
void improvedSelectionSort(int arr[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int minIndex = left;
        int maxIndex = right;

        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }

        int temp = arr[left];
        arr[left] = arr[minIndex];
        arr[minIndex] = temp;

        if (maxIndex == left) {
            maxIndex = minIndex;
        }

        temp = arr[right];
        arr[right] = arr[maxIndex];
        arr[maxIndex] = temp;

        left++;
        right--;
    }
}

int main() {
    int original[MAXN];
    int arr[MAXN];
    int n;

    inputArray(original, n);

    int choice;
    do {
        cout << "\nOriginal array: ";
        printArray(original, n);

        cout << "\n--- Sorting Menu ---\n";
        cout << "1. Selection Sort\n";
        cout << "2. Insertion Sort\n";
        cout << "3. Bubble Sort\n";
        cout << "4. Merge Sort (recursive)\n";
        cout << "5. Quick Sort (recursive)\n";
        cout << "6. Improved Selection Sort (min & max each pass)\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        copyArray(arr, original, n);

        switch (choice) {
            case 1:
                selectionSort(arr, n);
                cout << "Array after Selection Sort: ";
                printArray(arr, n);
                break;
            case 2:
                insertionSort(arr, n);
                cout << "Array after Insertion Sort: ";
                printArray(arr, n);
                break;
            case 3:
                bubbleSort(arr, n);
                cout << "Array after Bubble Sort: ";
                printArray(arr, n);
                break;
            case 4:
                mergeSort(arr, 0, n - 1);
                cout << "Array after Merge Sort: ";
                printArray(arr, n);
                break;
            case 5:
                quickSort(arr, 0, n - 1);
                cout << "Array after Quick Sort: ";
                printArray(arr, n);
                break;
            case 6:
                improvedSelectionSort(arr, n);
                cout << "Array after Improved Selection Sort: ";
                printArray(arr, n);
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
