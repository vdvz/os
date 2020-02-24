#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char ch;
    struct termios tty, savtty;

    int fd = open("/dev/tty", O_RDONLY);
    tcgetattr(fd, &tty);
    if (isatty(fileno(stdout)) == 0) {
        fprintf(stderr,"stdout not terminal\n");
        exit(1);
    }

    savtty = tty;
    tty.c_lflag &= ~(ISIG | ICANON | ECHO);
    tty.c_cc[VMIN] = 1;     /* MIN */
    tcsetattr(fd, TCSAFLUSH, &tty);
    setbuf(stdout, (char *) NULL);
    printf("Awesome?(y/n):\n");
    
    read(fd, &ch, 1);
    putchar(ch);

    /*len = strlen(text);
    for (i = 0; i < len; i++) {
        read(fd, &ch, 1);
        if (ch == text[i]){
                    putchar(ch);
        }
        else {
            putchar('\07');
            putchar('*');
            errors++;
        }
    }*/

    tcsetattr(fd, TCSAFLUSH, &savtty);
    
    printf("\nYour answer is: %c\n", ch);

    return 0;
}