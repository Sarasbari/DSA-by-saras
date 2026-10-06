class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;
        map<int, int> count;

        for (int card : hand)
            count[card]++;

        while (!count.empty()) {
            int start = count.begin()->first;

            for (int x = start; x < start + groupSize; x++) {
                if (count[x] == 0)
                    return false;
                count[x]--;
                if (count[x] == 0)
                    count.erase(x);
            }
        }
        return true;
    }
};