// Cracking The Coding Interview - 1.7
// Zero rows and columns in an MxN matrix

#include <iostream>
#include <iomanip>

using namespace std;

void PropogateZeros(int* matrix[], int M, int N) {
    bool* zrows = new bool[M];
    bool* zcols = new bool[N];
    for(int row = 0; row < M; row++) {
        for(int col = 0; col < N; col++) {
            if(matrix[row][col] == 0) {
                zrows[row] = true;
                zcols[col] = true;
            }
        }
    }

    // zero rows
    for(int row = 0; row < M; row++) {
        if(zrows[row]) {
            for(int col = 0; col < N; col++) {
                matrix[row][col] = 0;
            }
        }
    }

    // zero cols
    for(int col = 0; col < N; col++) {
        if(zcols[col]) {
            for(int row = 0; row < M; row++) {
                matrix[row][col] = 0;
            }
        }
    }

}

void PrintMatrix(int* matrix[], int M, int N) {
    for(int row = 0; row < M; row++) {
        for(int col = 0; col < N; col++) {
            cout << setw(3) << matrix[row][col] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // allocate matrix
    const int ROWS = 10;
    const int COLS = 7;
    int* matrix[ROWS];
    for(int r = 0; r < ROWS; r++) {
        matrix[r] = new int[COLS];
    }

    // initialize matrix
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            matrix[r][c] = r+c;
        }
    }
    matrix[ROWS/2][COLS/2+2] = 0;

    // print and set zeros
    PrintMatrix(matrix, ROWS, COLS);
    PropogateZeros(matrix, ROWS, COLS);
    PrintMatrix(matrix, ROWS, COLS);

    return 0;
}
