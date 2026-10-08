#include "array_ops.h"
#include <iostream>

int* array_create(std::size_t size){
    if (size == 0) return nullptr;
    return new int[size];
}

void array_delete(int*& arr) {
    delete[] arr;
    arr = nullptr;
}

int* array_resize(int* arr, std::size_t& size, std::size_t new_size) {
    if (new_size == 0) {
        array_delete(arr);
        size = 0;
        return nullptr;
    }

    int* new_arr = new int[new_size];
    std::size_t to_copy;
    if (size < new_size) {
        to_copy = size;
    } else {
        to_copy = new_size;
    }

    for (std::size_t i = 0; i < to_copy; ++i) {
        new_arr[i] = arr[i];
    }
    
    array_delete(arr);

    size = new_size;
    
    return new_arr;
}

int* array_insert(int* arr, std::size_t& size, std::size_t pos, int value) {
    if (pos > size) pos = size;
    int* new_arr = new int[size + 1];
    for (std::size_t i = 0; i < pos; ++i) new_arr[i] = arr[i];
    new_arr[pos] = value;
    for (std::size_t i = pos; i < size; ++i) new_arr[i + 1] = arr[i];
    size++;
    array_delete(arr);
    return new_arr;
}


int* array_remove(int* arr, std::size_t& size, std::size_t pos) {
    if (size == 0 || pos >= size) return arr;
    if (size == 1) {
        size = 0;
        array_delete(arr);
        return nullptr;
    }
    int* new_arr = new int[size - 1];
    for (std::size_t i = 0; i < pos; ++i) new_arr[i] = arr[i];
    for (std::size_t i = pos + 1; i < size; ++i) new_arr[i - 1] = arr[i];
    size--;
    array_delete(arr);
    return new_arr;
}

void array_print(const int* arr, std::size_t size) {
    if (arr == nullptr || size == 0) {
        std::cout << "Array is empty \n";
        return;
    }
    for (std::size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}




void array_insertion_sort(int* arr, std::size_t size) {
    // arr = [40, 10, 30, 20]
    if (arr == nullptr || size < 2) {
        return;
    }
    for (std::size_t i = 1; i < size; ++i) {
        int key = arr[i];
        std::size_t j = i;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }

        arr[j] = key;
    }
}


static void array_reverse_sub(int* arr, std::size_t start, std::size_t end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}


void array_rotate_left(int* arr, std::size_t size, std::size_t k) {
    if (arr == nullptr || size < 2) {
        return;
    }
    k = k % size;

    if (k == 0) {
        return;
    }

    array_reverse_sub(arr, 0, k - 1);
    array_reverse_sub(arr, k, size - 1);
    array_reverse_sub(arr, 0, size - 1);
}


bool array_binary_search(const int* arr, std::size_t size, int target, std::size_t& out_index) {
    if (!arr || size == 0) {
        return false;
    }

    long long low = 0;
    long long high = static_cast<long long>(size) - 1;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            out_index = static_cast<std::size_t>(mid); 
            return true;
        }

        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return false; 
}
