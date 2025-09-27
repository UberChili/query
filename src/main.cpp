#include <iostream>
#include <print>
#include <cstdlib>
#include <string>

std::string prompt() {
	std::string input;
	do {
		std::print("prompt> ");
		std::getline(std::cin, input);
		if (input.empty()) {
			continue;
		} else {
			std::print("\t{}\n", input);
			return input;
		}
	} while (true);
}

void parse(std::string query) {
	if (query.empty()) {
		std::println("Empty query");
		return;
	}
}

int main(void) {
	// First clear of screen
	system("clear");

	while (true) {
		std::string in_prompt = prompt();
		// Process the string, parse to AST
	};

	return 0;
}
