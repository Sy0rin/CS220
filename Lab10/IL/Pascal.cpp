// Travis Bailey
// Lab 10 Pascal
// edited on Apr 25, 2023
#include <iostream>
using namespace std;

int nChooseK(int n, int k) {
    if (k == 0 || k == n) { // Base case: n choose 0 or n choose n is 1
        return 1;
    } else {
        // Recursive case: n choose k = (n-1) choose (k-1) + (n-1) choose k
        return nChooseK(n - 1, k - 1) + nChooseK(n - 1, k);
    }
}

int main() {
    int n, k;
    cout << "Enter n and k (integer) with a space between them: ";
    cin >> n >> k;

    int result = nChooseK(n, k);
    cout << n << " choose " << k << " = " << result << endl;
    return 0;
}