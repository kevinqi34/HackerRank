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
    int N;
    cin >> N;
    vector<int> B(N);
    int sum = 0;
    int count = 0;
    for(int B_i = 0;B_i < N;B_i++){
       cin >> B[B_i];
        sum+=B[B_i];
        if (sum % 2 == 1) {
            count+=2;
        }
    }



    if (sum % 2 == 1) {
        cout << "NO" << endl;
    } else {
        cout << count << endl;



    }


    return 0;
}
