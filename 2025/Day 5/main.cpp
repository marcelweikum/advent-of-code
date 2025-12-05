// ------------------------- Advent of Code 2025 - Day 5: Cafeteria -------------------------
// Solution by: Marcel Weikum
// ------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string myText;
    ifstream MyReadFile("input.txt");
    vector<long long> ingredients;
    vector<pair<long long, long long>> ranges;
    long long sum{0};
    bool isIngredient{false};

    // --------------------- PART 1 ---------------------
    while (getline (MyReadFile, myText)) {
        if (myText.empty()) {
            isIngredient = true;
            continue;
        }

        if (isIngredient) {
            ingredients.push_back(stoll(myText));
        } else {
            // Parse each range and store as pair
            for (int i{0}; i < (int)myText.length(); ++i) {
                if (myText[i] == '-') {
                    long long min = stoll(myText.substr(0, i));
                    long long max = stoll(myText.substr(i + 1));
                    ranges.push_back({min, max});
                    break;
                }
            }
        }
    }

    // Check each ingredient against all ranges
    for (const auto& ingredient : ingredients) {
        for (const auto& range : ranges) {
            if (ingredient >= range.first && ingredient <= range.second) {
                ++sum;
                break;
            }
        }
    }

    cout << "Part 1 - Total fresh ingredients: " << sum << endl;
    // --------------------------------------------------

    sum = 0; // reset sum for part 2

    // --------------------- PART 2 ---------------------
    sort(ranges.begin(), ranges.end());
    vector<pair<long long, long long>> merged;

    // Merge overlapping ranges
    for (const auto& range : ranges) {
        if (merged.empty() || merged.back().second < range.first - 1) {
            merged.push_back(range);
        } else {
            merged.back().second = max(merged.back().second, range.second);
        }
    }

    // Calculate total possible ingredient values
    for (int i{0}; i < merged.size(); ++i) {
        sum += (merged[i].second + 1) - merged[i].first; 
    }

    cout << "Part 2 - Total possible ingredient values: " << sum << endl;
    // --------------------------------------------------

    MyReadFile.close();
    return 0;
}