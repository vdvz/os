 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>


#define MAX_LENGHT 30

struct node {
    char *string;
    node * next_string = NULL;
};

int main(){
    char str[MAX_LENGHT];
    node * prev_node = NULL;
    node * head = NULL;
    fgets(str, MAX_LENGHT, stdin);
    while(str[0] != '.'){
        size_t size = strlen(str);
        struct node * current = (struct node*)malloc(sizeof(struct node));
        current->string = (char*)malloc(size*sizeof(char));
        //strcpy(current->string, str);
        //puts(current->string);
        memcpy(current->string, str, size-sizeof(char));
        if(!head){
            head = current;
        }else{
            prev_node->next_string = current;
        }
        prev_node = current;
        fgets(str, MAX_LENGHT, stdin);
    }

    while(head != NULL){
        prev_node = head;
        puts(head->string);
        head = prev_node->next_string;
        free(prev_node->string);
        free(prev_node);
    }

    return 0;
}