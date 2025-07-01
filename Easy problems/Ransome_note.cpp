// 383. ** Ransom Note ** (platform: Leetcode,geeksforgeeks) {hashmap,string}

/*Given two strings ransomNote and magazine,
 return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
Each letter in magazine can only be used once in ransomNote.*/

#include <iostream>
#include <string>
using namespace std;

// Function to check if ransomNote can be constructed from magazine
bool canConstruct(string ransomNote, string magazine)
{
    // Create an array to count the frequency of each letter in the magazine
    int counter[26] = {0}; // 26 lowercase English letters

    // Count letters in the magazine
    for (char ch : magazine)
    {
        counter[ch - 'a']++; // Convert character to index (e.g., 'a' = 0)
    }
    /*
    For every character in magazine, increase its count.

ch - 'a' gives the index (0 for 'a', 1 for 'b', ..., 25 for 'z').

Example:
If magazine = "abcab"
Then counter becomes:
a:2, b:2, c:1
    */

    // Check if ransomNote can be formed
    for (char ch : ransomNote)
    {
        // If the letter is not available or used up, return false
        if (counter[ch - 'a']-- <= 0)
        {
            return false;
        }
    }
    /*
    Now check every character in ransomNote.
Decrease its count in the counter.
If the count becomes less than 0, it means there weren't enough letters from magazine.
    */

    // All characters in ransomNote were found in magazine
    return true;
}

int main()
{
    // Example input
    string ransomNote = "aab";
    string magazine = "abcab";

    // Call the function and store the result
    bool result = canConstruct(ransomNote, magazine);

    // Print result
    if (result)
    {
        cout << "Yes, the ransom note can be constructed from the magazine." << endl;
    }
    else
    {
        cout << "No, the ransom note cannot be constructed from the magazine." << endl;
    }

    return 0;
}

// Time complexity: O(n+m)
// space complexity: O(1)
