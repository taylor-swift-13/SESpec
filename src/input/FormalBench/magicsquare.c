int magicSquareTest(int ** myMatrix, int n);

int magicSquareTest(int ** myMatrix, int n) {

    int magicSum = 0;
    for (int i = 0; i < n; i++) {
        magicSum += myMatrix[0][i];
    }

    for (int i = 0; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += myMatrix[i][j];
        }
        if (rowSum != magicSum) {
            return 0;
        }
    }

    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < n; i++) {
            colSum += myMatrix[i][j];
        }
        if (colSum != magicSum) {
            return 0;
        }
    }

    int diagonalSum1 = 0;
    for (int i = 0; i < n; i++) {
        diagonalSum1 += myMatrix[i][i];
    }
    if (diagonalSum1 != magicSum) {
        return 0;
    }

    int diagonalSum2 = 0;
    for (int i = 0; i < n; i++) {
        diagonalSum2 += myMatrix[i][n - i - 1];
    }
    if (diagonalSum2 != magicSum) {
        return 0;
    }

    return 1;
}
