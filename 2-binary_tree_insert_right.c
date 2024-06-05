#include "binary_trees.h"
/**
 * binary_tree_insert_right - adds node to the right of the parent
 * and if node exists it move down one level and add the new node first
 * @parent: parent of the specified node
 * @value: value for the node
 * Return: NULL if it fails or the new node
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
  binary_tree_t *new;
 

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new->right = parent->right;
		parent->right->parent = new;
	}
	parent->right = new;

	return (new);
}
