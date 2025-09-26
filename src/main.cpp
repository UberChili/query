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
		} else {
			break;
		}

		// TODO
		// We would do some kind of processing here
		// Maybe we just call a function that _parses_
		// parse(input);
	} while (true);
}

void parse(std::string query) {
	if (query.empty()) {
		std::println("Empty query");
		return;
	}
}

int main(void) {
	prompt();

	return 0;
}
