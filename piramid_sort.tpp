#include "piramid_sort.hpp"

/**
 * @brief Функция для преобразования поддерева в кучу
 * 
 * @tparam K Тип сортируемых данных
 * @param arr Массив данных
 * @param n Размер кучи
 * @param i Индекс корня
 */
template<typename K>
void SubtreeToHeap(std::vector<K>& arr, int n, int i) {
    
    int largest = i; // Корень
    int left = 2 * i + 1; // Левый потомок
    int right = 2 * i + 2; // Правый потомок
    
    // Сохраняем индекс наибольшего элемента
    // Если левый потомок больше корня
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Если правый потомок больше, чем наибольший элемент на данный момент
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Если наибольший элемент не корень
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Преобразуем в кучу поддерево
        SubtreeToHeap<K>(arr, n, largest);
    }
}

/**
 * @brief Функция пирамидальной сортировки
 * 
 * @tparam T Тип сортируемых данных
 * @param arr Массив чисел
 */
template<typename T>
void HeapSort(std::vector<T>& arr) {
    int n = arr.size();

    // Построение кучи
    for (int i = n / 2 - 1; i >= 0; i--)
        SubtreeToHeap<T>(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        // Перемещение текущего корня в конец
        std::swap(arr[0], arr[i]);

        // Преобразуем подмассив в кучу
        SubtreeToHeap<T>(arr, i, 0);
    }
}