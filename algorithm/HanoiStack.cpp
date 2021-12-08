#include <iostream>
#include <stack>
using namespace std;

void move1(int no, int source, int target, unsigned long long int k){
	stack<int> s;
    // int source = 1;
    // int target = 3;
    int cnt = 0;
	while(1){
        cnt++;
		while(no > 1){
			s.push(no), s.push(source), s.push(target);
			no = no-1, target = 6-source-target;
		}
        if(cnt == k) {
            cout <<  source << " " << target << endl;
        }
        // cout << "cnt=" << cnt << endl;
		// cout << "원반[" << no << "]를(을) "<< x << "기둥에서 " << y << "기둥으로 옮김.\n";

		if(s.size()){
            cnt++;
			target = s.top(), s.pop();
			source = s.top(), s.pop();
			no = s.top(), s.pop();

            if(cnt == k) {
                cout <<  source << " " << target << endl;
            }
			
            // cout << "cnt=" << cnt << endl;
			// cout<< "원반[" << no << "]를(을) " << x << "기둥에서 "<< y << "기둥으로 옮김.\n";

			no = no-1, source = 6-source-target;
		}
		else
			break;
	}
}

int main() {
	// move1(3, 1, 3, 5);
	// return 0;

    int testCase;
    cin >> testCase;

    for (int i = 0; i < testCase; i++) {
        int n;
        unsigned long long int k;
        cin >> n >> k;

        move1(n, 1, 3, k);
    }

}