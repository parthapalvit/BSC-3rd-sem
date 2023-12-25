//  write a c++ program using templete to sort a list of elememnts .
// give user the option to perform sorting using insertion sort , bubble sort or selection sort .  

#include <iostream>

template <typename T>
void insertionSort(T arr[], int size) {
    for (int i = 1; i < size; ++i) {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

template <typename T>
void bubbleSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;

        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap arr[i] and arr[minIndex]
        T temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

template <typename T>
void printArray(const T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int size = 5;  // Adjust the size based on your list
    int intList[size] = {5, 2, 8, 1, 3};
    double doubleList[size] = {5.5, 2.2, 8.8, 1.1, 3.3};

    int choice;
    std::cout << "Choose the type of sorting:\n";
    std::cout << "1. Insertion Sort\n";
    std::cout << "2. Bubble Sort\n";
    std::cout << "3. Selection Sort\n";
    std::cout << "Enter your choice (1, 2, or 3): ";
    std::cin >> choice;

    std::cout << "Original array: ";
    printArray(intList, size);

    switch (choice) {
        case 1:
            insertionSort(intList, size);
            break;
        case 2:
            bubbleSort(intList, size);
            break;
        case 3:
            selectionSort(intList, size);
            break;
        default:
            std::cout << "Invalid choice. Exiting.\n";
            return 1;
    }

    std::cout << "Sorted array: ";
    printArray(intList, size);

    // Similar process for doubleList if needed

    return 0;
}
