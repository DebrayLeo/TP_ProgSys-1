#include "headers.h"

int main() {
    displayWelcome();
    displayPrompt();
    while(1){
        executeCommand();
    }
    return EXIT_SUCCESS;
}
