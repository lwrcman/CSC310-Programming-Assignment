#include "test/heap-sort.h"


/**
 * @brief Sets the array to 
 * 
 * @param array The array we want to heapify
 * @param size The size of the array
 * @param index The index of the array we want to heapify
 */
void heapify(int *data, int length, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < length && data[left] > data[largest]) {
        largest = left;
    }

    if (right < length && data[right] > data[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(data, index, largest);
        heapify(data, length, largest);
    }
}

/**
 * @brief Heap sorts the array
 * 
 * @param array The array to sort
 * @param size The size of the array we are sorting
 */
void heap_sort(int *data, int length) {
  // Build heap
  for (int i = length / 2 - 1; i >= 0; i--) {
    heapify(data, length, i);
  }

  // Sort
  for (int i = length - 1; i >= 0; i--) {
    swap(data, 0, i);
    heapify(data, i, 0);
  }
}
