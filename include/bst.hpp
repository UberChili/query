#ifndef BST_H 
#define BST_H 

#include <memory>
#include <print>

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

#endif