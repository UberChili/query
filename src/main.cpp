#include <iostream>
#include <memory>
#include <print>
#include <string>

// This project needs an implementation of an ATS, not a binary tree
// For now... We will define a simple binary tree just for learning purposes
// Doing it in here just because I'm too lazy to create a new directory 
// and start a new project and all that jazz
struct Node {
	int data;
	std::unique_ptr<Node> parent;
	std::unique_ptr<Node> left;
	std::unique_ptr<Node> right;

	Node(int d) : data(d), parent(nullptr),left(nullptr), right(nullptr) {};
};

struct Tree {
	std::unique_ptr<Node> root;
	int elems;

	Tree() : root(nullptr), elems(0) {};

public:
	void insert(int num) {
		Node node = Node(num);
		Node* x = root.get();
		Node* y = nullptr;

		while (x != nullptr) {
			y = x;
			if (node.data < x->data) {
				x = x->left.get();
			} else {
				x = x->right.get();
			}
		}

		node.parent = y;

		if (y == nullptr) {
			root = node;
		}
		else if (node.data < y->data) {
			y->left = node;
		} else {
			y->right = node;
		}

		// if (root == nullptr) {
		// 	root = std::make_unique<Node>(num);
		// 	elems++;
		// 	return;
		// }

		// // value is less than current root
		// if (num < root->data) {
		// 	Node* current = root.get();
		// 	while (current->left != nullptr) {
		// 		if (num < current->data) {
		// 			// go left, but only if we should go left
		// 		} else {
		// 			// go right, but only if we should go right
		// 		}
		// 	}
		// 	current->left = std::make_unique<Node>(num);
		// 	elems++;
		// 	return;
		// }
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

	while (true) {
		std::string in_prompt = prompt();
		// Process the string, parse to AST
	};

	return 0;
}
