/*
  5.19 (Calculating the Value of ) Calculate the value of π from the infinite series

                4   4   4   4   4
        π = 4 – - + - – - + - – -- + ...
                3   5   7   9   11

  Print a table that shows the value of π approximated by computing the first 200,000 terms of this
  series. How many terms do you have to use before you first get a value that begins with 3.14159?
 */
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    long double infinitePI{4.0};
    unsigned long int denominator{3};

    bool foundFirst314159{false};
    unsigned long int at314159{0};
    cout << "Number of calculations\tValue of infinitePI" << endl;
    for (int calculationCount = 1; calculationCount <= 200'000; calculationCount++) {
        if ((calculationCount % 2) == 0)
            infinitePI += 4.0 / static_cast<double>(denominator);
        else
            infinitePI -= 4.0 / static_cast<double>(denominator);
        if (foundFirst314159 == false && infinitePI >= 3.14159 && infinitePI < 3.14160) {
            at314159 = calculationCount;
            foundFirst314159 = true;
        }
        denominator += 2;
        cout << calculationCount << "\t" << fixed << setprecision(6) << infinitePI << endl;
    }
    cout << "Hit 3.14159 at calculation #" << at314159 << endl;

    return 0;
}
