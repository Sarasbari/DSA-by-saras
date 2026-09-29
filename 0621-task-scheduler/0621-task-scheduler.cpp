class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for (char task : tasks)
            freq[task - 'A']++;
        int maxfreq = 0;
        for (int f : freq)
            maxfreq = max(f, maxfreq);

        int maxcount = 0;
        for (int f : freq) {
            if (f == maxfreq)
                maxcount++;
        }

        int intervals = (maxfreq - 1) * (n + 1) + maxcount;

        return max((int)tasks.size(), intervals);
    }
};