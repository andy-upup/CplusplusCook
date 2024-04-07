#include "matrix.h"

namespace algo {

// 73
// input: matrix = [[1,1,1],
//                  [1,0,1],
//                  [1,1,1]]
// output: [[1,0,1],
//          [0,0,0],
//          [1,0,1]]
void setZeroes(std::vector<std::vector<int>>& matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    std::vector<bool> row(m, false);
    std::vector<bool> col(n, false);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}

// 54
// input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// output: [1,2,3,6,9,8,7,4,5]
std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
    if (matrix.empty()) {
        return {};
    }
    std::vector<int> output;
    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;
    while (true) {
        for (int i = left; i <= right; ++i) {
            output.push_back(matrix[top][i]);
        }
        if (++top > bottom) {
            break;
        }
        for (int i = top; i <= bottom; ++i) {
            output.push_back(matrix[i][right]);
        }
        if (--right < left) {
            break;
        }
        for (int i = right; i >= left; --i) {
            output.push_back(matrix[bottom][i]);
        }
        if (--bottom < top) {
            break;
        }
        for (int i = bottom; i >= top; --i) {
            output.push_back(matrix[i][left]);
        }
        if (++left > right) {
            break;
        }
    }
    return output;
}

// 48
// input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// output: [[7,4,1],[8,5,2],[9,6,3]]
void rotate(std::vector<std::vector<int>>& matrix) {
    if (matrix.empty()) {
        return;
    }
    int row = matrix.size();
    int col = matrix[0].size();
    for (int i = 0; i < row / 2; ++i) {
        for (int j = 0; j < col; ++j) {
            int num = matrix[i][j];
            matrix[i][j] = matrix[row - 1 - i][j];
            matrix[row - 1 - i][j] = num;
        }
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < i; ++j) {
            int num = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = num;
        }
    }
}

// 240
// input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
// output: true
bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    if (matrix.empty()) {
        return false;
    }
    const int row = matrix.size();
    const int col = matrix[0].size();
    int i = 0, j = col - 1;
    while (i < row && j >= 0) {
        if (matrix[i][j] == target) {
            return true;
        } else if (matrix[i][j] < target) {
            ++i;
        } else {
            --j;
        }
    }
    return false;
}

} // namespace algo