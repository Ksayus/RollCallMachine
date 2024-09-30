#include "ReadingList.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <io.h>
#include <Windows.h>
#include <locale>
#include <codecvt>

using namespace std;

const int MaxNumber = 512;
const int NumberExtractions = 39;

int LineNumber = 0;

string filename = "NameList.txt";

string Lines;
string List[MaxNumber]{};
string ListStorager[MaxNumber]{};

int ExtractionQuantity;

void CheckFlie()
{
	if ((_access("./NameList.txt", 0)) == -1)
	{
		ofstream file("NameList.txt");//创建一个输出流对象file
	}
	if ((_access("./NumberExtractions.txt", 0)) == -1)
	{
		ofstream file("./NumberExtractions.txt");//创建一个输出流对象file
	}
}

int GetRand(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}

int ReadingListStorager()
{
	srand(time(0));

	std::ifstream file;
	std::fstream filenumber;
	file.open("./NameList.txt", ios::in);
	

	int check = 0;
	//read.open("./NameList.txt");
	while (getline(file, List[check]))
	{
		cout << List[check] << endl;
		ListStorager[check] = List[check];
		//cout << ListStorager[check] << endl;//输出读取的文本文件数据
		check++;
	}

	// << List[check] << endl;
	char savename[MaxNumber];
	while (file.getline(savename, sizeof(savename)))
	{
		cout << savename << endl;
	}


	cout << check << endl;

	filenumber.open("./NumberExtractions.txt", ios::out);

	file.close();
	//LineNumber == check;
	//cout << check << endl;
	filenumber << check;
	filenumber.close();
	


	HWND hwnd;
	hwnd = FindWindow(L"ConsoleWindowClass", NULL);//找到当前窗口句柄
	if (hwnd) {
		ShowOwnedPopups(hwnd, SW_HIDE);//显示或隐藏由指定窗口所有的全部弹出式窗口
		ShowWindow(hwnd, SW_HIDE);//控制窗口的可见性
	}
	HDC hdc;
	int client_width = 0, client_height = 0;
	hdc = GetDC(NULL);
	client_width = GetDeviceCaps(hdc, DESKTOPHORZRES);
	client_height = GetDeviceCaps(hdc, DESKTOPVERTRES);
	hdc = GetWindowDC(GetDesktopWindow());
	POINT p{};
	//GetCursorPos(&p);//获取鼠标坐标 
	int times = 350;
	while (times) {
		int midnumber = rand() % check;

		LPCSTR lpcstr = ListStorager[midnumber].c_str();

		//SetCursorPos(p.x, p.y);//更改鼠标坐标
		TextOutA(hdc, GetRand(10, client_width), GetRand(10, client_height), lpcstr, 3);
		Sleep(1);
		times--;
		if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState('E')) break;//按下组合键停止
	}




	int resultnumber = rand() % check;
	//cout << resultnumber << endl;

	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	std::wstring wstr = converter.from_bytes(ListStorager[resultnumber]);

	LPCWSTR lpcwstr = wstr.c_str();

	if (MessageBox(NULL, lpcwstr, L"就是你了！", MB_OK) == IDYES)
	{
		return 0;
	}
	
	//std::cout << List;
	//return check;
}
