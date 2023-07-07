/*
6. Use the Lehmann algorithm to check whether the given number P is prime or not?

The Lehmann algorithm is a probabilistic algorithm used to determine whether a given number is prime or composite. 
It is based on the observation that if a number P is prime, then for any random number A less than P, 
the expression A raised to the power of (P-1)/2 modulo P should be either 1 or -1 (mod P).

Here's how the Lehmann algorithm works:

1. Take the number P that needs to be checked for primality.
2. Randomly select a number A such that 1 < A < P.
3. Compute the value R = A^((P-1)/2) (mod P), using modular exponentiation.
4. If R is equal to 1 or -1 (mod P), continue to the next iteration.
5. Repeat steps 2 to 4 for a desired number of iterations (usually a large number) to increase the probability of correctness.
6. If, for all iterations, R is equal to 1 (mod P), then P is composite. Otherwise, if R is equal to -1 (mod P) for at least one iteration, 
    then P is probably prime.


*/

#include <bits/stdc++.h>
using namespace std;


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

bool is_prime_Lehmann(int P, int num_iterations)
{
    // Base case: If P is less than 2, it's not prime
    if (P < 2)
        return false;
    
    // Random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(2, P - 1);

    for (int i = 0; i < num_iterations; i++)
    {
        int A = dis(gen); // Randomly select A

        // Compute R = A^((P-1)/2) (mod P)
        int R = modularExponentiation(A, (P-1) / 2, P);

        cout << R << endl;
        // Check if R is equal to 1 or -1 (mod P)
        if (R != 1 && R != P -1)
            return false;   // P is composite
    }

    return true;    // P is probably prime
}


int main()
{
    int P;
    int num_iterations = 10;         // Number of iterations for increased accuracy

    cout << "Enter a number to check primality: ";
    cin >> P;

    if (is_prime_Lehmann(P, num_iterations))
        cout << P << " is probably prime." << endl;
    else
        cout << P << " is composite." << endl;

    return 0;

}