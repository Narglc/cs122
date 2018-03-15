#include<stdio.h>
#include<stdlib.h>
int main(){
  char cmd[5];
  while(1){
    scanf("%s",cmd);
    printf("%s",cmd);
    if(strcmp(cmd,"a")==0){
      printf("choice is a\n");
    }else if(!strcmp(cmd,"b")==0){
      printf("choice is b\n");
    }else if(strcmp(cmd,"quit")==0){
      printf("choice is quit\n");
      exit(0);
    }else{
      printf("Wrong cmd!\n");
    }
  }
  return 0;
}

