#include "apue.h"
#include <sys/wait.h>
#include <string.h>
#include <stdbool.h>
#include<time.h>
//#include<readline/readline.h>
//#include<readline/history.h>

static void	sig_int(int);		/* our signal-catching function */
int main(void)
{
		char	buf[MAXLINE];	/* from apue.h */
		pid_t	pid;
		int		status,i,argv_num = 0,history_num = 0 ,temp = 0,times = 1;
    char *token ;
    char* argv[100];
    char history[1000][MAXLINE];
    const char s[2] = " ";
    bool debug = false;
    bool parent = false;
    time_t now[1000];
    //struct tm *timenow[1000];

		if (signal(SIGINT, sig_int) == SIG_ERR) // signal 呼叫
				err_sys("signal error");

		printf("## ");	/* print prompt (printf requires %% to print %) */
		while (fgets(buf, MAXLINE, stdin) != NULL) {
        argv_num = 0;
        
        if (buf[strlen(buf) - 1] == '\n')
						buf[strlen(buf) - 1] = 0; /* replace newline with null */
        
        //history                 
        if ( strlen(buf) >= 1 && buf[0] != '\n'&& buf[0] != '!' ){
            strcpy(history[history_num],buf);
            time(&now[history_num++]); 
        }//if
            

  


        if ( buf[0] == '!'){
            temp = 0 ;
            times = 1;
            for( i = strlen(buf)-1;i>0;i-- ){
                temp = temp + (buf[i] - '0')*times;
                times = times *10;
            }//for 
            if ( temp>history_num-1 ){
                printf( "Error! Iuput num is more than history num!\n" );
                printf( "## " );
                continue;
            }//if
            else{
              strcpy( buf,history[temp] );
              printf( "%s\n",buf );
            }//else
            
        }//if          

         //擷取字串
         token = strtok(buf, s);
   
         /* walk through other tokens */
         while( token != NULL ) {
            argv[argv_num++] = token;
            
            if ( debug == true ){
                printf( "token:%s\n",token );
                printf( "argv:%s\n",argv[argv_num-1] );
            }//if
            token = strtok(NULL, s);
        }//while


        if ( debug == true ){
            printf( "strlen(buf):%zu\n",strlen(buf) );   //%zu  size_t專用
            printf( "argv_num:%d\n",argv_num );
        }//if
                
        //追加NULL結尾
        argv[argv_num] = NULL;
        

        
        
        //built-in command  parent exec
        if ( argv_num > 0 && strcmp( argv[0],"cd" ) ==0 ){
            parent = true;
            chdir( argv[1] );
        }//if
        else if ( argv_num > 0 && (strcmp( argv[0],"logout" ) ==0 
                                  || strcmp( argv[0],"exit" ) ==0) ){
            parent = true;
            exit(0);
        }//else if
        else if ( argv_num > 0 && strcmp( argv[0],"history" ) ==0 ){
            parent = true;
            for (i = 0 ; i<history_num;i++)
                printf( "%5d  %s  %s\n",i,ctime(&now[i]),history[i] ); //asctime(timenow[i])將時間資料結構轉成字串
        }//else if
            


             
             
             

        
        //else command child exec  
				else if ((pid = fork()) < 0) {
						parent = false;
            err_sys("fork error");
				}//else if 
        else if (pid == 0) {		/* child */
            parent = false;
            execvp(argv[0],argv);
						err_ret("couldn't execute: %s", buf);
						exit(127);
				}//else if

				/* parent */
        //parent == false && 
        
        
        if ( debug == true && parent == true )
            printf( "this is parent!\n" );
        else if ( debug == true && parent == false )
            printf( "this is child!\n" );
            
            
            
        if ( parent == false  ){
				    if ((pid = waitpid(pid, &status, 0)) < 0)
						    err_sys("waitpid error");
        }//if
        printf("## ");
        
        for ( i =0; i<MAXLINE;i++ )
            buf[i] = ' ';
        parent = false;
        
		}//while
		exit(0);
}//mian

		void
sig_int(int signo)
{
		printf("interrupt\n## ");
}

