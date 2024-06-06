#include "binary_trees.h"

/**
 * binary_trees_ancestor - an ancestor checker function
 * @first: first node
 * @second: second node
 * Return: return node of ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *i, *k;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	i = first->parent;
	k = second->parent;
	if (i == NULL || first == k || (!i->parent && k))
		return (binary_trees_ancestor(first, k));
	else if (k == NULL || i == second || (!k->parent && i))
		return (binary_trees_ancestor(i, second));
	return (binary_trees_ancestor(i, k));
}
