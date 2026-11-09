class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        while (fast != 1) {
            slow = fun(slow);
            fast = fun(fun(fast));

            if (slow == fast && fast != 1)
                return false;
        }
        return true;
    }

    int fun(int n) {
        int sum = 0;

        while (n > 0) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }
};