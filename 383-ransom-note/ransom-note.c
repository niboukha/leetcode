bool canConstruct(char * ransomNote, char * magazine){
    int arr[26] = {0};
    int tab[26] = {0};

    for (int i = 0; i < strlen(magazine); i++)
        arr[magazine[i] - 97] += 1;
    for (int i = 0; i < strlen(ransomNote); i++)
        tab[ransomNote[i] - 97] += 1;
    int i = 0;
    while (i < 26)
    {
        if (arr[i] < tab[i])
            return (false);
        i++;
    }
    return (true);
}