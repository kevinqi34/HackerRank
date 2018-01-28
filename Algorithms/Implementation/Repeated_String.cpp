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
    long n;
    cin >> n;


    int num_of_as = 0;
    for (auto i: s) {
        if (i == 'a') {
            num_of_as++;
        }
    }

    int s_len = s.length();

    long repeat_count = n / s_len;
    int out_count = n % s_len;
    int ext = 0;
    for (int i = 0; i < out_count; i++) {
        if (s[i] == 'a') {
            ext++;
        }
    }


    cout << num_of_as * repeat_count + ext << endl;


    return 0;
}
