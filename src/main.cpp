#include "bst.hpp"
#include <iostream>
#include <print>
#include <string>
#include <vector>

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

  // Testing our tree
  std::vector<int> nums = {70, 5, 2, 4, 8, 7, 3, 3};
  Tree tree =  Tree();
  for (const auto& num : nums) {
    tree.insert(num);
  }
  tree.print_tree();

	// while (true) {
	// 	std::string in_prompt = prompt();
	// 	// Process the string, parse to AST
	// };

	return 0;
}
