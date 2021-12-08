#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> fail(string pattern)
{
    int patternsize = pattern.size();
    vector<int> table(patternsize, 0);
    int j = 0;
    for (int i = 1; i < patternsize; i++) {
        while (j > 0 && pattern[i] != pattern[j]) { j = table[j - 1]; }
        if (pattern[i] == pattern[j]) {
            table[i] = ++j;
        }
    }
    for (int i = 0; i < patternsize; i++) {
        cout << table[i] << " ";
    }
    cout << endl;
    return table;
}

int kmp(string pattern, string text) {
    int patternsize = pattern.size();
    int textsize = text.size();
    int cnt = 0;
    vector<int> table = fail(pattern);

    int j = 0;
    for (int i = 0; i < textsize; i++) {
        while (j > 0 && pattern[j] != text[i]) { j = table[j - 1]; }
        if (pattern[j] == text[i]) {
            if (j == patternsize - 1) {
                cnt++;
                j = table[j];
            }
            else j++;
        }
    }
    return cnt;
}

int main(void) {
    int testCase;
    cin >> testCase;
    for (int t = 0; t < testCase; t++) {
        string pattern, text;
        cin >> pattern >> text;
        int cnt = kmp(pattern, text);
        cout << cnt << endl;
    }
}