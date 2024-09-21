class Solution {
public:
    int minimumRecolors(string blocks, int k)
    {
        int res = INT_MAX;
        int count = 0;
        int i = 0;
        while (i < k)
        {
            if (blocks[i] == 'W')
                count++;
            i++;
        }
        res = min(res, count);

        for (int i = k; i < blocks.size(); i++)
        {
            if (blocks[i - k] == 'W' and blocks[i] == 'B')
                count--;
            if (blocks[i - k] == 'B' and blocks[i] == 'W')
                count++;
            res = min(res, count);
        }

        



        return res;
    }
};