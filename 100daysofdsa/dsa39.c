//Implement a Min Heap using an array where the smallest element is always at the root.
#include <stdio.h>
#define MAX_SIZE 100
int minHeap[MAX_SIZE];
int size = 0;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insert(int value) {
    if (size == MAX_SIZE) {
        printf("Heap is full!\n");
        return;
    }
    minHeap[size] = value;
    size++;
    int i = size - 1;
    while (i != 0 && minHeap[i] < minHeap[(i - 1) / 2]) {
        swap(&minHeap[i], &minHeap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
void minHeapify(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && minHeap[left] < minHeap[smallest]) {
        smallest = left;
    }
    if (right < size && minHeap[right] < minHeap[smallest]) {
        smallest = right;
    }
    if (smallest != i) {
        swap(&minHeap[i], &minHeap[smallest]);
        minHeapify(smallest);
    }
}
int extractMin() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return -1;
    }
    int min = minHeap[0];
    minHeap[0] = minHeap[size - 1];
    size--;
    minHeapify(0);
    return min;
}
int main() {
    insert(5);
    insert(3);
    insert(8);
    insert(1);
    printf("Minimum element: %d\n", extractMin());
    printf("Minimum element: %d\n", extractMin());
    return 0;
}
