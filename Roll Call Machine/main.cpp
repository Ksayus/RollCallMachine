#include <iostream>
#include <Windows.h>
#include "ReadingList.h"
using namespace std;

#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" ) // ������ڵ�ַ

int main()
{
	a:
	if (MessageBox(NULL, L"�Ƿ����г���,����˳�����", L"��ʾ", MB_YESNO | MB_NOFOCUS) == IDYES)
	{
		if (MessageBox(NULL, L"�Ƿ�ʼ����,���༭����", L"��ʾ", MB_YESNO | MB_NOFOCUS) == IDYES)
		{
			CheckFlie();
			ReadingListStorager();
		}
		else {
			if (MessageBox(NULL, L"���Ǳ༭��������񷵻ص�һ����ʾ", L"��ʾ", MB_YESNO | MB_NOFOCUS) == IDYES)
			{
				system("start ./NameList.txt");
				goto a;
			}
			else {
				goto a;
			}
		}
	}

	return 0;
}