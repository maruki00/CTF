#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc,char*argv[])
{

	time_t t = time(NULL);
	srand(t);
	char buff[100];
	for (int i=0; i < 30; i++)
	{
		printf("%d\n", rand() & 0xf);
	}

    return 0;
}
