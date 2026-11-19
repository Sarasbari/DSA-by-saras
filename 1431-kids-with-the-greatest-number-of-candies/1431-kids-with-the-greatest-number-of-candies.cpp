class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxcandies = 0;
        for (int candy : candies)
            maxcandies = max(maxcandies, candy);

        vector<bool> result;
        for (int candy : candies)
            result.push_back(candy + extraCandies >= maxcandies);

        return result;
    }
};