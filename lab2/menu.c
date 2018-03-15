#include<stdio.h>
int main(){
  char cmd[5];
  while(1){
    scanf("%s",cmd);
    printf("%s",cmd);
    if(!strcmp(cmd,"a")){
      printf("choice is a\n");
    }else if(!strcmp(cmd,"b")){
      printf("choice is b\n");
    }else if(!strcmp(cmd,"quit")){
      printf("choice is quit\n");
      break;
    }
  }
  return 0;
}

