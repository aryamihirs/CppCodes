#include<stdio.h>
void func(int);

struct abc
{
	int x;
}obj;

static int value = 5;
int main(){
	printf("%ld\n", sizeof(obj));
	return 0;
}
