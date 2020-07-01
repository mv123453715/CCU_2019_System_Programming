#include "apue.h"

int main(void)
{
	char buf[MAXLINE];
	long long int count = 0;
  setvbuf(stdin, buf, _IONBF, MAXLINE);
	while( (fgets(buf,MAXLINE,stdin)) != NULL ){
     count++;
		if(fputs(buf,stdout) == EOF)
			err_sys("output error");
	}//while
	if(ferror(stdin))
		err_sys("input error");
  printf( "Loop Iterations:%lld\n",count );
	exit(0);
}

