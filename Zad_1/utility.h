//��������� �.�.
#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <functional>




// ������ ������� ��� ��������� ������� ���������� 
template <typename Func>                // ������� measureTime ������������ ��� ��������� ������� ���������� ������ �������.
double measureTime(Func func) {         // ��� ��������� ������� � �������� ��������� � ���������� ����� ���������� ���� ������� � ��������.
    clock_t start = clock();
    func();
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}

// ������ ������� �������� ������� ��������� �������, ������������ ���������� ���������� � �������� ���������
template <typename T>
T* createRandomArray(size_t size, T min, T max) {        
    T* arr = new T[size];                              // ������� createRandomArray ������� ������ ��������� �������,
    for (size_t i = 0; i < size; ++i) {
                                                       //����������� ���������� ���������� � �������� ���������.��� ��������� ������ �������,
        arr[i] = min + rand() % (max - min + 1);       //����������� � ������������ �������� � �������� ���������� � ���������� ��������� �� ��������� ������.
    }
    return arr;
}

// ������ ������� ���������� ������� ���������� �������,  ��������� �������������
template <typename T>
T* createIncreasingArray(size_t size, T start) {  // ������� createIncreasingArray ������� ������ ��������� �������,
    T* arr = new T[size];                         // ����������� ��������� ������������� ���������� �������.
    for (size_t i = 0; i < size; ++i) {          // ��� ��������� ������ ������� � ��������� �������� � �������� ���������� � ���������� ��������� �� ��������� ������.
        arr[i] = start++;
    }
    return arr;
}

// ������ ������� ������ ������� � ����
template <typename T>
void printArrayToFile(const T* arr, size_t size, const std::string& filename) {
    std::ofstream file(filename);                      // ������� printArrayToFile ������� ������ � ����.
    if (file.is_open()) {                              // ��� ��������� ��������� �� ������, ������ ������� � ��� ����� � �������� ����������.
        for (size_t i = 0; i < size; ++i) {
            file << arr[i] << " ";
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file" << std::endl;
    }
}

// ������ ������� ��������, ������������ �� ������
template <typename T>
bool isArraySorted(const T* arr, size_t size) {   // ������� isArraySorted ���������, ������������ �� ������.
    for (size_t i = 1; i < size; ++i) {           // ��� ��������� ��������� �� ������ � ������ ������� � �������� ���������� � ���������� true,
        if (arr[i] < arr[i - 1]) {                //  ���� ������ ������������, � false � ��������� ������.
            return false;
        }
    }
    return true;
}

// ������ ������� ����������������� ������ �������� � �������
template <typename T>
size_t sequentialSearch(const T* arr, size_t size, const T& key) {  // ������� sequentialSearch ��������� ���������������� ����� �������� � �������.
    for (size_t i = 0; i < size; ++i) {               //  ��� ��������� ��������� �� ������, ������ ������� � ������� �������� � �������� ����������
        if (arr[i] == key) {                          //  � ���������� ������ ��������, ���� �� ������, ��� ������ �������, ���� ������� �� ������.
            return i;
        }
    }
    return size; // ���� ������� �� ������
}

// �����: ������ ������� ����������������� ������ � ������������ ��������
template <typename T, typename F>
size_t sequentialSearchCustom(const T* arr, size_t size, F func) { 
    for (size_t i = 0; i < size; ++i) {   // ������� sequentialSearchCustom ��������� ���������������� ����� �������� � �������
        if (func(arr[i])) {               //  � �������������� ������������ �������. ��� ��������� ��������� �� ������, ������ �������,
            return i;                     //  ������� � ������� �������� � �������� ���������� � ���������� ������ ��������,
        }                                 //  ���� �� ������, ��� ������ �������, ���� ������� �� ������.
    }
    return size; // ���� ������� �� ������
}


