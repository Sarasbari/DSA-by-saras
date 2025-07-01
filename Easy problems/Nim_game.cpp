// 292. ** Nim Game  ** (platform: Leetcode, geeksforgeeks) {math}

/*
You are playing the following Nim Game with your friend:

Initially, there is a heap of stones on the table.
You and your friend will alternate taking turns, and you go first.
On each turn, the person whose turn it is will remove 1 to 3 stones from the heap.
The one who removes the last stone is the winner.
Given n, the number of stones in the heap,
 return true if you can win the game assuming both you and your friend play optimally, otherwise return false.
 */

/*
Winning Strategy:
If n % 4 == 0, then you cannot win (❌) — because the opponent can always bring it back to a multiple of 4.

If n % 4 != 0, then you can win (✅) — by forcing your opponent into a losing position.
*/

#include <iostream>
using namespace std;

bool canWinNim(int n)
{
    return n % 4 != 0;
}

int main()
{
    int n = 7;

    if (canWinNim(n))
    {
        cout << "You can win the Nim Game with " << n << " stones." << endl;
    }
    else
    {
        cout << "You will lose the Nim Game with " << n << " stones." << endl;
    }

    return 0;
}

// Time complexity: O(1)
// space complexity:O(1)
