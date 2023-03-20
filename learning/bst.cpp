#include<iostream>

struct bst
{
    bst* parent;
    bst* left_child;
    bst* right_child;
    int key;
};

int main() {
    bst node1, node2, node3;

    node1.key = 5;
    node2.key = 3; 
    node3.key = 8;

    node1.parent = NULL;
    node2.parent = &node1;
    node3.parent = &node1;

    node1.left_child = &node2;
    node1.right_child = &node3;
}
