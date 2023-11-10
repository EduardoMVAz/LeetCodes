void visitRooms(int** rooms, int * roomsColSize, int * visitados, int curr) {
    // verifica se o quarto já foi visitado
    if (visitados[curr] != 1) {
        
        // visita o quarto
        visitados[curr] = 1;
        
        // Para cada chave no quarto, visita o quarto correspondente
        for (int i = 0; i < roomsColSize[curr]; i++) {
            // visita o quarto
            visitRooms(rooms, roomsColSize, visitados, rooms[curr][i]);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    int * visitados = calloc(roomsSize, sizeof(int));
    
    visitRooms(rooms, roomsColSize, visitados, 0);
    
    for (int i = 0; i < roomsSize; i++) {
        if (visitados[i] != 1) {
            return false;
        }
    }
    return true;
}