#include <iostream>
#include "tree.h"
static void test_tree()
{
	int a[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int* preorder = a;
	int b[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	int* inorder = b;
	int c[] = { 7, 4, 2, 5, 8, 6, 3, 1 };
	int* postorder = c;
	BinaryTreeNode* tree = ConstructInPost(inorder, postorder, 8);
	PreorderTraversal(tree);
	std::cout << std::endl;
	InorderTraversal(tree);
	std::cout << std::endl;
	PostorderTraversal(tree);
	std::cout << std::endl;
	std::cout << GetNext(tree)->value;
}
