#include "apue.h"

int main(void)
{

	int c;
	long long int count = 0;
	while( (c = getc(stdin)) != EOF ){
		count++;
    if(putc(c,stdout) == EOF)
			err_sys("output error");
  }//while
		
	if(ferror(stdin))
		err_sys("input error");
  printf( "Loop Iterations:%lld\n",count );
	exit(0);
}

