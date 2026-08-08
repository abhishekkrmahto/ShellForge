#include <stdio.h>
#include <stdlib.h>
#include <string.h>          // Fixed: Changed "String.h" to lowercase "string.h"
#include <readline/history.h>
#include <readline/readline.h>
#include "history.h"

int main(){
    printf("----------------------------------------------------\n"); // Fixed: 'prinf' to 'printf'
    printf("                  SHELL-FORGE                       \n");
    printf("          A unix style shell written in C           \n");
    printf("----------------------------------------------------\n"); // Fixed: 'prinf' to 'printf'

    // INITIALIZING HISTORY !!
    using_history();

    char *line;
    while(1){
        line = readline("shellforge$ ");
        if(line == NULL){
            printf("WRONG COMMAND !!\n");
            break;
        }
        if(strlen(line) == 0){
            free(line);      // Added: Free empty lines to prevent memory leaks
            continue;
        }

	if(strcmp(line,"history")==0){
	    print_history();
	    free(line);
	    continue;
	}

	add_history(line);
	printf(" YOU ENTERED : %s\n",line);
	if(strcmp(line,"exit") == 0){
	    free(line);
	    printf("Exiting...\n");
	    break;
	}

	free(line);

    }
    return 0;
}




