#include <iostream>
#include <vector>
#include <string>

using namespace std;

int DFA[3][1001];

int translateInt(char state)
{
    if (state == 'A') return 0;
    else if (state == 'B') return 1;
    else return 2;
}
void makeDFA(int size, string pattern) {
    int x = 0;
    for (int i = 0; i < size + 1; i++) {
        for (int j = 0; j < 3; j++) {
            DFA[j][i] = DFA[j][x];
        }
        x = DFA[translateInt(pattern[i])][x];
        if (size - 1 >= i) {
            DFA[translateInt(pattern[i])][i] = i + 1;
        }
    }
}
int main(void) 
{
    int testCase;
    cin >> testCase;
    for (int t = 0; t < testCase; t++)
    {
        int cnt = 0;
        int state = 0;
        int node = 0;
        string pattern, text;
        cin >> pattern >> text;
        makeDFA(pattern.size(), pattern);
        for (int i = 0; i < text.size() + 1; i++) {
            int temp = translateInt(text[i]);
            if (state == pattern.size()) {
                cnt++;
                state = DFA[temp][state];
            }
            else state = DFA[temp][state];
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < pattern.size() + 1; j++) {
                if (DFA[i][j] != 0) node++;
            }
        }
        cout << node << " " << cnt << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < pattern.size() + 1; j++) {
                DFA[i][j] = 0;
            }
        }
    }
}