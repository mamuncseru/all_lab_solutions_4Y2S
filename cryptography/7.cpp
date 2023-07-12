/*
7. Use the Robin-Miller algorithm to check whether the given number P is prime or not?


The Robin-Miller algorithm, also known as the Miller-Rabin primality test, is a probabilistic algorithm used to determine whether a
 given number is prime or composite. It is an improved version of the Lehmann algorithm and provides a higher probability of 
 correctly identifying prime numbers.

Here's how the Robin-Miller algorithm works:

1. Take the number P that needs to be checked for primality.
2. Write P-1 as (2^r) * d, where d is an odd number.
3. Randomly select a number a between 2 and P-2.
4. Compute x = (a^d) mod P using modular exponentiation.
5. If x is equal to 1 or P-1 (mod P), continue to the next iteration.
6. Repeat steps 3 to 5 for a desired number of iterations.
7. If, for all iterations, x is equal to 1 (mod P), then P is composite. Otherwise, 
if x is equal to P-1 (mod P) for at least one iteration, then P is probably prime.


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


bool is_prime_RobinMiller(int P, int num_iterations)
{
    // Base case: if P is less than 2, it's not prime
    if (P < 2)
        return false;

    // Write P-1 as (2^r) * d
    int r = 0;
    int d = P - 1;
    while (d%2 == 0)
    {
        d /= 2;
        r++;
    }

    // Random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(2, P-2);

    for (int i = 0; i < num_iterations; i++)
    {
        int a = dis(gen);   // Randomly select a base

        // Compute x = (a ^ d) mod P
        int x = modularExponentiation(a, d, P);

        // check if x is equal to 1 or P-1 (mod P)
        if (x != 1 && x!= P-1)
        {
            // Perform r - 1 modular exponentiations
            bool is_composite = true;
            for (int j = 1; j < r; j++)
            {
                x = modularExponentiation(x, 2, P);
                if (x == P - 1)
                {
                    is_composite = false;
                    break;
                }
            }
            if (is_composite)
                return false;   // P is composite
        }
    }

    return true;    // P is probably prime
}


int main()
{
    int P;
    int num_iterations = 10; // Number iterations for increased accuracy

    cout << "Enter a number to check primality: ";
    cin >> P;

    if (is_prime_RobinMiller(P, num_iterations))
        cout << P << " is probably a prime number." << endl;

    else
        cout << P << " is composite." << endl;

    return 0;
}