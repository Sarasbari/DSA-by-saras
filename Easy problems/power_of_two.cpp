// 231. ** Power of Two ** (platform : LeetCode, GeeksforGeeks) (bit manipulation)

/*Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two, if there exists an integer x such that n == 2x.*/

#include <iostream>
using namespace std;

bool isPowerOfTwo(int n)
{
    // Optimized approach using bit manipulation
    return n > 0 && (n & (n - 1)) == 0;

    // Brute force approach
    if (n < 1)
        return false;
    while (n != 1)
    {
        if (n % 2 == 1)
            return false;
        n /= 2;
    }
    return true;
}

int main()
{
    int n = 16;

    if (isPowerOfTwo(n))
    {
        cout << n << " is a power of two." << endl;
    }
    else
    {
        cout << n << " is NOT a power of two." << endl;
    }

    return 0;
}

// Time complexity: O(1) for the optimized approach
// Space complexity: O(1)