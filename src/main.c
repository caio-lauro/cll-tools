#include <stdio.h>
#include <string.h>

#include "../include/options.h"
#include "../include/error.h"
#include "../include/help.h"
#include "../include/update.h"

int runCommand(int argc, char *argv[]);

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("No command inserted. Use -h for help.\n"); 
		return 0; 
	}	

	int returnValueRunCMD = runCommand(argc, argv);
	if (returnValueRunCMD != 0) { 
		return returnValueRunCMD; 
	}

	return 0; 
}

int TODOSMTH() {
	printf("TODO: Implement this one.\n");
	return 0;
}

int runCommand(int argc, char *argv[]) {
	int opt; 
	while ((opt = getopt_long(argc, argv, "h", long_options, NULL)) != -1) {
		switch (opt) {
			case 'h':
				if (argc != 2)
					return throwError(2);
				return getHelp();
			default:
				return throwError(2);
		}
	}

	char *cmd = argv[optind];

	if (strcmp(cmd, "update-system") == 0 || strcmp(cmd, "system-update") == 0) {
		if (argc != 2)
			return throwError(2);
		return updateSys();
	}

	return throwError(1);
}
