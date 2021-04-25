#include <stdio.h>
#include <stdlib.h>

struct bstree 
{
	int key;		
	char *value;	
	struct bstree *left;
	struct bstree *right;
};

// Создание элемента BST
struct bstree *bstree_create(int key, char *value)
{
	struct bstree *node;
	node = malloc(sizeof(*node));
	if (node != NULL)
	{
		node->key = key;
		node->value = value;
		node->left = NULL;
		node->right = NULL;
	}
	return node;
}

// Добавление элемента в BST
void bstree_add(struct bstree *tree, int key, char *value) {
	struct bstree *parent, *node;
	if (tree == NULL) {
        return;	    
	}
		
	for (parent = tree; tree != NULL;) {
		parent = tree;
		if (key < tree->key) {
		    tree = tree->left;    
		} else {
		    if (key > tree->key) {
			    tree = tree->right;   
			}    
		}
	}

	node = bstree_create(key, value);
	if (key < parent->key) {
	    parent->left = node;    
	} else {
	    parent->right = node;    
    }

// Поиск элемента в BST
struct bstree *bstree_lookup(struct bstree *tree, int key)
{
	while (tree != NULL) {
		if (key == tree->key) {
			return tree;
		}
		else {
		    if (key < tree->key) {
				tree = tree->left;
			} else {
				tree = tree->right;
			}    
		}
	}
	return tree;
}

// Поиск минимального элемента в BST
struct bstree *bstree_min(struct bstree *tree)
{
	if (tree == NULL) {
	    return NULL;    
	}
		
	while (tree->left != NULL) {
	    tree = tree->left;    
	}
		
	return tree;
}

// Поиск максимального элемента в BST
struct bstree *bstree_max(struct bstree *tree)
{
	if (tree == NULL) {
	    return NULL;    
	}
		
	while (tree->right != NULL) {
	    tree = tree->right;    
	}
	
	return tree;
}

int main(void) {
	struct bstree *tree, *node;
	tree = bstree_create(180, "Ivan");
	bstree_add(tree, 200, "Egor");
	bstree_add(tree, 60, "Artem");
	node = bstree_lookup(tree, 180);
	printf("Value = %s\n", node->value);
	node = bstree_min(tree);
	printf("Min: value = %s\n", node->value);
	node = bstree_max(tree);
	printf("Max: value = %s\n", node->value);
	return 0;
}
