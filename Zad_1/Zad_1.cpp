//  Черепанов А.В.

#include <iostream>
#include "utility.h"


int main() {

    const size_t SIZE = 1000000; // Размер массива
    const int MIN_VAL = 1; // Минимальное значение элемента массива
    const int MAX_VAL = 100; // Максимальное значение элемента массива


    // Создание массива заданного размера, заполненного случайными значениями в заданном интервале
    int* randArray = createRandomArray<int>(SIZE, MIN_VAL, MAX_VAL);


    // Создание массива с монотонно возрастающими значениями
    int* incArray = createIncreasingArray<int>(SIZE, 1);



    // Вывод массива на экран
    printArrayToFile(randArray, SIZE, "random_array.txt");
    printArrayToFile(incArray, SIZE, "increasing_array.txt");



    // Проверка, отсортирован ли массив
    assert(!isArraySorted(randArray, SIZE)); // Проверка, не отсортирован ли массив randArray
    assert(isArraySorted(incArray, SIZE)); // Проверка, отсортирован ли массив incArray


    // Поиск значения в массиве
    size_t index = sequentialSearch(randArray, SIZE, 50); // Поиск значения 50 в массиве randArray
    if (index != SIZE) { // Если значение найдено
        std::cout << "Element found at index: " << index << std::endl; // Вывод индекса найденного элемента

    }
    else { // Если значение не найдено
        std::cout << "Element not found" << std::endl; // Вывод сообщения о том, что значение не найдено
    }

}
