// ------------------------- Advent of Code 2025 - Day 4: Printing Department -------------------------
// Solution by: Marcel Weikum
// ----------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>

using namespace std;

int checkAround(int x, int y, const vector<string>& grid) {
    if (grid[x][y] == '.' || grid[x][y] == 'x') {
        return 4; // no roll, return 4 to skip
    }

    int count{0};
    int length = grid.size();
    
    int startX{max(0, x - 1)};
    int endX{min(length - 1, x + 1)};

    int startY{max(0, y - 1)};
    int endY{min(length - 1, y + 1)};

    for (int i = startX; i <= endX; ++i) {
        for (int j = startY; j <= endY; ++j) {
            if (i == x && j == y) {
                continue;
            }
            if (grid[i][j] == '@') {
                ++count;
            }
        }
    }
    return count;
}

int main() {
    string myText;
    ifstream MyReadFile("input.txt");
    vector<string> grid;
    int sum{0};
    int removed{0};

    while (getline (MyReadFile, myText)) {
        grid.push_back(myText);
    }

    MyReadFile.close();

    // --------------------- PART 1 ---------------------
    for (int i = 0; i < (int)grid.size(); ++i) {
        for (int j = 0; j < (int)grid[i].length(); ++j) {
            if (checkAround(i, j, grid) < 4) {
                ++sum;
            }
        }
    }
    cout << "Part 1 - Total removed items: " << sum << endl;
    // --------------------------------------------------

    sum = 0; // reset sum for part 2

    // --------------------- PART 2 ---------------------
    do { // do until no more items can be removed
        removed = 0;
        for (int i = 0; i < (int)grid.size(); ++i) {
            for (int j = 0; j < (int)grid[i].length(); ++j) {
                if (checkAround(i, j, grid) < 4) {
                    grid[i][j] = 'x';
                    ++removed;
                }
            }
        }
        sum += removed;
    } while (removed > 0);
    cout << "Part 2 - Total removed items: " << sum << endl;
    // --------------------------------------------------
}