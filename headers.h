#ifndef TPPROGSYSSHELL_HEADERS_H

// Include section

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/wait.h>

// Macro section

#define WELCOME_MESSAGE "Bienvenue dans le Shell de l'ENSEA\nPour sortir taper exit\n"
#define PROMPT "ENSEASH %  "
#define COMMAND_DON_T_EXIST "Command %s doesn't exist\n"
#define MAX_COMMAND_SIZE 512
#define MAX_OUTPUT_SIZE 128
#define EXIT_MESSAGE "Bye bye...\n"
#define PROMPT_SIGN "ENSEASH[sign:%d | time:%d ms] %% "
#define PROMPT_EXIT "ENSEASH[exit:%d | time:%d ms] %% "

// Prototype section

void displayWelcome();
void displayPrompt();
void executeCommand();
void displayNextPrompt();

#define TPPROGSYSSHELL_HEADERS_H

#endif //TPPROGSYSSHELL_HEADERS_H
