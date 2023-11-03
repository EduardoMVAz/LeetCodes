int findCenter(int** edges, int edgesSize, int* edgesColSize) {
    bool center = true, hasedge = false;
    for (int i = 1; i < edgesSize + 2; i++) {
        for (int j = 0; j < edgesSize; j++) {
            for (int k = 0; k < edgesColSize[j]; k++) {
                if (i == edges[j][k]) {
                    hasedge = true;
                }
            }
            if (!hasedge) {
                center = false;
                break;
            }
            hasedge = false;
        }
        if (center) {
            return i;
        }
        center = true;
    }
    return -1;
}