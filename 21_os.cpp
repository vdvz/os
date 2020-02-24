#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <stdlib.h>

int count;

void sigcatch(int sig){
    signal(sig, SIG_IGN);
    if (sig == SIGQUIT) {
        printf("\n%d signal(s) receive\n", count);
        exit(1);
    }
    if(sig == SIGINT){
        //TODO сделать так чтобы звук выводился при подключении по ssh 
        putchar('\007');
        count++;
    }
    signal(sig, sigcatch);
}

int main(){
    int number, divisor;
    void sigcatch(int);
    
    signal(SIGINT, sigcatch);
    signal(SIGQUIT, sigcatch);
    while(1){

    }

return 0;
}



