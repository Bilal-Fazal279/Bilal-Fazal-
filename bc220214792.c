#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){

pid_t pid;
pid = fork();
if(pid<0){
fprintf(stderr , "Fork failed \n");
return 1;
}else if(pid>0){
char dirName[] = "Bilal Fazal";
if(mkdir(dirName , 0777)== -1){
perror("Error Creating Directory");
exit(EXIT_FAILURE);
}
//printf("\nParent Process created directory with name: %s\n",dirName);
wait(NULL);
}else{
char fileName[] = "Bilal_Fazal.txt";
FILE *file = fopen(fileName , "w");

if(file == NULL){
perror("Error Creating File");
exit(EXIT_FAILURE);
}
printf("\nIn Child Process created file name--: %s\n",fileName);
fclose(file);

exit(EXIT_FAILURE);

}


return 0;
}
