// 242. ** Valid Anargram ** (platform : leetcode, geeksforgeeks) (string)

/*Given two strings s and t, return true if t is an anagram of s, and false otherwise.*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isAnagram(string s, string t)
{
    if (s.length() != t.length()) // check if the size of both the strings are equal
    {
        return false;
    }

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != t[i]) // check if the characters of both the strings are equal
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s = "listen";
    string t = "silent";

    if (isAnagram(s, t))
    {
        cout << "\"" << s << "\" and \"" << t << "\" are anagrams." << endl;
    }
    else
    {
        cout << "\"" << s << "\" and \"" << t << "\" are NOT anagrams." << endl;
    }

    return 0;
}
// Time complexity: O(n log n) due to sorting
// Space complexity: O(1)