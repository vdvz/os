#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

struct list{
    int offset;
    struct list * next;
};

int main (){
    int N = 30;
    //dp - дескриптор файла начиная с 3; 0,1,2 - потоки инпут аутпут и ерор
    int dp = open("text", O_RDWR);
    
    struct list * head =(struct list*)malloc(sizeof(struct list));
    struct list * itter = head;
    int max_offset = 0;
    char str[1];
    int file_offset = 0;
    while(read(dp, &str, sizeof(char))){
        file_offset++;
        if(str[0] == '\n'){
            if(max_offset<file_offset){
                max_offset = file_offset;
            }
            itter->offset = file_offset;
            struct list * body =(struct list*)malloc(sizeof(struct list));
            body->offset = -1;
            body->next = NULL;
            itter->next = body;
            itter = itter->next;
            file_offset = 0;
        }
        lseek(dp,0L,SEEK_CUR);
    }

    itter->offset = file_offset;
 /* TODO parsing line from keyboard 
    char line_number_str[10];
    printf("Enter number of the required line: ");
    scanf("%s", &line_number);
    //parse
    int line_number = 0;
    while
*/
    int line_number = 2;

    lseek(dp, 0L, SEEK_SET);   
    if(line_number == 0){
    char * string = (char*)malloc(max_offset*sizeof(char));
    itter = head;
    while(itter->next){
        read(dp, string, (itter->offset-1)*sizeof(char));
        puts(string);
        lseek(dp, 1L, SEEK_CUR);
        itter = itter->next;
    }
    free(string);
    }else{
        int offset = 0;
        itter = head;
        for (int line = 1; line < line_number; line++){
            offset += itter->offset;
            itter = itter->next;
        }   
        char * string = (char*)malloc((itter->offset-1)*sizeof(char));
        lseek(dp, offset, SEEK_SET);
        read(dp, string, itter->offset*sizeof(char));
        puts(string);
        free(string);
    }

    itter = head;
    struct list * sub = head;
    while(itter->next){
        //printf("%d\n", itter->offset);
        sub = itter;
        itter = itter->next;
        free(sub);
    }

    return 0;
}