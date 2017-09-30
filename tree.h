struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
	// 前序遍历的第一个数字是根节点的值
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->value = rootValue;
	root->left = root->right = nullptr;
	if (startPreorder == endPreorder)
	{
		if (startInorder == endInorder&& *startPreorder == *startInorder)
			return root;
		else
			throw std::exception("Invalid input.");
	}
	// 在中序遍历序列中找到根节点的值
	int* rootInorder = startInorder;
	while (rootInorder<=endInorder && *rootInorder!=rootValue)
		++rootInorder;
	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0)
	{
		// 构建左子树
		root->left = ConstructCore(startPreorder+1, leftPreorderEnd, startInorder, rootInorder-1);
	}
	if (leftLength < endPreorder-startPreorder)
	{
		// 构建右子树
		root->right = ConstructCore(leftPreorderEnd+1, endPreorder, rootInorder+1, endInorder);
	}
	return root;
}

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
	if (preorder == nullptr || inorder == nullptr || length <= 0)
		return nullptr;
	return ConstructCore(preorder, preorder+length-1, inorder, inorder+length-1);
}
