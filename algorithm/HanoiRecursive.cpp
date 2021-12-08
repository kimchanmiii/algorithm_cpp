#include <iostream>
using namespace std;
 
void HanoiTower(int n, int source, int intermediate, int target) {
    // if (n == 1) {
    //     cnt++;
    //     cout << source << " -> " << target << endl;
    //     cout << cnt << "    " << k << endl;
    //     cout << "----------------" << endl;
    //     return;
    // }
    if (n > 0) {
        HanoiTower(n - 1, source, target, intermediate);
        cout << source << " -> " << target << endl;
        HanoiTower(n - 1, intermediate, source, target);
    }
}

int main() {
    int n = 6;
    //int k = 5;
    HanoiTower(n, 1, 2, 3);
    return 0;

    // int testCase;
    // cin >> testCase;

    // for (int i = 0; i < testCase; i++) {
    //     int n, k;
    //     cin >> n >> k;
    //     long source[k];
    //     long target[k];

    //     for (int j = 0; j < k; j++) {
            
    //     }
    // }
}