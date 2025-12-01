// ------------------------- Advent of Code 2025 - Day 1: Secret Entrance -------------------------
// Solution by: Marcel Weikum
// ------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string myText;
    ifstream MyReadFile("input.txt");
    int position{50};
    int timesAtZero{0};

    // --------------------- PART 1 ---------------------
    while(getline (MyReadFile, myText)) {
        // get the rotation value, mod 100 if over 100
        int rotation = stoi(myText.substr(1, myText.length())) > 100 ? stoi(myText.substr(1, myText.length())) % 100 : stoi(myText.substr(1, myText.length()));
        // if the first character is L, move left
        if (myText[0] == 'L') {
            position -= rotation;
            // wrap around if below 0
            if (position < 0) {
                position += 100;
            }
        }
        // if the first character is R, move right
        else if (myText[0] == 'R') {
            position += rotation;
            // wrap around if over 100
            if(position >= 100) {
                position -= 100;
            }
        }

        if (position == 0) {
            timesAtZero++;
        }
    }
    cout << "Times at zero: " << timesAtZero << endl;
    // --------------------------------------------------
    
    position = 50;                      // reset position
    timesAtZero = 0;                    // reset counters
    MyReadFile.clear();                 // clear the EOF flag
    MyReadFile.seekg(0);                // move the file pointer to the beginning

    // --------------------- PART 2 ---------------------

    while(getline (MyReadFile, myText)) {
        // get the rotation value, mod 100 if over 100
        int rotation = stoi(myText.substr(1, myText.length()));
        // if the first character is L, move left
        if (myText[0] == 'L') {
            for (int i{0}; i < rotation; ++i) {
                position--;
                // wrap around if below 0
                if (position < 0) {
                    position += 100;
                }
                if (position == 0) {
                    timesAtZero++;
                }
            }
        }
        // if the first character is R, move right
        else if (myText[0] == 'R') {
            for (int i{0}; i < rotation; ++i) {
                position++;
                // wrap around if over 100
                if(position >= 100) {
                    position -= 100;
                }
                if (position == 0) {
                    timesAtZero++;
                }
            }
        }
    }
    cout << "Times at zero: " << timesAtZero << endl;
    // --------------------------------------------------

    MyReadFile.close();
    return 0;
}