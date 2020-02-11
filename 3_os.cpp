#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(){

    printf("%u\n", getuid());
    printf("%u\n", geteuid());

    FILE *file; 
    
    if ((file = fopen("file", "w"))==NULL) {
        perror("can't open \"file\"");
        
    }else{
        printf("Success!\n");
        fclose(file);
    }
    setuid(geteuid());
    
    printf("%u\n", getuid());
    printf("%u\n", geteuid());

    if ((file = fopen("file", "w"))==NULL) {
        perror("can't open \"file\"");
        
    }else{
        printf("Success!\n");
        fclose(file);
    }
    return 0;
}