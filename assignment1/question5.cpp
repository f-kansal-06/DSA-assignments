#include <iostream>
using namespace std;

int main() {
    int a[100][100], r, c;
    cout << "Enter rows and columns: ";
    cin >> r >> c;
    cout << "Enter matrix:" << endl;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];

    for (int i = 0; i < r; i++) {
        int sumRow = 0;
        for (int j = 0; j < c; j++) {
        sumRow += a[i][j];
        }
        cout << "Sum of row " << i << ": " << sumRow << endl;
    }

    for (int j = 0; j < c; j++) {
        int sumCol = 0;
        for (int i = 0; i < r; i++){
            sumCol += a[i][j];
        }
        cout << "Sum of col " << j << ": " << sumCol << endl;
    }
}
