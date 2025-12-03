// ------------------------- Advent of Code 2025 - Day 3: Lobby -------------------------
// Solution by: Marcel Weikum
// --------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string myText;
    ifstream MyReadFile("input.txt");
    string collector;
    int counter{1};
    long long sum{0};
    int maxTwoDigit = 0;
    int maxFirstIdx = -1;
    int maxSecondIdx = -1;

    // --------------------- PART 1 ---------------------
    while(getline (MyReadFile, myText)) {

        // Check all possible pairs of digits where i comes before j
        for (int i = 0; i < myText.length(); ++i) {
            for (int j = i + 1; j < myText.length(); ++j) {
                int firstDigit = myText[i] - '0';
                int secondDigit = myText[j] - '0';
                int twoDigitNum = firstDigit * 10 + secondDigit;

                if (twoDigitNum > maxTwoDigit) {
                    maxTwoDigit = twoDigitNum;
                    maxFirstIdx = i;
                    maxSecondIdx = j;
                }
            }
        }
        collector = to_string(maxTwoDigit);
        sum += maxTwoDigit;
        ++counter;

        maxTwoDigit = 0;
        maxFirstIdx = -1;
        maxSecondIdx = -1;
        collector.clear();
    }
    cout << "Part 1 - Sum of all highest and second highest numbers: " << sum << endl;
    // --------------------------------------------------

    sum = 0; // reset sum for part 2
    counter = 1; // reset counter for part 2
    collector.clear(); // reset collector for part 2
    MyReadFile.clear(); // clear the EOF flag
    MyReadFile.seekg(0); // move the file pointer to the beginning

    // --------------------- PART 2 ---------------------
    while(getline (MyReadFile, myText)) {
        
        int currentSearchIdx = 0;
        int digitsNeeded = 12;
        collector.clear();

        // Construct the highest 12-digit number
        for (int k = 0; k < 12; ++k) {
            char bestDigit = -1;
            int bestDigitIdx = -1;
            
            // Calculate the limit for the search range
            int searchEndLimit = myText.length() - (digitsNeeded - 1);

            // Search for the best digit in the allowed range
            for (int i = currentSearchIdx; i < searchEndLimit; ++i) {

                // If there is a better digit, update bestDigit and its index
                if (myText[i] > bestDigit) {
                    bestDigit = myText[i];
                    bestDigitIdx = i;
                    if (bestDigit == '9') break; 
                }
            }

            collector += bestDigit;
            
            currentSearchIdx = bestDigitIdx + 1;
            digitsNeeded--;
        }
        sum += stoll(collector);
        ++counter;
        
    }
    cout << "Part 2 - Sum of all highest 12-digit numbers: " << sum << endl;
    // --------------------------------------------------

    MyReadFile.close();
    return 0;
}