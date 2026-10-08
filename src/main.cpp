#include "array_ops.h"
#include <iostream>

int main() {
    int* arr = nullptr;
    std::size_t size = 0;
    int choice = 0;

    while (true) {
        std::cout << "\n=== MENU ===\n";
        std::cout << "1. Create array\n";
        std::cout << "2. Resize array\n";
        std::cout << "3. Insert element\n";
        std::cout << "4. Remove element\n";
        std::cout << "5. Sort array\n";
        std::cout << "6. Rotate left\n";
        std::cout << "7. Binary search\n";
        std::cout << "8. Print array\n";
        std::cout << "9. Delete array and Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 9) {
            array_delete(arr);
            size = 0;
            break;
        }

        switch (choice) {
            case 1: {
                if (arr != nullptr) array_delete(arr);
                std::cout << "Enter size: ";
                std::cin >> size;
                arr = array_create(size);
                for (std::size_t i = 0; i < size; ++i) {
                    std::cout << "arr[" << i << "] = ";
                    std::cin >> arr[i];
                }
                break;
            }
            case 2: {
                std::size_t new_size;
                std::cout << "Enter new size: ";
                std::cin >> new_size;
                arr = array_resize(arr, size, new_size);
                break;
            }
            case 3: {
                std::size_t pos;
                int value;
                std::cout << "Enter position to insert: ";
                std::cin >> pos;
                std::cout << "Enter value: ";
                std::cin >> value;
                arr = array_insert(arr, size, pos, value);
                break;
            }
            case 4: {
                std::size_t pos;
                std::cout << "Enter position to remove: ";
                std::cin >> pos;
                arr = array_remove(arr, size, pos);
                break;
            }
            case 5: {
                array_insertion_sort(arr, size);
                std::cout << "Sorted!\n";
                break;
            }
            case 6: {
                std::size_t k;
                std::cout << "Enter positions to rotate: ";
                std::cin >> k;
                array_rotate_left(arr, size, k);
                array_print(arr, size);
                break;
            }
            case 7: {
                int target;
                std::size_t out_index = 0;
                std::cout << "Enter value to search: ";
                std::cin >> target;
                if (array_binary_search(arr, size, target, out_index)) {
                    std::cout << "Found at index: " << out_index << "\n";
                } else {
                    std::cout << "Not found\n";
                }
                break;
            }
            case 8: {
                std::cout << "Current array: ";
                array_print(arr, size);
                break;
            }
            default: {
                std::cout << "Invalid choice!\n";
                break;
            }
        }
    }

    return 0;
}
