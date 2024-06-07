#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *q, *k;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	q = first->parent; 
	k = second->parent;
	if (first == k || !q || (!q->parent && k))
		return (binary_trees_ancestor(first, k));
	else if (q == second || !k || (!k->parent && q))
		return (binary_trees_ancestor(q, second));
	return (binary_trees_ancestor(q, k));
}
