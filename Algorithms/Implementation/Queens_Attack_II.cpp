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

struct pos {
    int r;
    int c;
};


// Output -1 if invalid
int distance (pos a, pos b) {
    int check1 = abs(a.r - b.r);
    int check2 = abs(a.c - b.c);

    if (check1 == check2) {
        return check1 - 1;
    } else if (check1 == 0) {
        return check2 - 1;
    } else if (check2 == 0) {
        return check1 - 1;
    } else {
        return -1;
    }
}



// Return the direction facing the queen
int direction(pos a, pos queen) {
    if (a.r == queen.r && a.c < queen.c) {
        // Left of Queen
        return 0;
    } else if (a.r == queen.r && a.c > queen.c) {
        // Right of Queen
        return 1;
    } else if (a.c == queen.c && a.r < queen.r) {
        // Below Queen
        return 2;
    } else if (a.c == queen.c && a.r > queen.r) {
        // Above Queen
        return 3;
    } else if (a.c > queen.c && a.r > queen.r) {
        // Top Right
        return 4;
    } else if (a.c < queen.c && a.r > queen.r) {
        // Top Left
        return 5;
    } else if (a.c > queen.c && a.r < queen.r) {
        // Bottom Right
        return 6;
    } else if (a.c < queen.c && a.r < queen.r) {
        // Bottom Left
        return 7;
    } else {
        return -1;
    }

}




int main() {
    int n;
    int k;
    cin >> n >> k;
    int rQueen;
    int cQueen;
    cin >> rQueen >> cQueen;
    pos queen;
    queen.r = rQueen;
    queen.c = cQueen;

    // Initial Markers
    pos left = {queen.r, 0};
    int d0 = distance(left, queen);
    pos right = {queen.r, n + 1};
    int d1 = distance(right, queen);
    pos bottom = {0, queen.c};
    int d2 = distance(bottom, queen);
    pos top = {n + 1, queen.c};
    int d3 = distance(top, queen);

    pos bottomleft;
    if ((queen.c - 1) < (queen.r - 1)) {
        bottomleft.c = 0;
        bottomleft.r = queen.r - queen.c;
    } else {
        bottomleft.c = queen.c - queen.r;
        bottomleft.r = 0;
    }
    int d7 = distance(bottomleft, queen);

    pos bottomright;
    if ((n - queen.c) < (queen.r - 1)) {
        bottomright.c = n + 1;
        bottomright.r = queen.r - n + queen.c - 1;
    } else {
        bottomright.c = queen.c + queen.r;
        bottomright.r = 0;
    }
    int d6 = distance(bottomright, queen);

    pos topleft;
    if ((queen.c - 1) < (n - queen.r)) {
        topleft.c = 0;
        topleft.r = queen.r + queen.c;
    } else {
        topleft.c = queen.c - (n - queen.r) - 1;
        topleft.r = n + 1;
    }
    int d5 = distance(topleft, queen);

    pos topright;
    if ((n - queen.c) < (n - queen.r)) {
        topright.c = n + 1;
        topright.r = queen.r + (n - queen.c) + 1;
    } else {
        topright.c = queen.c + n - queen.r + 1;
        topright.r = n + 1;
    }
    int d4 = distance(topright, queen);

    // Find min marker in each direction O(k)
    for(int a0 = 0; a0 < k; a0++){
        int rObstacle;
        int cObstacle;
        pos obstacle;
        cin >> rObstacle >> cObstacle;
        // your code goes here
        obstacle.r = rObstacle;
        obstacle.c = cObstacle;

        int dir = direction(obstacle, queen);
        int dist = distance(obstacle, queen);
        if (dist != -1) {
            // 8 cases
            if (dir == 0) { // Case 0 - left
                if (dist < d0) {
                    left = obstacle;
                    d0 = dist;
                }
            } else if (dir == 1) { // Case 1 - right
                if (dist < d1) {
                    right = obstacle;
                    d1 = dist;
                }
            } else if (dir == 2) { // Case 2 - bottom
                if (dist < d2) {
                    bottom = obstacle;
                    d2 = dist;
                }
            } else if (dir == 3) { // Case 3 - top
                if (dist < d3) {
                    top = obstacle;
                    d3 = dist;
                }
            } else if (dir == 4) { // Case 4 - topright
                if (dist < d4) {
                    topright = obstacle;
                    d4 = dist;
                }
            } else if (dir == 5) { // Case 5 - topleft
                if (dist < d5) {
                    topleft = obstacle;
                    d5 = dist;
                }
            } else if (dir == 6) { // Case 6 - bottomright
                if (dist < d6) {
                    bottomright = obstacle;
                    d6 = dist;
                }
            } else if (dir == 7) { // Case 7 - bottomleft
                if (dist < d7) {
                    bottomleft = obstacle;
                    d7 = dist;
                }
            }
        } // if

    }

    // Calculate Total Steps
    int total = distance(left, queen) + distance(right, queen) + distance(top, queen) + distance(bottom, queen) +
        distance(bottomleft, queen) + distance(bottomright, queen) + distance(topleft, queen) +      distance(topright,queen);


/*

    cout << "Left  : " << left.r << " " << left.c << " " << distance(left, queen) << " " << direction(left, queen) << endl;
    cout << "Right : " << right.r << " " << right.c << " " << distance(right, queen) << " " << direction(right, queen) << endl;
    cout << "Top   : " << top.r << " " << top.c << " " << distance(top, queen) << " " << direction(top, queen) << endl;
    cout << "Bottom: " << bottom.r << " " << bottom.c << " " << distance(bottom, queen) << " " << direction(bottom, queen) << endl;
    cout << "BLeft : " << bottomleft.r << " " << bottomleft.c << " " << distance(bottomleft, queen) << " " << direction(bottomleft, queen) << endl;
    cout << "BRight: " << bottomright.r << " " << bottomright.c << " " << distance(bottomright, queen) << " " << direction(bottomright, queen) << endl;
    cout << "TLeft : " << topleft.r << " " << topleft.c << " " << distance(topleft, queen) << " " << direction(topleft, queen) << endl;
    cout << "TRight: " << topright.r << " " << topright.c << " " << distance(topright, queen) << " " << direction(topright, queen) << endl;

    cout << "Total : " << total << endl;

*/
    cout << total << endl;



    return 0;
}
