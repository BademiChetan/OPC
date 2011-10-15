#include <climits>
#include <cstring>
#include <iostream>
#include <cstdio>
 using namespace std;
#define ALPHABET_SIZE 128
 int count = 0;
short * compute_prefix_func(char *p, short len)
{
        short *pi = new short[len];
        short k = 0;
        pi[0] = k;
 
        for (int q=1; q<len; q++) {
                while (k>0 && p[k]!=p[q])
                        k = pi[k-1];
                if (p[k] == p[q])
                        k++;
                pi[q] = k;
        }
        return pi;
}
 
void prepare_badcharacter_heuristic(const char *str, size_t size, int result[ALPHABET_SIZE])
{
        size_t i;
 
        for (i = 0; i < ALPHABET_SIZE; i++)
                result[i] = -1;
 
        for (i = 0; i < size; i++)
                result[(size_t) str[i]] = i;
}
 
/* result is array of size size+1 holding the strong suffix rule results
   as described above */
void prepare_goodsuffix_heuristic(const char *normal, size_t size, int result[])
{
        char *left = (char *) normal;
        char *right = left + size;
        char reversed[size+1];
        char *tmp = reversed + size;
        size_t i,j;
        char test;
 
        /* reverse string */
        *tmp = 0;
        while (left < right)
                *(--tmp) = *(left++);
 
        short *prefix_reversed = compute_prefix_func(reversed, size);
 
        /* can't figure out how to handle first and last positions with the rest
        its algorithm is slightly different */
 
        //result of 0 will only be accessed when we find a match
        //so it stores the good suffix skip of the first character
        //(last in reverse calculation)
        result[0] = size - prefix_reversed[size-1];
        //The last value in the prefix calculation is always
        //the same for a string in both directions
 
        i = 1;
        result[size] = 1;
        while (prefix_reversed[i++])
                result[size]++;
 
        for (i=1; i<size; i++) {
                test = 0;
                for (j=i; j<size-1; j++) {                   
                        if (prefix_reversed[j] == i) {
                                test = 1;
                                if (prefix_reversed[j+1] == 0) {
                                        test = 2;
                                        break;
                                }
                        }
                }
 
                if (test == 1)
                        result[size-i] = size;
                else if (test == 2)
                        result[size-i] = j+1 - i;
                else
                        result[size-i] = size - prefix_reversed[size-1];
        }
 
        delete[] prefix_reversed;
}
/*
 * Boyer-Moore search algorithm
 */
void boyermoore_search(char *haystack, char *needle)
{
        /* Calc string sizes */
        size_t needle_len, haystack_len;
        needle_len = strlen(needle);
        haystack_len = strlen(haystack);
 
        /** Simple checks */
        if(haystack_len == 0)
                return;
        if(needle_len == 0)
                return;
        if(needle_len > haystack_len)
                return;
 
        /** Initialize heuristics */
        int badcharacter[ALPHABET_SIZE];
        int goodsuffix[needle_len+1];
 
        prepare_badcharacter_heuristic(needle, needle_len, badcharacter);
        prepare_goodsuffix_heuristic(needle, needle_len, goodsuffix);
 
        /** Boyer-Moore search */
        size_t s = 0;
        while(s <= (haystack_len - needle_len))
        {
                size_t j = needle_len;
                while(j > 0 && needle[j-1] == haystack[s+j-1])
                        j--;
 
                if(j > 0) {
                        int k = badcharacter[(size_t) haystack[s+j-1]];
                        int m;
                        if(k < (int)j && (m = j-k-1) > goodsuffix[j])
                                s+= m;
                        else
                                s+= goodsuffix[j];
                } else {
                        count++;
                        s += goodsuffix[0];
                }
        }
}
char buf[50005];
char temp[50005];
main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",buf);
        int i;
        scanf("%d",&i);
        while(i--)
        {
            int m,l;
            scanf("%d%d",&m,&l);
            strncpy(temp,buf+m,l);
            temp[l]='\0';
           // printf("%s\n",temp);
            count=0;
            boyermoore_search(buf, temp);
            printf("%d\n",count);               
        }
    }
        return 0;
}
