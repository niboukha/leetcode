class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr)
    {
        vector<int> res;
        std::map<int, std::set<int>> hash;

        for (int i = 0; i < arr.size(); i++)
            hash[arr[i]].insert(i);
        int i = 0;
        for (auto it = hash.begin(); it != hash.end(); it++)
        {
            for (const auto& value : it->second)
                arr[value] = i + 1;
            i++;
        }

        return arr;
    }
};
