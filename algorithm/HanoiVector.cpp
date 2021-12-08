#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int> > answer;
 
void hanoi(int num, int from, int by, int to) {
    int cnt = 0;
    // 1번판(마지막 원판) -> 3번판
    if(num == 1)
    {
        cnt++;
        vector<int> temp;
        temp.push_back(from);
        temp.push_back(to);
        answer.push_back(temp);
        
        return;
    }
    cnt++;
    // 1번판 -> 2번판
    hanoi(num-1, from, to, by);
    
    // 1번판 -> 3번판
    vector<int> temp;
    temp.push_back(from);
    temp.push_back(to);
    answer.push_back(temp);
    
    // 2번판 -> 3번판
    hanoi(num-1, by, from, to);
}

int main() {
    int testCase;
    cin >> testCase;

    for (int i = 0; i < testCase; i++) {
        int n;
        unsigned long long int k;
        cin >> n >> k;

        hanoi(n, 1, 2, 3);

        for (int i = 0; i < answer.size(); i++) {
            for (int j = 0; j < answer[i].size(); j++) {
                if(i == k-1) {
                    cout << answer[i][j] << " ";
                }
            }
        }
        cout << "\n";
    }
}