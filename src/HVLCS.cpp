#include <unordered_map>
#include <iostream>
using namespace std;

int main() {
    int K;
    cin >> K;

    unordered_map<char, int> val;
    for (int i = 0; i < K; i++) {
        char ch;
        int v;
        cin >> ch >> v;
        val[ch] = v;
    }

    string A, B;
    cin >> A >> B;

    cout << "K: " << K << endl;
    for (auto p : val) {
        cout << "char: " << p.first << " val: " << p.second << endl;
    }
    cout << "A: " << A << endl;
    cout << "B: " << B << endl;

    return 0;
}