class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        int a = 0;
        int b = 0;
        int mini = min(x, y);
        int ans = 0;
        for (char c : s)
        {
            if (c > 'b')
            {
                ans += min(a, b) * mini;
                a = 0;
                b = 0;
            }
            else if (c == 'a')
            {
                if (x < y && b > 0)
                {
                    b--;
                    ans += y;
                }
                else
                {
                    a++;
                }
            }
            else
            {
                if (x > y && a > 0)
                {
                    a--;
                    ans += x;
                }
                else
                {
                    b++;
                }
            }
        }
        ans += min(a, b) * mini;
        return ans;
    }
};