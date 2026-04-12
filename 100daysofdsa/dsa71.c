//Implement a hash table using quadratic probing with formula:
//h(k, i) = (h(k) + i*i) % m
#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
typedef struct {
    int key;
    int value;
    int isOccupied; // 0 for empty, 1 for occupied
} HashEntry;
typedef struct {
    HashEntry table[TABLE_SIZE];
} HashTable;
void initHashTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i].isOccupied = 0;
    }
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}
void insert(HashTable* ht, int key, int value) {
    int hashIndex = hashFunction(key);
    int i = 0;
    while (ht->table[hashIndex].isOccupied) {
        if (ht->table[hashIndex].key == key) {
            ht->table[hashIndex].value = value; // Update existing key
            return;
        }
        i++;
        hashIndex = (hashFunction(key) + i * i) % TABLE_SIZE; // Quadratic probing
    }
    ht->table[hashIndex].key = key;
    ht->table[hashIndex].value = value;
    ht->table[hashIndex].isOccupied = 1;
}

int search(HashTable* ht, int key) {
    int hashIndex = hashFunction(key);
    int i = 0;
    while (ht->table[hashIndex].isOccupied) {
        if (ht->table[hashIndex].key == key) {
            return ht->table[hashIndex].value; // Key found
        }
        i++;
        hashIndex = (hashFunction(key) + i * i) % TABLE_SIZE; // Quadratic probing
    }
    return -1; // Key not found
}

int main() {
    HashTable ht;
    initHashTable(&ht);
    insert(&ht, 1, 10);
    insert(&ht, 11, 20); // Collision with key 1
    insert(&ht, 21, 30); // Collision with key 1 and 11

    printf("Value for key 1: %d\n", search(&ht, 1));   // Output: 10
    printf("Value for key 11: %d\n", search(&ht, 11)); // Output: 20
    printf("Value for key 21: %d\n", search(&ht, 21)); // Output: 30
    printf("Value for key 31: %d\n", search(&ht, 31)); // Output: -1 (not found)

    return 0;
}
