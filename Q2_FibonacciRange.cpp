#include <iostream>
using namespace std;
// array to store 
int num[1000];

int fib(int n) {
    if (n == 1 || n == 2)
        return 1;
    if (num[n] != 0)  //base case for recursion
        return num[n];

    num[n] = fib(n - 1) + fib(n - 2);
    return num[n];
}
int main() {
    int n, m;
    cin >> n >> m;
if (n > m) {
        cout << "Invalid input! Should satisfy n<=m";
        return 0;
    }
for (int i = n; i <= m; i++) {
        cout << fib(i) << " ";
    }

    return 0;
}
