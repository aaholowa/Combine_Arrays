#include <iostream>
using namespace std;

// function prototypes
void print_array(const int *const arr, size_t size);
int *combine_array(int *arr1, size_t size1, int *arr2, size_t size2);

int main() {

    // arrays
    int arr1[]{1, 2, 3, 4, 5};
    int arr2[]{10, 20, 30};

    // size of arrays
    size_t size1 = sizeof(arr1) / (sizeof(arr1[0]));
    size_t size2 = sizeof(arr2) / (sizeof(arr2[0]));
    size_t size_combined = size1 * size2;

    // display array 1
    cout << "Array 1: ";
    print_array(arr1,size1);

    // display array 2
    cout << "Array 2: ";
    print_array(arr2,size2);

    // display result of the combined array
    int *combined {nullptr};
    cout << "Result: ";
    combined = combine_array(arr1,size1,arr2,size2);
    print_array(combined, size_combined);
    delete [] combined; // free storage
}

// function definitions

void print_array(const int *const arr, size_t size){
    cout << "[ ";
    for(size_t i {0}; i < size; ++i){
        cout << arr[i] << ' ';
    }
    cout << "]" << endl;
}

int *combine_array(int *arr1, size_t size1, int *arr2, size_t size2){
    int *combined {nullptr};
    size_t combined_size = size1 * size2;
    combined = new int[combined_size]; // allocate array on the heap
    int k {0}; // variable to move along the new array

    for(size_t i {0}; i < size2; ++i){
        for(size_t j {0}; j < size1; ++j){
            *(combined + k) = arr1[j] * arr2[i]; // pointer arithmetic
            ++k; // move to next location in memory
        }
    }
    return combined;
}