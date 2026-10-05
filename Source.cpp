#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>

using namespace std;

int ackermannRecursive(int m, int n) {
    if (m == 0) {
        return n + 1;
    }
    else if (n == 0) {
        return ackermannRecursive(m - 1, 1);
    }
    else {
        return ackermannRecursive(m - 1, ackermannRecursive(m, n - 1));
    }
}

int ackermannNonRecursive(int m, int n) {
    int st[10000];
    int top = -1;

    st[++top] = m;

    while (top >= 0) {
        m = st[top--];

        if (m == 0) {
            if (top == -1) {
                return n + 1;
            }
            n = n + 1;
        }
        else if (n == 0) {
            st[++top] = m - 1;
            n = 1;
        }
        else {
            st[++top] = m - 1;
            st[++top] = m;
            n = n - 1;
        }
    }
    return n;
}

void generatePowerset(const char S[], int size, int index, char current[], int currentSize) {
    if (index == size) {
        cout << "(";
        for (int i = 0; i < currentSize; ++i) {
            cout << current[i];
            if (i + 1 < currentSize) cout << ",";
        }
        cout << ")";
        return;
    }

    generatePowerset(S, size, index + 1, current, currentSize);

    if (index < size - 1 || currentSize > 0) {
        cout << ", ";
    }

    current[currentSize] = S[index];
    generatePowerset(S, size, index + 1, current, currentSize + 1);
}

int main() {
    cout << "=== Homework 1 Testing ===\n\n";

    cout << "--- Problem 1: Ackermann Function ---\n";
    int testM = 2, testN = 2;
    cout << "Ackermann Recursive(" << testM << ", " << testN << ") = "
        << ackermannRecursive(testM, testN) << "\n";
    cout << "Ackermann Non-Recursive(" << testM << ", " << testN << ") = "
        << ackermannNonRecursive(testM, testN) << "\n\n";

    cout << "--- Problem 2: Powerset Generation ---\n";
    char S[] = { 'a', 'b', 'c' };
    int size = 3;
    char current[10];

    cout << "Set S = {a, b, c}\n";
    cout << "Powerset(S) = {";
    generatePowerset(S, size, 0, current, 0);
    cout << "}\n";

    return 0;
}