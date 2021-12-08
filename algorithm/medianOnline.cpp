#include <iostream>
#include <queue>
#include <functional>
#include <math.h>
using namespace std;
 
// function to calculate med of stream
void MedianOnline(double arr[], int n)
{
    // max heap to store the smaller half elements
    priority_queue<double> s;
 
    // min heap to store the greater half elements
    priority_queue<double,vector<double>,greater<double> > g;
    
    int sum = 0;
    double med = arr[0];
    s.push(arr[0]);

    sum += med;
    sum %= 10;

    for (int i=1; i < n; i++)
    {
        double x = arr[i];
 
        // case1(left side heap has more elements)
        if (s.size() > g.size())
        {
            if (x < med)
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
                g.push(x);
 
            med = (s.top() + g.top())/2.0;
            med = trunc(med);
            sum += med;
            sum %= 10;
        }
 
        // case2(both heaps are balanced)
        else if (s.size()==g.size())
        {
            if (x < med)
            {
                s.push(x);
                med = (double)s.top();
                sum += med;
                sum %= 10;
            }
            else
            {
                g.push(x);
                med = (double)g.top();
                sum += med;
                sum %= 10;
            }
        }
 
        // case3(right side heap has more elements)
        else
        {
            if (x > med)
            {
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            else
                s.push(x);
 
            med = (s.top() + g.top())/2.0;
            med = trunc(med);
            sum += med;
            sum %= 10;
        }
    }
    cout << sum << endl;
}

int main() {

    int testCase;
    cin >> testCase;

    for (int i = 0; i < testCase; i++) {
        int n;
        cin >> n;
        double arr[n];

        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        // int n = sizeof(arr)/sizeof(arr[0]);
        MedianOnline(arr, n);

        // for (int j = 0; j < n; j++) {
        //     cout << sum << endl;
        // }
    }
}