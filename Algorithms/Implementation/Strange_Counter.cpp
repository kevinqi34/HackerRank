#include <iostream>

using namespace std;

int main(){
    long t;
    cin >> t;
    // O(log N)
    long top_value = 3;
    while (t > top_value) {
        t-=top_value;
        top_value*=2;
    } // While

    cout << top_value - t + 1 << endl;

    return 0;
}
