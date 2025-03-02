#include <stdio.h>
#include <stdlib.h>
#include "../include/update.h"

int updateSys() {
	printf("Starting system updates.\n");
	int updateReturn = system("dnf update -y");

	printf("\nStarting flatpak updates.\n");
	int flatpakReturn = system("flatpak update -y");

	return updateReturn || flatpakReturn;
}
