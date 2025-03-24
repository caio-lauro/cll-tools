#include "../include/error.h"

int commandNotFound() {
	printf("Command not found. Use --help or -h for help.\n");
	return 1;
}

int wrongUsage() {
	printf("Wrong usage. Use --help or -h for help.\n");
	return 2;
}

int throwError(int errorCode) {
	switch (errorCode) {
		case 1:
			return commandNotFound();
		case 2:
			return wrongUsage();
		default:
			printf("Misusage of throwError, error code not found.\n");
			return -1;
	}
}
