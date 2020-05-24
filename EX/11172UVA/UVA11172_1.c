#include <stdio.h>

int main()
{
	int a , b , c;
	for(scanf("%d" , &a) ; a--!=0 && scanf("%d %d" , &b , &c);)
		printf("%c\n", b > c ? '>' : b < c ? '<' : '=');
}
