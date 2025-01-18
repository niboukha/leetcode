
class Solution 
{
    public:
        string addBinary(string a, string b)
        {
            string  num;
            int rem = 0;
            size_t lena = a.length();
            size_t lenb = b.length();

            if (a[0] == '0' && lena == 1 && b[0] == '0' && lenb == 1)
                return ("0");
            for (int i = 0; i < max(a.length(), b.length()); i++)
            {
                if (lena > 0) lena--;
                else a[lena] = '0';
                
                if (lenb > 0)  lenb--;
                else  b[lenb] = '0';
                
                num += (((a[lena] - 48) ^ (b[lenb] - 48)) ^ rem) + 48;

                if (!rem)  rem = ((a[lena] - 48) & (b[lenb] - 48));
                else rem = ((a[lena] - 48) | (b[lenb] - 48));
            }

            if (rem)
                num += rem + 48;
                
            reverse(num.begin(), num.end());
            return (num);
        }
};
