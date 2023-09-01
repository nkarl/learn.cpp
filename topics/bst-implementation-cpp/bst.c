#include <stdlib.h>
#include <stdio.h>

typedef struct Node NODE;
struct Node
{
    int Key;
    NODE *Less;
    NODE *More;
};

NODE *new_node(int k) {
    NODE *node = (NODE *)malloc(sizeof(NODE));
    node->Key = k;
    node->Less = node->More = NULL;
    return node;
}

NODE *insert(int k, NODE *parent)
{
    if (parent == NULL) return new_node(k);

    if (k < parent->Key)
        parent->Less = insert(k, parent->Less);
    else if (parent->Key < k)
        parent->More = insert(k, parent->More);
    return parent;
}

void print(NODE *root) {
    if (root == NULL) return;

    printf("%d ", root->Key);
    print(root->Less);
    print(root->More);
}

int main(int argc, char *argv[], char *env[])
{
    NODE _root = *new_node(3);
    printf("%d\n", _root.Key);

    insert(0, &_root);
    insert(1, &_root);
    insert(2, &_root);
    insert(7, &_root);
    insert(4, &_root);
    insert(9, &_root);

    print(&_root);
}
