#include <iostream>
#include <vector>
using namespace std;

void Hanoi(int, unsigned long long int);

int main() {
    int testCase, n;
    unsigned long long int k;

    cin >> testCase;

    for (int i = 0; i < testCase; i++) {
        cin >> n >> k;
        Hanoi(n, k);
    }
}

void Hanoi(int n, unsigned long long int k){
    unsigned long long int halfK = 2 << (n -  2);
    vector<pair<int, int> > v; 
    pair<int, int> p1, p2, p3, p4, p5, p6;
    
    if (k  == halfK) cout << 1 << " " << 3;
    else if (n % 2 != 0) {
        if (k < halfK) {
            p1 = make_pair(3, 2); 
            p2 = make_pair(1, 3); 
            p3 = make_pair(1, 2);
        }
        else  {
            p1 = make_pair(2, 3); 
            p2 = make_pair(1, 3); 
            p3 = make_pair(2, 1);
        }
        v.push_back(p1); 
        v.push_back(p2); 
        v.push_back(p3);
        cout << v[k % 3].first << " " << v[k % 3].second << endl;
    }
    else {
        if (k < halfK) {
            p1 = make_pair(3, 2); 
            p2 = make_pair(1, 2); 
            p3 = make_pair(1, 3); 
            p4 = make_pair(2, 3); 
            p5 = make_pair(1, 2); 
            p6 = make_pair(3, 1);
        }
        else  {
            p1 = make_pair(2, 3); 
            p2 = make_pair (1, 2); 
            p3 = make_pair(1, 3); 
            p4 = make_pair(2, 3); 
            p5 = make_pair(2, 1); 
            p6 = make_pair(3, 1);
        }
        v.push_back(p1); 
        v.push_back(p2); 
        v.push_back(p3); 
        v.push_back(p4); 
        v.push_back(p5); 
        v.push_back(p6);
        cout << v[k % 6].first << " " << v[k % 6].second << endl;
    }
}