//Write a program to implement Symmetric Matrix using one-dimensional array

#include <iostream>

using namespace std;

class SymmetricMatrix {
private:
    int n; // Order of the matrix
    int *arr; // One-dimensional array to store the elements

public:
    // Constructor to initialize the matrix
    SymmetricMatrix(int size) {
        n = size;
        arr = new int[n * (n + 1) / 2]; // Formula to calculate the size of a symmetric matrix
    }

    // Function to set the value at a specific row and column
    void setValue(int row, int col, int value) {
        if (row <= n && col <= n) {
            // Only set the value if it is in the lower triangular part or on the diagonal
            if (row >= col) {
                arr[row * (row - 1) / 2 + col - 1] = value;
            } else {
                arr[col * (col - 1) / 2 + row - 1] = value;
            }
        } else {
            cout << "Invalid operation. Please set values within the matrix dimensions." << endl;
        }
    }

    // Function to get the value at a specific row and column
    int getValue(int row, int col) {
        if (row <= n && col <= n) {
            // Return the value based on the lower triangular part or the diagonal
            if (row >= col) {
                return arr[row * (row - 1) / 2 + col - 1];
            } else {
                return arr[col * (col - 1) / 2 + row - 1];
            }
        } else {
            cout << "Invalid operation. Please access values within the matrix dimensions." << endl;
            return -1; // Return an invalid value
        }
    }

    // Function to display the matrix
    void displayMatrix() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << getValue(i, j) << " ";
            }
            cout << endl;
        }
    }

    // Destructor to free the allocated memory
    ~SymmetricMatrix() {
        delete[] arr;
    }
};

int main() {
    int size;
    
    cout << "Enter the order of the matrix: ";
    cin >> size;

    SymmetricMatrix matrix(size);

    cout << "Enter the elements of the symmetric matrix:" << endl;
    for (int i = 1; i <= size; i++) {
        for (int j = i; j <= size; j++) {
            int value;
            cout << "Enter the value at position (" << i << ", " << j << "): ";
            cin >> value;
            matrix.setValue(i, j, value);
        }
    }

    cout << "\nSymmetric Matrix:" << endl;
    matrix.displayMatrix();

    return 0;
}
