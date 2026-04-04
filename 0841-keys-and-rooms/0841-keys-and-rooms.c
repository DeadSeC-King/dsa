#include <stdbool.h>

void dfs(int** rooms, int roomsSize, int* roomsColSize, int room, bool* visited) {
    if (visited[room]) return;
    
    visited[room] = true;
    
    for (int i = 0; i < roomsColSize[room]; i++) {
        int nextRoom = rooms[room][i];
        dfs(rooms, roomsSize, roomsColSize, nextRoom, visited);
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool visited[roomsSize];
    
    // initialize visited array
    for (int i = 0; i < roomsSize; i++) {
        visited[i] = false;
    }
    
    // start DFS from room 0
    dfs(rooms, roomsSize, roomsColSize, 0, visited);
    
    // check if all rooms visited
    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) return false;
    }
    
    return true;
}