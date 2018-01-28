#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

/*
 * Computes the next lexicographical permutation of the specified vector
 * of values in place, returning whether a next permutation existed.
 * (Returns false when the argument is already the last possible permutation.)
 */
template <typename T>
bool nextPermutation(std::vector<T> &vec) {
    // Find non-increasing suffix
    if (vec.size() == 0)
        return false;
    typename std::vector<T>::iterator i = vec.end() - 1;
    while (i > vec.begin() && *(i - 1) >= *i)
        --i;
    if (i == vec.begin())
        return false;

    // Find successor to pivot
    typename std::vector<T>::iterator j = vec.end() - 1;
    while (*j <= *(i - 1))
        --j;
    std::iter_swap(i - 1, j);

    // Reverse suffix
    std::reverse(i, vec.end());
    return true;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string in;
        cin >> in;
        vector <char> test;
        for (auto i : in) {
            test.push_back(i);
        }

        nextPermutation(test);
        string new_out;
        for (auto i : test) {
            new_out+=i;
        }

        if (new_out == in) {
            cout << "no answer" << endl;
        } else {
            cout << new_out << endl;
        }



    }
    return 0;
}
