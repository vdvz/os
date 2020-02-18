#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(){

    //chmod g+s -> set UID, SUID when start process executing, now disable
    // Реальный идентификатор пользователя данного процесса - идентификатор пользователя щапустившего Этот процесс
    // Эффективный идентификатор пользователя служит для определения прав доступа к системным ресурсам (ресурсам файловой системы)
    printf("%u\n", getuid());
    printf("%u\n", geteuid());

    FILE *file; 
    
    if ((file = fopen("file", "w"))==NULL) {
        perror("can't open \"file\"");
        
    }else{
        printf("Success!\n");
        /*//chmod g+s make different uid and euid
        printf("%u\n", getuid());
        printf("%u\n", geteuid());    
        */
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