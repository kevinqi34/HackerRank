#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    string s;
    cin >> s;
    string t;
    cin >> t;
    int k;
    cin >> k;

    int common = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == t[i]) {
            common++;
        } else {
            break;
        }
    }

    int s_len = s.length();
    int t_len = t.length();

    // Case A - k is too small - reject
    if ((s_len + t_len - 2 * common) > k) {
        cout << "No" << endl;
    } else if ((s_len + t_len - 2 * common) % 2 == (k % 2)) { // Case B - k is exact - accept
        cout << "Yes" << endl;
    } else if ((s_len + t_len - k) < 0) { // Case C - k deletes entire string
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }



    return 0;
}
