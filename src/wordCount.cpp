#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Too few arguments" << endl;
        return 1;
    }

    unordered_map<string, int> m;
    ifstream file;
    file.open(argv[1]);
    if (file.fail()) {
        cout << "Bad file path" << endl;
        return 1;
    }
    string word;

    while (file >> word) {
        if (m.find(word) == m.end()) {
            m.insert(pair<string, int>(word, 1));
        }
        else {
            m.find(word)->second++;
        }
    }

    file.close();

    ofstream oFile;
    oFile.open(argv[1], ios::app);
    if (oFile.fail()) {
        cout << "Bad file path" << endl;
        return 1;
    }

    for (auto it : m) {
        oFile << it.first << ": " << it.second << endl;
    }

    oFile.close();

    cout << "Complete" << endl;

    return 0;
}
