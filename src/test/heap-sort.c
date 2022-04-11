#include "test/heap-sort.h"


/**
 * @brief Heapifies the array
 * 
 * @param array The array we want to heapify
 * @param size The size of the array
 * @param index The index of the array we want to heapify
 */
void heapify(int *array, int size, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < size && array[left] > array[largest]) {
        largest = left;
    }

    if (right < size && array[right] > array[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(array, index, largest);
        heapify(array, size, largest);
    }
}

/**
 * @brief Heap sorts the array
 * 
 * @param array The array to sort
 * @param size The size of the array we are sorting
 */
void heap_sort(int *array, int size) {
  // Build heap
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(array, size, i);
  }

  // Sort
  for (int i = size - 1; i >= 0; i--) {
    swap(array, 0, i);
    heapify(array, i, 0);
  }
}
