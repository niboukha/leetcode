class Solution {
public:
    void duplicateZeros(vector<int>& arr)
    {
        int count = 0;
        for (int i = 0; i < arr.size(); i++)
            if (arr[i] == 0)
                count++;

        int left = arr.size() - 1;
        int right = arr.size() - 1 + count;
        while (left < right)
        {
            if (right < arr.size())
                arr[right] = arr[left];
            right--;
            if (arr[left] == 0)
            {
                if (right < arr.size())
                    arr[right] = arr[left];
                right--;
            }
            left--;
        }
    }
};
