#include <iostream>
int main() {
    int a, b;
    std::cout << "Give me one number." << std::endl;
    std::cin >> a;
    std::cout << std::endl << "Give me your second number" << std::endl;
    std::cin >> b;
    if (a < b)
    {
        int c, d;
        c = a;
        d = b;
        b = c;
        a = d;
    }
    int r;
    do {
        r = a % b;
        a = b;
        b = r;
    } while (b != 0);
    std::cout << "Your answer is " << a << std::endl;
    return 0;
}