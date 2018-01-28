#include <bits/stdc++.h>

using namespace std;

int solve(int n, int p){
   // Solve from front
   int f_turns = p / 2;

   if (n % 2 == 0) {
       n++;
   }
   int b_turns = (n - p) / 2;


   if (f_turns < b_turns) {
       return f_turns;
   } else {
       return b_turns;
   }
}

int main() {
    int n;
    cin >> n;
    int p;
    cin >> p;
    int result = solve(n, p);
    cout << result << endl;
    return 0;
}
