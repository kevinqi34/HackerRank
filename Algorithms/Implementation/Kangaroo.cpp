#include <bits/stdc++.h>

using namespace std;

string kangaroo(int x1, int v1, int x2, int v2) {
    // Complete this function
    for (int i = 0; i < 10000; i++) {
        int d1 = x1 + v1 * i;
        int d2 = x2 + v2 * i;

        if (d1 == d2) {
            return "YES";
            break;
        }

    }

    return "NO";


}

int main() {
    int x1;
    int v1;
    int x2;
    int v2;
    cin >> x1 >> v1 >> x2 >> v2;
    string result = kangaroo(x1, v1, x2, v2);
    cout << result << endl;
    return 0;
}
