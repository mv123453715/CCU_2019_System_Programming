#include "apue.h"

int main(void)
{
	char buf[MAXLINE];
	long long int count = 0;
	while( (fgets(buf,MAXLINE,stdin)) != NULL ){
     
		if(fputs(buf,stdout) == EOF)
			err_sys("output error");
     else
       count++;
	}//while
	if(ferror(stdin))
		err_sys("input error");
  printf( "Loop Iterations:%lld\n",count );
	exit(0);
}

