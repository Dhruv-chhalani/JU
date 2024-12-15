#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int key;
    struct NODE *right;
    struct NODE *left;
    int height;
};

int get_height(struct NODE *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

struct NODE *createnode(int k)
{
    struct NODE *new = (struct NODE *)malloc(sizeof(struct NODE));
    new->key = k;
    new->right = NULL;
    new->left = NULL;
    new->height = 1;
    return new;
}

int get_bf(struct NODE *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return get_height(n->left) - get_height(n->right);
}

struct NODE *rr(struct NODE *x)
{
    struct NODE *y = x->right;
    struct NODE *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(get_height(x->left), get_height(x->right)) + 1;
    y->height = max(get_height(y->left), get_height(y->right)) + 1;
    return y;
}

struct NODE *lr(struct NODE *y)
{
    struct NODE *x = y->left;
    struct NODE *t2 = x->right;

    x->right = y;
    y->left = t2;

    x->height = max(get_height(x->right), get_height(x->left)) + 1;
    y->height = max(get_height(y->right), get_height(y->left)) + 1;

    return x;
}

struct NODE *insert(struct NODE *t, int key)
{
    if (t == NULL)
        return createnode(key);

    if (key < t->key)
        t->left = insert(t->left, key);
    else if (key > t->key)
        t->right = insert(t->right, key);

    t->height = 1 + max(get_height(t->right), get_height(t->left));

    int bf = get_bf(t);

    if (bf > 1 && key < t->left->key)
    {
        return lr(t);
    }
    if (bf < -1 && key > t->right->key)
    {
        return rr(t);
    }
    if (bf > 1 && key > t->left->key)
    {
        t->left = lr(t->left);
        return rr(t);
    }
    if (bf < -1 && key < t->right->key)
    {
        t->right = rr(t->right);
        return lr(t);
    }
    return t;
}

void preOrder(struct NODE *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    struct NODE *root = NULL;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preOrder(root);
    return 0;
}