#include "headers.h"

void displayWelcome(){
    write(STDOUT_FILENO,WELCOME_MESSAGE,sizeof(WELCOME_MESSAGE)-1);
}

void displayPrompt(){
    write(STDOUT_FILENO,PROMPT,sizeof(PROMPT)-1);
}

void displayNextPrompt(int status, int delay) {
	char buffer[MAX_COMMAND_SIZE];
	if (WIFEXITED(status)) {
		sprintf(buffer, PROMPT_EXIT, WEXITSTATUS(status), delay);
	}
	else {
		sprintf(buffer, PROMPT_SIGN, WTERMSIG (status), delay);
	}
	write(STDOUT_FILENO,buffer, strlen (buffer));
}
