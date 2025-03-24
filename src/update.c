#include "../include/update.h"
#include "../include/colors.h"

int updateSys() {
	printf(BOLD "Starting system updates." NORMAL "\n");
	int updateReturn = system("sudo dnf update -y");

	printf(BOLD "\nStarting flatpak updates." NORMAL "\n");
	int flatpakReturn = system("flatpak update -y");

	return updateReturn || flatpakReturn;
}
