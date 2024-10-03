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

string constLoopLong = "350";
string constNumberLong = "1";

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
	if ((_access("./NumberLong.txt", 0)) == -1)
	{
		ofstream file("./NumberLong.txt");//创建一个输出流对象file
		ofstream outfile;
		outfile.open("./NumberLong.txt",ios::out);
		outfile << constNumberLong;
		outfile.close();
	}
	if ((_access("./LoopLong", 0)) == -1)
	{
		ofstream file("./LoopLong.txt");//创建一个输出流对象file
		ofstream outfile;
		outfile.open("./LoopLong.txt", ios::out);
		outfile << constLoopLong;
		outfile.close();
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



	char NumberLongStringchar[MaxNumber]{};

	int check = 0;
	//read.open("./NameList.txt");
	while (getline(file, List[check]))
	{
		cout << List[check] << endl;
		cout << List[check].length() << endl;

		//int NumberLong = stoi(NumberLongString);
		int NumberLong = List[check].length();
		NumberLongStringchar[check] = NumberLong;

		ListStorager[check] = List[check];
		//cout << ListStorager[check] << endl;//输出读取的文本文件数据
		check++;
	}

	// << List[check] << endl;
	/*char savename[MaxNumber];
	while (file.getline(savename, sizeof(savename)))
	{
		cout << savename << endl;
	}*/


	cout << check << endl;
	file.close();

	/*filenumber.open("./NumberLong.txt", ios::in);
	while (getline(filenumber, NumberLongString))
	{
		cout << NumberLongString << endl;
		
	}
	filenumber.close();*/

	fstream Loopfile;
	string LoopLongString;
	Loopfile.open("./LoopLong.txt", ios::in);
	while (getline(Loopfile, LoopLongString))
	{
		cout << LoopLongString << endl;
	}
	Loopfile.close();
	int LoopLong = stoi(LoopLongString);
	


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
	int times = LoopLong;
	while (times) {
		int midnumber = rand() % check;

		LPCSTR lpcstr = ListStorager[midnumber].c_str();

		int LongNumber = NumberLongStringchar[midnumber];

		//SetCursorPos(p.x, p.y);//更改鼠标坐标
		TextOutA(hdc, GetRand(10, client_width), GetRand(10, client_height), lpcstr, LongNumber);
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
