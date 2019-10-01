#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Too few arguments" << endl;
        return 1;
    }
    
    ifstream fileIn;
    fileIn.open(argv[1]);
    if (fileIn.fail()) {
        cout << "Bad file path" << endl;
        return 1;
    }

    unordered_map<string, int> wordCounts;

    string word;
    while (fileIn >> word) {
        if (wordCounts.find(word) == wordCounts.end()) {
            wordCounts.insert(pair<string, int>(word, 1));
        }
        else {
            wordCounts.find(word)->second++;
        }
    }

    fileIn.close();

    ofstream fileOut;
    fileOut.open(argv[1], ios::app);
    if (fileOut.fail()) {
        cout << "Bad file path" << endl;
        return 1;
    }

    for (auto it : wordCounts) {
        fileOut << it.first << ": " << it.second << endl;
    }

    cout << "Complete" << endl;

    return 0;
}
