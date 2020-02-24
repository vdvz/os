#include <stdio.h>
#define TRUE 1
#define FALSE 0

int main(int argc, char **argv){
    FILE *fpin, *fpout;
    char line[BUFSIZ];

    if ((fpin = fopen(argv[1], "r")) == (FILE *) NULL) {
        perror(argv[0]);
        return 1;
    }

    fpout = popen("wc -l", "w");
    while (fgets(line, BUFSIZ, fpin) != (char *)NULL){
        if (line[0] == '\n'){
            fputs(line, fpout);
        }
    }

    fclose(fpin);
    pclose(fpout);

    return 0;
}