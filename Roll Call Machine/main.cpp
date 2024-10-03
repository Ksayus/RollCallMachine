#include <iostream>
#include <Windows.h>
#include "ReadingList.h"
using namespace std;

#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" ) // 设置入口地址

int main()
{
a:
	CheckFlie();
	if (MessageBox(NULL, L"是否运行程序,点否退出点名", L"提示", MB_YESNO | MB_NOFOCUS) == IDYES)
	{
		if (MessageBox(NULL, L"是否开始抽人,点否编辑名单", L"提示", MB_YESNO | MB_NOFOCUS) == IDYES)
		{
			ReadingListStorager();
		}
		else {
			if (MessageBox(NULL, L"点是编辑名单和长度和循环次数，点否返回第一个提示", L"提示", MB_YESNO | MB_NOFOCUS) == IDYES)
			{
				system("start ./NameList.txt");
				system("start ./NumberLong.txt");
				//system("start ./LoopLong.txt");
				goto a;
			}
			else {
				goto a;
			}
		}
	}

	return 0;
}