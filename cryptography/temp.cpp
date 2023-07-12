#include <iostream>
#include <random>
#include <cmath>

int modularExponentiation(int base, int exponent, int modulus)
{
    int result = 1;
    base = base % modulus;

    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;

        base = (base * base) % modulus;
        exponent /= 2;
    }

    return result;
}

bool isPrimeLehmann(int P, int numIterations)
{
    // Base case: if P is less than 2, it's not prime
    if (P < 2)
        return false;

    // Random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(2, P - 2);

    for (int i = 0; i < numIterations; ++i)
    {
        int A = dis(gen); // Randomly select A

        // Compute R = A^((P-1)/2) (mod P)
        int R = modularExponentiation(A, (P - 1) / 2, P);

        // Check if R is equal to 1 or P - 1 (mod P)
        if (R != 1 && R != P - 1)
            return false; // P is composite
    }

    return true; // P is probably prime
}

int main()
{
    int P;
    int numIterations = 10; // Number of iterations for increased accuracy

    std::cout << "Enter a number to check primality: ";
    std::cin >> P;

    if (isPrimeLehmann(P, numIterations))
        std::cout << P << " is probably prime." << std::endl;
    else
        std::cout << P << " is composite." << std::endl;

    return 0;
}
