#include <windows.h>
#include "test_tree.cpp"
int main()
{
	LARGE_INTEGER li, freq;
	QueryPerformanceCounter(&li);
	double f_start = li.QuadPart;

	// 要被计时的操作
	test_tree();

	QueryPerformanceCounter(&li);
	double f_end = li.QuadPart;
	QueryPerformanceFrequency(&freq);   //取得当前线(进)程的时钟主频
	double f = freq.QuadPart;
	double time = (f_end - f_start) / 1000000;
	std::cout << "\n\n运行所用时间：" << time << "秒" << std::endl;
	system("pause");
	return 0;
}