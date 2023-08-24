#include "bits/stdc++.h"

// NOTE: Not solved yet!

struct Node {
    int value;
    // keep track of number of descendants
    int descendants = 0;
    Node* parent;
    std::vector<Node*> children;

    void make_parent(Node *p) {
        // set parent node
        this->parent = p;
        // set child node of p
        p->children.push_back(this);
    }

    void add_child(Node *child) {
        child->make_parent(this);
    }
};

void print_children(Node n) {
    std::cout << n.value << " -> ";
    for (auto x : n.children) {
        std::cout << x->value << " ";
    }
    std::cout << "\n";
}

void print_tree(Node* n) {
    if (n->children.empty()) {
        std::cout << n->value << " -> null" << "\n";
    } else {
        print_children(*n);
        for (auto x : n->children) {
            print_tree(x);
        }
    }
}


int main() {
    int n;
    std::cin >> n;

    std::vector<Node> employees(n);
    employees[0].value = 1;
    for (int i = 1; i < n; i++) {
        // set value of employee
        employees[i].value = i+1;

        // input parent value for i+1 th employee
        int parent;
        std::cin >> parent;

        // set parent
        employees[i].make_parent(&employees[parent-1]);
    }
    
}