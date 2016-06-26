#include <iostream>
#include "detect_vm.h"

#define UR_INSIDE "Yes, You are inside "

int main() {
	if (IsVirtualBox()) {
		std::cout << UR_INSIDE "vBOX" << std::endl;
	}
	else if (IsVmWare()) {
		std::cout << UR_INSIDE "VmWare" << std::endl;
	}
	else if (IsHypervisor() || IsVirtualPC() || IsSandboxiePresent() || IsParallels() || IsUnknownVM()) {
		std::cout << UR_INSIDE "other VM" << std::endl;
	}
	std::cout << "press enter to exit...";
	std::cin.ignore();

	return 1;
}