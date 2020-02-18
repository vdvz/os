#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <unistd.h>
#include <ulimit.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

 int main(int argc, char *argv[])
 {
     //после опций с параметрами ставится двоеточие
     char options[ ] = "ispuU:cC:dv:V:";  /* valid options */cd 
/*
    optarg – указатель на текущий аргумент, если таковой имеется.
    optind – индекс на следующий указатель argv, который будет обработан при следующем вызове getopt().
    optopt – последний из известных параметров.
*/
      while ((c = getopt(argc, argv, options)) != EOF) {
      switch (c) {
      case 'v':
      {     //system("env");
            char* pPath;
            pPath = getenv(optarg);
            if (pPath!=NULL)
                  printf ("Enviroments: %s\n",pPath);
            else 
                  perror("getenv() error\n");
            break;
      }
      case 'V':
      {
            char name[256];
            char value[256];
            char flag = 0;
            for(int i = 0;i<strlen(optarg);i++){
                  if(optarg[i]=='='){
                        flag=1;
                  }
                  if(flag){
                        value[i]=optarg[i];
                  }
                  if(!flag){
                        name[i]=optarg[i];
                  }
            }
            if(!flag){
                  perror("bad name\n");
                  break;                 
            }
            if(!setenv((const char * )&name,(const char *)&value, 1)){
                  printf("Succes set name:%s to value:%s\n", &name, &value);
            }else{
                  perror("setenv() error\n");
            }
            break;
      }
      case 'i':
            printf("real user id: %ui\n", getuid());
            printf("effective user id: %ui\n", geteuid());
            printf("real group id: %ui\n", getgid());
            printf("effective group id: %ui\n", getegid());
            break;
      case 's':
      {
            pid_t process_id = getpid();
            pid_t group_id = getpgid(process_id);
            if(!setpgid(process_id, group_id))
                  printf ("process %d is leader of %d\n", process_id, group_id);
            else
                  perror("setpgid() error\n");
            break;
      }
      case 'p':
      {
            pid_t process_id = getpid();
            printf ("process_id: %d\n", process_id);
            printf ("parent_process_id: %d\n", getppid());
            printf ("group_process_id: %d\n", getpgid(process_id));
            break;
      }
      case 'd':
      {     
            char cwd[256];
            if (getcwd(cwd, sizeof(cwd)) == NULL)
                  perror("getcwd() error\n");
            else
                  printf("Current working directory is: %s\n", cwd);
            break;
      }
      case 'c':
      {
            struct rlimit core;
            if(!getrlimit(RLIMIT_CORE, &core)){
                  printf("Alloweable size of core-file: %d\n", core.rlim_cur);
            }else{
                  perror("getrlimit() error\n");
            }
            break;
      }
      case 'u':
      {
            int ulimit_ = ulimit(UL_GETFSIZE);
            if(ulimit_==-1)
                  perror("ulimit() error\n");
            else
                  printf("ulimit is: %d\n", ulimit_);
            break;
      }
      case 'U':
      {
            break;
      }
      case '?':
            printf("invalid option is %c\n", optopt);
            invalid++;
      }
      }
     return 0;
 }