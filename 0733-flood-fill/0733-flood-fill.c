void dfs(int** image, int imageSize, int* imageColSize, int r, int c, int origColor, int newColor) {
    // boundary check
    if (r < 0 || c < 0 || r >= imageSize || c >= imageColSize[0]) return;

    // stop if not same color
    if (image[r][c] != origColor) return;

    // fill color
    image[r][c] = newColor;

    // explore 4 directions
    dfs(image, imageSize, imageColSize, r+1, c, origColor, newColor);
    dfs(image, imageSize, imageColSize, r-1, c, origColor, newColor);
    dfs(image, imageSize, imageColSize, r, c+1, origColor, newColor);
    dfs(image, imageSize, imageColSize, r, c-1, origColor, newColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {

    int origColor = image[sr][sc];

    // edge case: no change needed
    if (origColor == color) {
        *returnSize = imageSize;
        *returnColumnSizes = imageColSize;
        return image;
    }

    dfs(image, imageSize, imageColSize, sr, sc, origColor, color);

    // return values
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;

    return image;
}