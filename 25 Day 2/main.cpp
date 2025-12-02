// ------------------------- Advent of Code 2025 - Day 2: Gift Shop -------------------------
// Solution by: Marcel Weikum
// ------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    char myChar;
    string collector;
    string numStr;
    vector<pair<string, string>> ranges;
    int counter{0};
    long long sum{0};
    ifstream MyReadFile("input.txt");

    // --------------------- PART 1 ---------------------
    while(MyReadFile.get(myChar)) {
        // collect all characters until a '-' or ',' is found
        if (myChar != '-' && myChar != ',') {
            collector += myChar;
        }
        // check for range delimiter and store first value
        else if (myChar == '-') {
            ranges.push_back({collector, ""});
            collector = "";
        }
        // check for separator and store second value
        else if (myChar == ',') {
            ranges[counter].second = collector;
            collector = "";
            counter++;
        }
    }
    // Add the last range if collector is not empty
    if (!collector.empty()) {
        ranges[counter].second = collector;
        collector = "";
    }

    // Loop through all pairs
    for (int i = 0; i < ranges.size(); ++i) {
        // Check for invalid ranges with odd digit counts
        if (ranges[i].first.length() == ranges[i].second.length() && ranges[i].first.length() % 2 != 0) {
            continue;
        }
        // Loop through every range
        for (long long j = stoll(ranges[i].first); j <= stoll(ranges[i].second); ++j) {
            numStr = to_string(j);
            // Check for invalid numbers with odd digit counts
            if (numStr.length() % 2 != 0) {
                continue;
            }
            // if the first substring equals the second substring, we have a double
            if (numStr.substr(0, numStr.length() / 2) == numStr.substr(numStr.length() / 2)) {
                sum += j;
            }
        }
    }

    cout << "The total sum of all valid numbers is: " << sum << endl;
    // --------------------------------------------------

    sum = 0; // reset sum
    collector = ""; // reset collector
    numStr = ""; // reset numStr

    // --------------------- PART 2 ---------------------
    string pattern;
    int repeatCount;

    // Loop through all pairs
    for (int i = 0; i < ranges.size(); ++i) {
        // Loop through every range
        for (long long j = stoll(ranges[i].first); j <= stoll(ranges[i].second); ++j) {
            numStr = to_string(j);
            // Loop through possible pattern lengths
            for (int k = 1; k <= numStr.length() / 2; ++k) {
                // Check if the current length can form a valid pattern
                if (numStr.length() % k != 0) {
                    continue;
                }
                // Extract the pattern and prepare to build the repeated string
                pattern = numStr.substr(0, k);
                collector = "";
                repeatCount = numStr.length() / k;

                // Build the repeated pattern
                for (int l = 0; l < repeatCount; ++l) {
                    collector += pattern;
                }
                // Check if the built pattern matches the original number
                if (collector == numStr) {
                    sum += j;
                    break; // no need to check further patterns for this number
                }
            }
        }
    }

    cout << "The total sum of all valid repeated pattern numbers is: " << sum << endl;
    // --------------------------------------------------

    MyReadFile.close();
    return 0;
}