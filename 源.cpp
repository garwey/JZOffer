#include <windows.h>
#include <iostream>
#include "tree.h"
using namespace std;
void test()
{
	int a[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int* preorder = a;
	int b[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	int* inorder = b;
	int c[] = { 7, 4, 2, 5, 8, 6, 3, 1 };
	int* postorder = c;
	BinaryTreeNode* tree = ConstructInPost(inorder, postorder, 8);
	PreorderTraversal(tree);
	cout << endl;
	InorderTraversal(tree);
	cout << endl;
	PostorderTraversal(tree);
	cout << endl;
	cout << GetNext(tree)->value;
}
void main()
{
	LARGE_INTEGER li, freq;
	QueryPerformanceCounter(&li);
	double f_start = li.QuadPart;

	// 要被计时的操作
	test();

	QueryPerformanceCounter(&li);
	double f_end = li.QuadPart;
	QueryPerformanceFrequency(&freq);   //取得当前线(进)程的时钟主频
	double f = freq.QuadPart;
	double time = (f_end - f_start) / 1000000;
	cout << "\n\n运行所用时间：" << time << "秒" << endl;
	system("pause");
}