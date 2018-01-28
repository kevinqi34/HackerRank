#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<string> topic(n);
    for(int topic_i = 0; topic_i < n;topic_i++){
       cin >> topic[topic_i];
    }

    int max = 0;
    int mcount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int count = 0;
            for (int k = 0; k < m; k++) {
                unsigned int t1 = topic[i][k] - 48;
                unsigned int t2 = topic[j][k] - 48;
                if (t1 | t2) {
                    count++;
                }
            }

            if (count > max) {
                max = count;
                mcount = 1;
            } else if (count == max) {
                mcount++;
            }



        }
    }

    cout << max << endl;
    cout << mcount << endl;


    return 0;
}
