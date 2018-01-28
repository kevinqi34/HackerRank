#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;


bool is_happy(string input) {

     int checker = 0;
     for (int i = 1; i < input.size() - 1; i++) {
        if (input[i-1] != input[i] && input[i+1] != input[i]) {
            checker = 1;
            break;
        }
     } // For

     if (checker) {
        return false;
     } else {
        return true;
     }
}



int main(){
    int Q;
    cin >> Q;
    for(int a0 = 0; a0 < Q; a0++){
        int n;
        cin >> n;
        string b;
        cin >> b;

        unordered_map <char, int> machine; // Track instances
        vector <char> keys;

        // Count instances of each color
        for (auto i : b) {
            auto it = machine.find(i);
            if (it == machine.end()) {
                // Create new
                pair <char, int> tmp;
                tmp.first = i;
                tmp.second = 1;
                machine.insert(tmp);
                keys.push_back(i);
            } else {
                // Update
                it->second++;
            }
        } // For

        int bad_count = 0;
        for (auto i : keys) {
            if (i != '_') {
                if (machine.find(i)->second == 1) {
                    bad_count++;
                    break;
                }
            }
        } // For



        if (bad_count) {
            cout << "NO" << endl;
        } else {
            if (machine.find('_') == machine.end() && !is_happy(b)) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        }


    }
    return 0;
}
