#include <iostream>
#include <string>
using namespace std;

int countChar(const string& s, char c) {
    int count = 0; // for keeping track of number of character in the string matching  with char c
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            count++;
        }
    }
    return count;
}

int main() {
    string s;
    char c;
    getline(cin, s);  //include space in input string
    cin >> c;   // input character

    cout << countChar(s, c);
}
