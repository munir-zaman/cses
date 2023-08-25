#include "bits/stdc++.h"

// NOTE: Getting TLE on some test cases

struct Node {
    int value;
    // keep track of number of descendants
    int descendants = 0;
    Node* parent;
    std::vector<Node*> children;

    void increase_descendants(int n) {
        descendants += n;
        if (parent != nullptr) {
            // if has parent, increase descendants of parent
            parent->increase_descendants(n);
        }
    }

    void add_child(Node *child) {
        child->parent = this;
        this->children.push_back(child);

        this->increase_descendants(1 + child->descendants);
    }

    void make_parent(Node *p) {
        p->add_child(this);
    }

};

void print_children(Node n) {
    std::cout << n.value << " ( " << n.descendants << " ) " << " -> ";
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
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

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
    
    for (auto &e : employees) {
        std::cout << e.descendants << " ";
    }
    std::cout << "\n";
}