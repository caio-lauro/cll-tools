#include "../include/help.h"

void printCommandsHelp();

int getHelp() {
	printf(BOLD "Usage:" 
		NORMAL "\n\tcll-tools [OPTIONS] COMMAND\n");

	printf(BOLD "Description:" 
		NORMAL "\n\tcll-tools is a program designed and mantained by Caio Lauro to provide assistance in various tasks he does.\n");

	printf(BOLD "Software Options and Commands:" NORMAL "\n");
	printCommandsHelp();

	return 0;
}

void printCommandsHelp() {
	printf("\t-h, --help\t\t\t");
	printf("Provides help for the user.\n");

	printf("\tupdate-system, system-update\t");
	printf("Updates the sytem when needed.\n");
}
