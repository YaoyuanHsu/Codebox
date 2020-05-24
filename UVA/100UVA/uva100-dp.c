#include<stdio.h>
#define SIZE 10000
#define MAX(x,y) (x > y ? x : y)
#define MIN(x,y) (x < y ? x : y)

int length[SIZE + 1] = {0, 1};

int ALGO(int i)
{
     if(i == 1)
        return 1;
     if(i<=SIZE && length[i])
        return length[i];
     else if(i&1)
        return ALGO((3*i+1)>>1) + 2;
     else
        return ALGO(i>>1) + 1;
}

int main()
{
    int i, j, count, maxLength, temp;
    while(scanf("%d %d",&i, &j) != EOF){
        maxLength = 0;
        for(count = MIN(i, j) ; count <= MAX(i, j) ; count++)
            maxLength = MAX(maxLength, ALGO(count));
        printf("%d %d %d\n", i, j, maxLength);
    }
}
