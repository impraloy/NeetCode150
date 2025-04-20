class Solution {
public:
    int reverse(int x) {
        const int min = -2147483648; // -2^31
        const int max = 2147483647;  // 2^31 - 1

        int result = 0;
        while (x) {
            int digit = x % 10;
            x /= 10;

            if (result > max / 10 || (result == max / 10 && digit > max % 10))
                return 0;
            if (result < min / 10 || (result == min / 10 && digit < min % 10))
                return 0;
            result = (result * 10) + digit;
        }

        return result;
    }
};