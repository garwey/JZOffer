#include <iostream>
#include <windows.h>
using namespace std;
bool find(int* matrix, int rows, int columns, int num)
{
	bool found = false;
	if (matrix !=nullptr && rows > 0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;
		while (row < rows && columns >0)
		{
			if (matrix[row*columns + column] == num)
			{
				found = true;
				break;
			}
			else if (matrix[row*columns + column] > num)
				--column;
			else
				++row;
		}
	}
	return found;
}
void question()
{
	int matrix[] = {
		1,2,8,9,
		2,4,9,12,
		4,7,10,13,
		6,8,11,15
	};
	int num = 5;
	cout << "find("<<num<< ")\n";
	cout << find(matrix, 4, 4, num) << endl;
}
void find_main()
{
	LARGE_INTEGER li, freq;
	QueryPerformanceCounter(&li);
	double f_start = li.QuadPart;
	question();
	QueryPerformanceCounter(&li);
	double f_end = li.QuadPart;
	QueryPerformanceFrequency(&freq);   //取得当前线(进)程的时钟主频
	double f = freq.QuadPart;
	double time = (f_end - f_start)/1000000;
	cout << "运行所用时间：" << time <<"秒"<< endl;
	system("pause");
}