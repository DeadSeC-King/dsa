#include <stdlib.h>

typedef struct {
    int *maxHeap;
    int *minHeap;
    int maxSize;
    int minSize;
} MedianFinder;

void swap(int *a,int *b){
    int t=*a; *a=*b; *b=t;
}

/* ---------- Max Heap ---------- */
void maxHeapUp(int *heap,int i){
    while(i>0){
        int p=(i-1)/2;
        if(heap[p] >= heap[i]) break;
        swap(&heap[p],&heap[i]);
        i=p;
    }
}

void maxHeapDown(int *heap,int size,int i){
    while(1){
        int largest=i;
        int l=2*i+1;
        int r=2*i+2;

        if(l<size && heap[l]>heap[largest]) largest=l;
        if(r<size && heap[r]>heap[largest]) largest=r;

        if(largest==i) break;

        swap(&heap[i],&heap[largest]);
        i=largest;
    }
}

/* ---------- Min Heap ---------- */
void minHeapUp(int *heap,int i){
    while(i>0){
        int p=(i-1)/2;
        if(heap[p] <= heap[i]) break;
        swap(&heap[p],&heap[i]);
        i=p;
    }
}

void minHeapDown(int *heap,int size,int i){
    while(1){
        int smallest=i;
        int l=2*i+1;
        int r=2*i+2;

        if(l<size && heap[l]<heap[smallest]) smallest=l;
        if(r<size && heap[r]<heap[smallest]) smallest=r;

        if(smallest==i) break;

        swap(&heap[i],&heap[smallest]);
        i=smallest;
    }
}

/* ---------- Core ---------- */

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = malloc(sizeof(MedianFinder));

    obj->maxHeap = malloc(sizeof(int)*100000);
    obj->minHeap = malloc(sizeof(int)*100000);

    obj->maxSize = 0;
    obj->minSize = 0;

    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {

    /* insert to maxHeap */
    obj->maxHeap[obj->maxSize] = num;
    maxHeapUp(obj->maxHeap,obj->maxSize);
    obj->maxSize++;

    /* move max → minHeap */
    int val=obj->maxHeap[0];
    obj->maxHeap[0]=obj->maxHeap[--obj->maxSize];
    maxHeapDown(obj->maxHeap,obj->maxSize,0);

    obj->minHeap[obj->minSize]=val;
    minHeapUp(obj->minHeap,obj->minSize);
    obj->minSize++;

    /* balance heaps */
    if(obj->minSize > obj->maxSize){
        val=obj->minHeap[0];
        obj->minHeap[0]=obj->minHeap[--obj->minSize];
        minHeapDown(obj->minHeap,obj->minSize,0);

        obj->maxHeap[obj->maxSize]=val;
        maxHeapUp(obj->maxHeap,obj->maxSize);
        obj->maxSize++;
    }
}

double medianFinderFindMedian(MedianFinder* obj) {

    if(obj->maxSize > obj->minSize)
        return obj->maxHeap[0];

    return (obj->maxHeap[0] + obj->minHeap[0]) / 2.0;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->maxHeap);
    free(obj->minHeap);
    free(obj);
}