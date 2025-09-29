#include <iostream>
#include <memory>
#include <print>
#include <string>
#include <vector>

// This project needs an implementation of an ATS, not a binary tree
// For now... We will define a simple binary tree just for learning purposes
// Doing it in here just because I'm too lazy to create a new directory 
// and start a new project and all that jazz
struct Node {
	int data;
	std::unique_ptr<Node> left;
	std::unique_ptr<Node> right;

	Node(int d) : data(d), left(nullptr), right(nullptr) {};
};

struct Tree {
	std::unique_ptr<Node> root;
	int elems;

	Tree() : root(nullptr), elems(0) {};

public:
	void insert(int num) {
		Node* x = root.get();
		Node* y = nullptr;

		while (x != nullptr) {
			y = x;
			if (num < x->data) {
				x = x->left.get();
			} else {
				x = x->right.get();
			}
		}

		if (y == nullptr) {
			// root = node;
			root = std::make_unique<Node>(num);
			elems++;
		}
		else if (num < y->data) {
			y->left = std::make_unique<Node>(num);
			elems++;
		} else {
			y->right = std::make_unique<Node>(num);
			elems++;
		}
	}

	void print_tree() {
		Node* x = root.get();
    print_tree_helper(x);
		std::print("\n");
    std::println("{} nodes found", elems);
	}

private:
  void print_tree_helper(Node *node) {
    if (node == nullptr) {
      return;
    }

    print_tree_helper(node->left.get());
    std::print("{} ", node->data);
    print_tree_helper(node->right.get());
  }
};

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

  std::vector<int> nums = {70, 5, 2, 4, 8, 7, 3, 3};
  Tree tree = Tree();

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
