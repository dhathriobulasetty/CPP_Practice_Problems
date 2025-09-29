#include <iostream>

// (a) Function header for a function called exchange
void exchange(double* x, double* y);

// (c) Function header for a function called evaluate
// poly is a pointer to a function that takes an int and returns an int
typedef int (*PolyFunc)(int);
int evaluate(int x, PolyFunc poly);

int main() {
   
    double number1 = 5.5;
    double number2 = 9.9;

    // (b) Function prototype for exchange
    std::cout << "Demonstrating exchange function\n";
    std::cout << "Before exchange: number1 = " << number1 
              << ", number2 = " << number2 << std::endl;
    exchange(&number1, &number2);
    std::cout << "After exchange:  number1 = " << number1 
              << ", number2 = " << number2 << std::endl;

    // (d) Function prototype for evaluate

    std::cout << "\nDemonstrating evaluate function\n";
    auto square = [](int n) { return n * n; }; // sample poly function
    int result = evaluate(4, square);
    std::cout << "evaluate(4, square) = " << result << std::endl;

    // (e) Two statements initializing vowel array
    char vowel1[] = "AEIOU";
    char vowel2[6] = {'A','E','I','O','U','\0'};

    std::cout << "\nVowel arrays initialized:\n";
    std::cout << "vowel1 = " << vowel1 << std::endl;
    std::cout << "vowel2 = " << vowel2 << std::endl;

    return 0;
}

// (a) Definition of exchange
void exchange(double* x, double* y) {
    double temp = *x;
    *x = *y;
    *y = temp;
}

// (c) Definition of evaluate
int evaluate(int x, PolyFunc poly) {
    return poly(x); // call the function passed as argument
}
