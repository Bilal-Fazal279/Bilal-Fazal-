#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){

pid_t pid= fork();
if(pid<0){
fprintf(stderr , "Fork failed \n");
return 1;
}else if(pid>0){
char *dirName = "Aliza Sakhawat";
if(mkdir(dirName , 0777)== -1){
perror("Error Creating Directory");
exit(EXIT_FAILURE);
}


wait(NULL);

}else{
char fileName[] = "Aliza_Sakhawat.txt";
FILE *file = fopen(fileName , "w");

if(file == NULL){
perror("Error Creating File");
exit(EXIT_FAILURE);
}
printf("\n\nIn Child Process created file name--: %s",fileName);
printf("\n\n");
fclose(file);

exit(EXIT_FAILURE);

}


return 0;
}
