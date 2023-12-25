//write a c++ program to search  an element from a list. 
//give user the option to perform linear or binary search . use template function.  




#include <iostream>

template <typename T>
int linearSearch(const T arr[], int size, const T& target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i;  // Return the index if the element is found
        }
    }
    return -1;  // Return -1 if the element is not found
}

template <typename T>
int binarySearch(const T arr[], int size, const T& target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;  // Return the index if the element is found
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;  // Return -1 if the element is not found
}

int main() {
    const int intList[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const double doubleList[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0};

    int choice;
    std::cout << "Choose the type of search:\n";
    std::cout << "1. Linear Search\n";
    std::cout << "2. Binary Search\n";
    std::cout << "Enter your choice (1 or 2): ";
    std::cin >> choice;

    if (choice == 1) {
        int target;
        std::cout << "Enter the element to search: ";
        std::cin >> target;

        int result = linearSearch(intList, sizeof(intList) / sizeof(intList[0]), target);

        if (result != -1) {
            std::cout << "Element found at index: " << result << std::endl;
        } else {
            std::cout << "Element not found in the list.\n";
        }
    } else if (choice == 2) {
        double target;
        std::cout << "Enter the element to search: ";
        std::cin >> target;

        // Note: Binary search requires the list to be sorted
        int size = sizeof(doubleList) / sizeof(doubleList[0]);
        double sortedDoubleList[size];
        std::copy(doubleList, doubleList + size, sortedDoubleList);
        std::sort(sortedDoubleList, sortedDoubleList + size);

        int result = binarySearch(sortedDoubleList, size, target);

        if (result != -1) {
            std::cout << "Element found at index: " << result << std::endl;
        } else {
            std::cout << "Element not found in the list.\n";
        }
    } else {
        std::cout << "Invalid choice. Please enter 1 or 2.\n";
    }

    return 0;
}
