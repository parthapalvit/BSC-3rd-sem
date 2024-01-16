//Write a c++ program to convert the Sparse Matrix into non-zero form and vice-versa. 

#include <iostream>

const int MAX_SIZE = 100;

class SparseMatrix {
private:
    int row, col;
    int nonZeroCount;
    int sparseMatrix[MAX_SIZE][3];

public:
    // Constructor to initialize the sparse matrix
    SparseMatrix(int r, int c) : row(r), col(c), nonZeroCount(0) {
        if (row > MAX_SIZE || col > MAX_SIZE) {
            std::cerr << "Error: Matrix size exceeds the maximum limit." << std::endl;
            exit(1);
        }

        // Initializing the sparse matrix
        for (int i = 0; i < MAX_SIZE; ++i) {
            for (int j = 0; j < 3; ++j) {
                sparseMatrix[i][j] = 0;
            }
        }
    }

    // Function to insert a non-zero element into the sparse matrix
    void insert(int element, int rowIndex, int colIndex) {
        if (rowIndex < 0 || rowIndex >= row || colIndex < 0 || colIndex >= col) {
            std::cerr << "Error: Index out of bounds." << std::endl;
            return;
        }

        if (element != 0) {
            sparseMatrix[nonZeroCount][0] = element;
            sparseMatrix[nonZeroCount][1] = rowIndex;
            sparseMatrix[nonZeroCount][2] = colIndex;
            nonZeroCount++;
        }
    }

    // Function to display the sparse matrix
    void displaySparseMatrix() const {
        std::cout << "Sparse Matrix:" << std::endl;
        for (int i = 0; i < nonZeroCount; ++i) {
            std::cout << sparseMatrix[i][0] << " ("
                      << sparseMatrix[i][1] << ", " << sparseMatrix[i][2] << ")" << std::endl;
        }
    }

    // Function to convert Sparse Matrix to Non-zero form
    void convertToNonZeroForm(int nonZeroMatrix[MAX_SIZE][MAX_SIZE]) const {
        for (int i = 0; i < MAX_SIZE; ++i) {
            for (int j = 0; j < MAX_SIZE; ++j) {
                nonZeroMatrix[i][j] = 0;
            }
        }

        for (int i = 0; i < nonZeroCount; ++i) {
            nonZeroMatrix[sparseMatrix[i][1]][sparseMatrix[i][2]] = sparseMatrix[i][0];
        }
    }

    // Function to convert Non-zero form to Sparse Matrix
    void convertToSparseMatrix(const int nonZeroMatrix[MAX_SIZE][MAX_SIZE]) {
        nonZeroCount = 0;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (nonZeroMatrix[i][j] != 0) {
                    sparseMatrix[nonZeroCount][0] = nonZeroMatrix[i][j];
                    sparseMatrix[nonZeroCount][1] = i;
                    sparseMatrix[nonZeroCount][2] = j;
                    nonZeroCount++;
                }
            }
        }
    }

    // Function to display the non-zero form matrix
    void displayNonZeroForm(const int nonZeroMatrix[MAX_SIZE][MAX_SIZE]) const {
        std::cout << "Non-Zero Form Matrix:" << std::endl;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                std::cout << nonZeroMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int row, col;

    // Input matrix size
    std::cout << "Enter the number of rows in the matrix: ";
    std::cin >> row;
    std::cout << "Enter the number of columns in the matrix: ";
    std::cin >> col;

    SparseMatrix sparseMatrix(row, col);

    // Input values for the sparse matrix
    std::cout << "Enter the elements of the sparse matrix:" << std::endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            int element;
            std::cout << "Element at position (" << i << ", " << j << "): ";
            std::cin >> element;
            sparseMatrix.insert(element, i, j);
        }
    }

    // Display the sparse matrix
    sparseMatrix.displaySparseMatrix();

    // Convert Sparse Matrix to Non-zero form
    int nonZeroMatrix[MAX_SIZE][MAX_SIZE];
    sparseMatrix.convertToNonZeroForm(nonZeroMatrix);

    // Display the non-zero form matrix
    sparseMatrix.displayNonZeroForm(nonZeroMatrix);

    // Convert Non-zero form to Sparse Matrix
    SparseMatrix newSparseMatrix(row, col);
    newSparseMatrix.convertToSparseMatrix(nonZeroMatrix);

    // Display the resulting sparse matrix
    newSparseMatrix.displaySparseMatrix();

    return 0;
}
