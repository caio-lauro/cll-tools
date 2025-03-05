#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../include/help.h"
#include "../include/update.h"

int runCommand(char *cmd);

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("No command inserted. Use -h for help.\n"); 
		return 0; 
	}	

	int returnValueMatchCMD = runCommand(argv[1]);
	if (returnValueMatchCMD != 0) { 
		return returnValueMatchCMD; 
	}

	return 0; 
}

int TODOSMTH() {
	printf("TODO: Implement this one.\n");
	return 0;
}

int runCommand(char *cmd) {
	if (strcmp(cmd, "--help") == 0 || strcmp(cmd, "-h") == 0)
		return getHelp();
	if (strcmp(cmd, "update-system") == 0)
		return updateSys();
	
	printf("Command not yet created in runCommand.");
	return 2; 
}
