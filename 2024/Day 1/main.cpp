#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string myText;
    ifstream MyReadFile("input.txt");
    vector<int> list1;
    vector<int> list2;
    int sum{0};

    while(getline (MyReadFile, myText)) {
        list1.push_back(stoi(myText.substr(0, 5)));
        list2.push_back(stoi(myText.substr(8, myText.length())));
    }
    MyReadFile.close();

    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());

    // -------------------- Part 1 --------------------
    for (size_t i = 0; i < list1.size(); ++i) {
        sum += abs(list1[i] - list2[i]);
    }

    cout << "Part 1: " << endl;
    cout << "The total sum of differences is: " << sum << endl;
    cout << endl;
    sum = 0;

    // -------------------- Part 2 --------------------
    for (size_t i = 0; i < list1.size(); ++i) {
        int similarity{0};

        for (size_t j = 0; j < list2.size(); ++j) {
            if (list1[i] == list2[j]) {
                ++similarity;
            }
        }
        sum += list1[i] * similarity;
    }
    cout << "Part 2: " << endl;
    cout << "The total sum of differences is: " << sum << endl;

    return 0;
}