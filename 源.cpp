#include <windows.h>
#include "test_tree.cpp"
int main()
{
	LARGE_INTEGER li, freq;
	QueryPerformanceCounter(&li);
	double f_start = li.QuadPart;

	// Ҫ����ʱ�Ĳ���
	test_tree();

	QueryPerformanceCounter(&li);
	double f_end = li.QuadPart;
	QueryPerformanceFrequency(&freq);   //ȡ�õ�ǰ��(��)�̵�ʱ����Ƶ
	double f = freq.QuadPart;
	double time = (f_end - f_start) / 1000000;
	std::cout << "\n\n��������ʱ�䣺" << time << "��" << std::endl;
	system("pause");
	return 0;
}