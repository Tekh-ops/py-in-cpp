#include <stdio.h>
#include <math.h>

int main()
{
	int a = 1;

	for(int i = 0;i<=3;i++)
	{
		a = pow(2,a);
	}
	printf("%d\n",a);
	return 0;
}
