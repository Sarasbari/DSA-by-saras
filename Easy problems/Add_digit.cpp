// 258. ** Add Digits ** (platform: Leetcode, GeeksforGeeks) (math, digit root)

/*Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.*/

#include <iostream>
using namespace std;

int addDigits(int num)
{
    // Optimized approach using digital root formula
    return num == 0 ? 0 : (num - 1) % 9 + 1;

    // brute force approach
    while (num > 9)
    {
        int sum = 0;
        while (num != 0)
        {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    }
    return num;
}

int main()
{
    int num = 38; // You can change this input to test other cases

    int result = addDigits(num);
    cout << "The result after repeatedly adding digits of " << num << " is: " << result << endl;

    return 0;
}
// Time complexity: O(1) for the optimized approach
// Space complexity: O(1)