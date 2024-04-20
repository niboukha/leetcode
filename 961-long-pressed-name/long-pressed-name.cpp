class Solution {
public:
    bool isLongPressedName(string name, string typed)
    {
        int firstName = 0;
        int lastName = 0;
        int firstType = 0;
        int lastType = 0;
        int len = 0;

        if (typed.size() < name.size())
            return false;
        while (lastType < typed.size())
        {
            while (typed[firstType] == typed[lastType] )
                lastType++;
            if (lastType == typed.size() or typed[firstType] != typed[lastType])
            {
                len = lastType - firstType;
                if (typed[firstType] != name[firstName])
                    return false;
                firstType = lastType;
            }
            while (name[firstName] == name[lastName])
                lastName++;
            if (lastName == name.size() or name[firstName] != name[lastName])
            {
                // cout << name[lastName] << "\n";
                if (len < lastName - firstName or typed[lastType] != name[lastName])
                    return false;
                firstName = lastName;
            }
        }
        return true;        
    }
};