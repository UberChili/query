#include <iostream>
#include <print>
#include <cstdlib>

void prompt() {
	system("clear");

	std::string input;
	do {
		std::print("promt> ");
		std::cin >> input;
		if (input.empty()) {
			continue;
		}
		// We would do some kind of processing here
	} while (true);
}

int main(void) {
	std::println("Here I go killing again!");

	prompt();

	return 0;
}
