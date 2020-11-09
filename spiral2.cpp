#include<iostream>
#include<vector>
using namespace std;

const int RIGHT = 0, DOWN = 1, LEFT = 2, UP = 3;

bool is_out_of_bounds_or_occupied(int n,
                                  int row,
                                  int col, vector<vector<int> > M) {
    return row < 0           // out of bounds
        || row == n          // out of bounds
        || col < 0           // out of bounds
        || col == n          // out of bounds
        || M[row][col] != 0; // preoccupied
}

vector<vector<int> > spiral_matrix(int n) {
    vector<vector<int> > M(n, vector<int>(n)); // default fill value for intergers is 0
    int row = 0, col = 0;
    int num = 1;
    int direction = RIGHT;
    while(num <= n * n) {
        // keep working till we've filled all numbers 
        // from 1 to n^2
        M[row][col] = num;
        num += 1;

        // figure out where the next number should go
        if(direction == RIGHT) {
            col += 1;
            if(is_out_of_bounds_or_occupied(n, row, col, M)) {
                col -= 1; // get your ass back inside
                row += 1; // move down
                direction = DOWN;
            }
        } else if(direction == DOWN) {
            row += 1;
            if(is_out_of_bounds_or_occupied(n, row, col, M)) {
                row -= 1; // get your ass back inside
                col -= 1; // move left
                direction = LEFT;
            }
        } else if(direction == LEFT) {
            col -= 1;
            if(is_out_of_bounds_or_occupied(n, row, col, M)) {
                col += 1; // get your ass back inside
                row -= 1; // move left
                direction = UP;
            }
        } else if(direction == UP) { // move up
            row -= 1;
            if(is_out_of_bounds_or_occupied(n, row, col, M)) {
                row += 1; // get your ass back inside
                col += 1; // move right
                direction = RIGHT;
            }
        }
    }
    return M;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > M = spiral_matrix(n);
    for(int i = 0; i < M.size(); i++) {
        for(int j = 0; j < M[i].size(); j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}


