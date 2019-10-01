#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        cout << "Yes" << endl;
        return 0;
    }

    unordered_map<char, int> m;

    for (int i = 0; argv[1][i]; ++i) {
        if (m.find(argv[1][i]) != m.end()) {
            m.find(argv[1][i])->second++;
        }
        else {
            m.insert(pair<char, int>(argv[1][i], 1));
        }
    }

    //map<char, int>::iterator it;

    int odd = 0;
    for (auto it : m) {
        if (it.second & 1) {
            odd++;
        }
        if (odd > 1) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
