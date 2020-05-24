/*  1. input n
    2. print n
    3. if n = 1 then STOP
    4. if n is odd then n  <- 3n + 1
    5. else n  <- n/2
    6. GOTO 2
Input
    The input will consist of a series of pairs of integers i and j, one pair of integers per line. All integers
    will be less than 10,000 and greater than 0.
    You should process all pairs of integers and for each pair determine the maximum cycle length over
    all integers between and including i and j.
    You can assume that no operation overflows a 32-bit integer.
Output
    For each pair of input integers i and j you should output i, j, and the maximum cycle length for integers
    between and including i and j. These three numbers should be separated by at least one space with all
    three numbers on one line and with one line of output for each line of input. The integers i and j must
    appear in the output in the same order in which they appeared in the input and should be followed by the maximum cycle length (on the same line).
*/
#include<stdio.h>

int ALGO(int n)
{
     if(n == 1)
        return 1;
     if(n%2)
        return 1 + ALGO(3*n + 1);
     else
        return 1 + ALGO(n/2);
}

int main()
{
    int i, j, count, length, temp;
    while(scanf("%d %d",&i, &j) != EOF){
        printf("%d %d ", i, j);
        if(i > j){
            temp = i;
            i = j;
            j = temp;
        }
        for(length = 0, count = i ; count <= j ; count++){
            temp = ALGO(count);
            if(temp > length)
                length = temp;
        }
        printf("%d\n", length);
    }
}
