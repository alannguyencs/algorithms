#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <stack>
using namespace std;

const double PI = 3.1415926535;
const double ERR = 0.01;

bool feq (double a, double b) {
    return fabs(a-b) < ERR;
}

double fgcd(double a, double b) {
    if (feq(a, 0)) return b;
    if (feq(b, 0)) return a;
    return fgcd(b, fmod(a, b));
}



int main() {

    return 0;
}
