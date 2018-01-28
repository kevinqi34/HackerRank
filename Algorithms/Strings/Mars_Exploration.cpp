#include <iostream>

using namespace std;


int main(){
    string S;
    cin >> S;
    int count = 0;
    for (int i = 0; i < S.size(); i++) {
        if (i % 3 == 0 || i % 3 == 2) {
            if (S[i] != 'S') {
                count++;
            }
        } else {
            if (S[i] != 'O') {
                count++;
            }
        }

    }

    cout << count << endl;


    return 0;
}
