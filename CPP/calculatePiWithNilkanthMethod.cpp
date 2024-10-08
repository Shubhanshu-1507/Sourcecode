#include <iostream>
#include <math.h>
#include <iomanip>
#include <climits>

#define Billion 1000000000
typedef std::numeric_limits<long double> ld;

static long double Nilkanth() {
    long double pi = 3.0;
    int sign = 1;

    for (uint64_t i = 2; i <= Billion; i+=2) {

        pi += (4 * sign) / (i * (i + 1.0) * (i + 2.0));
        sign = -sign;
    }
    return pi;
}

int main() {
    std::cout << std::setprecision(ld::digits) << "With Nilkanth's method: " << Nilkanth() << std::endl;

    return 0;
}
