
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int s, e, flag=0;
	printf("Enter starting and ending numbers: ");
	scanf("%d%d",&s, &e);

	printf("Prime Numbers between %d and %d are :\n", s, e);
	for(int i=s; i<=e; i++)
	{
		flag=0;
		for(int j=2; j<i; j++)
		{
			if(i%j==0)
			{
				flag = 1;
				break;
			}
		}
		if(flag==0)
			printf("%d  ",i);
	}
	return 0;
}