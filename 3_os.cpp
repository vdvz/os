#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(){

    printf("%ui\n", getuid());
    printf("%ui\n", geteuid());

    FILE *file; 
    
    if ((file = fopen("file", "w"))==NULL) {
        perror("can't open \"file\"");
        exit(1);
    }

    fclose(file);

    setuid(geteuid());
    
    printf("%ui\n", getuid());
    printf("%ui\n", geteuid());

    FILE *file; 
    
    if ((file = fopen("file", "w"))==NULL) {
        perror("can't open \"file\"");
        exit(1);
    }

    fclose(file);

    return 0;
}