int revnum(int n)
{
    unsigned int rest, rev = 0;
    while (n > 0)
    {
        rest = n % 10;
        rev = rev*10 + rest;
        n /= 10;
    }
    return (rev);
}


bool isPalindrome(int x){

    while (x >= 0)
    {
        if (x == revnum(x))
            return (true);
        else
            return (false);
    }
    return (false);
}
