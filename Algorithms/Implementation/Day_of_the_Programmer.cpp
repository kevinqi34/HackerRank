#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


int is_leap_year(int year) {
  if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
      return 1;
  } else {
      return 0;
  }
}


int is_leap_year2(int year) {
    if (year % 4 == 0) {
        return 1;
    } else {
        return 0;
    }
}



string solve(int year){
    // Find day and month
    int limit = 256;
    int day;
    int month;


    if (year > 1918) {
        for (int i = 0; i < months.size(); i++) {
            if (i == 1 && is_leap_year(year)) {
                limit-=29;
            } else {
                limit-=months[i];
            }

            if (limit > 0) {
                day = limit;
                month = i + 2;
            } else {
                break;
            }
        }
    } else if (year < 1918) {
        for (int i = 0; i < months.size(); i++) {
            if (i == 1 && is_leap_year2(year)) {
                limit-=29;
            } else {
                limit-=months[i];
            }

            if (limit > 0) {
                day = limit;
                month = i + 2;
            } else {
                break;
            }
         }
    } else {
         for (int i = 0; i < months.size(); i++) {
            if (i == 1) {
                limit-=15;
            } else {
                limit-=months[i];
            }

            if (limit > 0) {
                day = limit;
                month = i + 2;
            } else {
                break;
            }
         }
    }



    string d;
    string m;
    if (day < 10) {
      d = "0" + to_string(day);
    } else {
      d = to_string(day);
    }

    if (month < 10) {
      m = "0" + to_string(month);
    } else {
      m = to_string(month);
    }


    return d + "." + m + "." + to_string(year);
}

int main() {
    int year;
    cin >> year;
    string result = solve(year);
    cout << result << endl;
    return 0;
}
