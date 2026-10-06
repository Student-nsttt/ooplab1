#include <gtest/gtest.h>
#include "array_ops.h"

TEST(ArrayCreateTest, ShouldAllocateMemoryCorrectly) {
    int* ptr = array_create(5);
    EXPECT_NE(ptr, nullptr) << "функция вернула пустой указатель вместо массива!";
    delete[] ptr;
}

// 2. создание массива
TEST(Variant3Tests, CreateValid) {
    int* arr = array_create(5);
    EXPECT_NE(arr, nullptr) << "адрес равен нулю, память не выделелась";
    array_delete(arr);
}

// 3. удаление обнуляет указатель
TEST(Variant3Tests, DeleteNull) {
    int* arr = array_create(5);
    array_delete(arr);
    EXPECT_EQ(arr, nullptr) << "функция удалила память, но забыла обнулить сам указатель";
}

// 4. изменение размера
TEST(Variant3Tests, Resize) {
    std::size_t size = 2;
    int* arr = array_create(size);
    arr[0] = 5; arr[1] = 6;
    arr = array_resize(arr, size, 4);
    size = 4;
    EXPECT_EQ(arr[0], 5) << "первый элемент потерялся или изменился после resize";
    EXPECT_EQ(arr[1], 6) << "второй элемент потерялся или изменился после resize";
    array_delete(arr);
}

// 5. вставка элемента
TEST(Variant3Tests, Insert) {
    std::size_t size = 2;
    int* arr = array_create(size);
    arr[0] = 10; arr[1] = 20;
    arr = array_insert(arr, size, 1, 15);
    EXPECT_EQ(size, 3) << "Функция вставила элемент но не увеличила размер до 3"; 
    EXPECT_EQ(arr[1], 15) << "2 элемент не равен 15";
    array_delete(arr);
}

// 6. удаление элемента
TEST(Variant3Tests, Remove) {
    std::size_t size = 3;
    int* arr = array_create(size);
    arr[0] = 10; arr[1] = 20; arr[2] = 30;
    arr = array_remove(arr, size, 1);
    EXPECT_EQ(size, 2) << "после удаления элемента массив остался такого же размера";
    array_delete(arr);
}

// 7. сортировка вставками
TEST(Variant3Tests, InsertionSort) {
    std::size_t size = 4;
    int* arr = array_create(size);
    arr[0] = 4; arr[1] = 2; arr[2] = 1; arr[3] = 3;
    array_insertion_sort(arr, size);
    EXPECT_EQ(arr[0], 1) << "Ошибка сортировки на индексе 0"; 
    EXPECT_EQ(arr[1], 2) << "Ошибка сортировки на индексе 1";
    EXPECT_EQ(arr[2], 3) << "Ошибка сортировки на индексе 2";
    EXPECT_EQ(arr[3], 4) << "Ошибка сортировки на индексе 3";
    array_delete(arr);
}

// 8. циклический сдвиг влево
TEST(Variant3Tests, RotateLeft) {
    std::size_t size = 4;
    int* arr = array_create(size);
    arr[0] = 1; arr[1] = 2; arr[2] = 3; arr[3] = 4;
    array_rotate_left(arr, size, 1); // arr = [2, 3, 4, 1]
    EXPECT_EQ(arr[0], 2) << "Ошибка сдвига"; 
    EXPECT_EQ(arr[1], 3) << "Ошибка сдвига";
    EXPECT_EQ(arr[2], 4) << "Ошибка сдвига";
    EXPECT_EQ(arr[3], 1) << "Ошибка сдвига";
    array_delete(arr);
}

// 9. Тест: бинарный поиск элемент найден
TEST(Variant3Tests, SearchSuccess) {
    std::size_t size = 3;
    int* arr = array_create(size);
    arr[0] = 10; arr[1] = 20; arr[2] = 30;
    std::size_t out_idx = 0;
    array_binary_search(arr, size, 20, out_idx);
    EXPECT_EQ(out_idx, 1) << "Ошибка: элемент 20 не на индексе 1";
    array_delete(arr);
}

// 10. Тест: бинарный поиск элемент не найден 
TEST(Variant3Tests, SearchFailure) {
    std::size_t size = 3;
    int* arr = array_create(size);
    arr[0] = 10; arr[1] = 20; arr[2] = 30;
    std::size_t out_idx = 0;
    EXPECT_FALSE(array_binary_search(arr, size, 99, out_idx)) << "Функция вернула true, хотя числа нет в массиве";
    array_delete(arr);
}

