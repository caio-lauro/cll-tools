#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "../include/update.h"

int matchCommand(char *cmd);

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("No command inserted. Use -h for help.\n"); 
		return 0; 
	}	

	int returnValueMatchCMD = matchCommand(argv[1]);
	if (returnValueMatchCMD != 0) { 
		return returnValueMatchCMD; 
	}

	return 0; 
}

int runCommand(int commandCode) { 
	switch (commandCode) { 
		case 0:
			printf("TODO: Implement -h.\n");
			return 0;
		case 1: 
			return updateSys();
		default:
			printf("Command not yet created in switch case of runCommand.");
			return 2; 
	}
}

int matchCommand(char *cmd) {
	int COMMAND_COUNT = 2;
	char commands_list[][51] = {"-h", "update-system"};
	
	bool commandFound = false;
	for (int i = 0; i < COMMAND_COUNT; i++) {
		if (strcmp(commands_list[i], cmd) == 0) {
			runCommand(i);
			commandFound = true;
			break;
		}
	}

	if (!commandFound) {
		printf("Command not found use -h for help.\n");
		return 1;
	}

	return 0;
}
