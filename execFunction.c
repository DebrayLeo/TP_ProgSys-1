#include "headers.h"

void executeCommand(){
    int nbCharRead;
    int status;
    int delay;
    struct timespec start, stop;
    char buffer[MAX_COMMAND_SIZE];
    char output_buffer[MAX_OUTPUT_SIZE];
    char *token;
    char * argv[5]={0};
    int i;
    char test;
    
    nbCharRead=read(STDIN_FILENO,buffer,MAX_COMMAND_SIZE);
    clock_gettime(CLOCK_MONOTONIC, &start);
    buffer[nbCharRead-1]='\0';
    
    if (strcmp(buffer,"exit")==0){
		write(STDOUT_FILENO, EXIT_MESSAGE, sizeof(EXIT_MESSAGE)-1);
		exit (EXIT_SUCCESS);
	}
	
	for(i=0;test==NULL;i++){
		argv[i] = strtok(buffer," ");
		test = argv[i];
	}
    
    if (fork()==0){
        //execvp(argv[0],argv); 		cette ligne est en commentaire car tant que les fonction ci-dessous ne sont pas modifiées le terminal n'éxécute plus la commande
        execlp(buffer,buffer,NULL);
        sprintf(output_buffer,COMMAND_DON_T_EXIST,buffer);
        write(STDOUT_FILENO,output_buffer,strlen(output_buffer));
        exit(EXIT_FAILURE);
    }
	else {
		wait(&status);
	}
	
	clock_gettime(CLOCK_MONOTONIC, &stop);
	delay = ((stop.tv_nsec-start.tv_nsec)/1000000);
    
    displayPrompt();
    displayNextPrompt(status,delay);

}
