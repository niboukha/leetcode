class Solution {
public:
    int hIndex(vector<int>& citations)
    {
        sort(citations.begin(), citations.end(), greater<>());
        for (int i = 0; i < citations.size(); i++)
        {
            if (citations[i] < i + 1)
                return i;
        }
        return citations.size();
    }
};