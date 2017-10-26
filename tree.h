struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode* parent;
};

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
	// ǰ������ĵ�һ�������Ǹ��ڵ��ֵ
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->value = rootValue;
	root->left = root->right = root->parent = nullptr;
	if (startPreorder == endPreorder)
	{
		if (startInorder == endInorder&& *startPreorder == *startInorder)
			return root;
		else
			throw std::exception("Invalid input.");
	}
	// ����������������ҵ����ڵ��ֵ
	int* rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootValue)
		++rootInorder;
	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0)
	{
		// ����������
		root->left = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
		root->left->parent = root;
	}
	if (leftLength < endPreorder - startPreorder)
	{
		// ����������
		root->right = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
		root->right->parent = root;
	}
	return root;
}

// ����ĳ��������ǰ���������������Ľ�����ؽ��ö�����
BinaryTreeNode* ConstructPreIn(int* preorder, int* inorder, int length)
{
	if (preorder == nullptr || inorder == nullptr || length <= 0)
		return nullptr;
	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode* ConstructCore2(int* startInorder, int* endInorder, int* startPostorder, int* endPostorder)
{
	// ǰ����������һ�������Ǹ��ڵ��ֵ
	int rootValue = *endPostorder;
	BinaryTreeNode* root = new BinaryTreeNode;
	root->value = rootValue;
	root->left = root->right = root->parent = nullptr;
	if (startInorder == endInorder)
	{
		if (startPostorder == endPostorder && *startInorder == *endPostorder)
			return root;
		else
			throw std::exception("Invalid input.");
	}
	// ����������������ҵ����ڵ��ֵ
	int* rootInorder = startInorder;
	while (*rootInorder != rootValue && rootInorder!=endInorder)
		++rootInorder;
	int leftLength = rootInorder - startInorder;
	int* leftPostorderEnd = startPostorder + leftLength - 1;
	if (leftLength > 0)
	{
		// ����������
		root->left = ConstructCore2(startInorder, rootInorder - 1, startPostorder, leftPostorderEnd);
		root->left->parent = root;
	}
	if (leftLength < endPostorder - startPostorder)
	{
		// ����������
		root->right = ConstructCore2(rootInorder + 1, endInorder, leftPostorderEnd+1, endPostorder-1);
		root->right->parent = root;
	}
	return root;
}

// ����ĳ����������������ͺ�������Ľ�����ؽ��ö�����
BinaryTreeNode* ConstructInPost(int* inorder, int* postorder, int length)
{
	if (postorder == nullptr || inorder == nullptr || length <= 0)
		return nullptr;
	return ConstructCore2(inorder, inorder + length - 1, postorder, postorder + length - 1);
}

void PreorderTraversal(BinaryTreeNode* root)
{
	if (root == nullptr)
		return;
	std::cout << root->value << ' ';
	PreorderTraversal(root->left);
	PreorderTraversal(root->right);
}

void InorderTraversal(BinaryTreeNode* root)
{
	if (root == nullptr)
		return;
	InorderTraversal(root->left);
	std::cout << root->value << ' ';
	InorderTraversal(root->right);
}

void PostorderTraversal(BinaryTreeNode* root)
{
	if (root == nullptr)
		return;
	PostorderTraversal(root->left);
	PostorderTraversal(root->right);
	std::cout << root->value << ' ';
}

BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
	if (pNode == nullptr)
		return nullptr;
	BinaryTreeNode* pNext = nullptr;
	if (pNode->right != nullptr)
	{
		BinaryTreeNode* p = pNode->right;
		while (p->left != nullptr)
			p = p->left;
		pNext = p;
	}
	else if (pNode->parent != nullptr)
	{
		BinaryTreeNode* pCurrent = pNode;
		BinaryTreeNode* pParent = pNode->parent;
		while (pParent->left != pCurrent && pParent != nullptr)
		{
			pCurrent = pCurrent->parent;
			pParent = pParent->parent;
		}
		pNext = pParent;
	}
	return pNext;
}