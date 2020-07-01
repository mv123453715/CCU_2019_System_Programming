#include "apue.h"
#include <fcntl.h> // for open
#include <unistd.h> // for close

//#define	BUFFSIZE	100
#define	BUFFSIZE	4096
//#define	BUFFSIZE	8192
//#define	BUFFSIZE	16384

int main(void)
{
		int		n;
		char	buf[BUFFSIZE];

    int null_fd = open( "/dev/null", O_WRONLY );
		while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
				if (write(null_fd, buf, n) != n)
						err_sys("write error");

		if (n < 0)
				err_sys("read error");

		exit(0);
}

