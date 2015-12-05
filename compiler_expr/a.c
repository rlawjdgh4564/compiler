#include <stdio.h>
#include <sys/types.h>
#include <time.h>

void main()
{
	time_t t;
	struct tm *tm;
	time(&t);
	printf("%s", ctime(&t));
	tm = localtime(&t);
	printf("The current year is %d.\n", 1900+tm->tm_year);
}