//Черепанов А.В.
#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <functional>




// Шаблон функции для измерения времени выполнения 
template <typename Func>                // Функция measureTime используется для измерения времени выполнения другой функции.
double measureTime(Func func) {         // Она принимает функцию в качестве аргумента и возвращает время выполнения этой функции в секундах.
    clock_t start = clock();
    func();
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}

// Шаблон функции создания массива заданного размера, заполненного случайными значениями в заданном интервале
template <typename T>
T* createRandomArray(size_t size, T min, T max) {        
    T* arr = new T[size];                              // Функция createRandomArray создает массив заданного размера,
    for (size_t i = 0; i < size; ++i) {
                                                       //заполненный случайными значениями в заданном интервале.Она принимает размер массива,
        arr[i] = min + rand() % (max - min + 1);       //минимальное и максимальное значения в качестве аргументов и возвращает указатель на созданный массив.
    }
    return arr;
}

// Шаблон функции заполнения массива случайными числами,  монотонно возрастающими
template <typename T>
T* createIncreasingArray(size_t size, T start) {  // Функция createIncreasingArray создает массив заданного размера,
    T* arr = new T[size];                         // заполненный монотонно возрастающими случайными числами.
    for (size_t i = 0; i < size; ++i) {          // Она принимает размер массива и начальное значение в качестве аргументов и возвращает указатель на созданный массив.
        arr[i] = start++;
    }
    return arr;
}

// Шаблон функции вывода массива в файл
template <typename T>
void printArrayToFile(const T* arr, size_t size, const std::string& filename) {
    std::ofstream file(filename);                      // Функция printArrayToFile выводит массив в файл.
    if (file.is_open()) {                              // Она принимает указатель на массив, размер массива и имя файла в качестве аргументов.
        for (size_t i = 0; i < size; ++i) {
            file << arr[i] << " ";
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file" << std::endl;
    }
}

// Шаблон функции проверки, отсортирован ли массив
template <typename T>
bool isArraySorted(const T* arr, size_t size) {   // Функция isArraySorted проверяет, отсортирован ли массив.
    for (size_t i = 1; i < size; ++i) {           // Она принимает указатель на массив и размер массива в качестве аргументов и возвращает true,
        if (arr[i] < arr[i - 1]) {                //  если массив отсортирован, и false в противном случае.
            return false;
        }
    }
    return true;
}

// Шаблон функции последовательного поиска значения в массиве
template <typename T>
size_t sequentialSearch(const T* arr, size_t size, const T& key) {  // Функция sequentialSearch выполняет последовательный поиск значения в массиве.
    for (size_t i = 0; i < size; ++i) {               //  Она принимает указатель на массив, размер массива и искомое значение в качестве аргументов
        if (arr[i] == key) {                          //  и возвращает индекс элемента, если он найден, или размер массива, если элемент не найден.
            return i;
        }
    }
    return size; // если элемент не найден
}

// Бонус: шаблон функции последовательного поиска с произвольной функцией
template <typename T, typename F>
size_t sequentialSearchCustom(const T* arr, size_t size, F func) { 
    for (size_t i = 0; i < size; ++i) {   // Функция sequentialSearchCustom выполняет последовательный поиск значения в массиве
        if (func(arr[i])) {               //  с использованием произвольной функции. Она принимает указатель на массив, размер массива,
            return i;                     //  функцию и искомое значение в качестве аргументов и возвращает индекс элемента,
        }                                 //  если он найден, или размер массива, если элемент не найден.
    }
    return size; // если элемент не найден
}


