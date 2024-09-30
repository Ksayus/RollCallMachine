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
		ofstream file("NameList.txt");//����һ�����������file
	}
	if ((_access("./NumberExtractions.txt", 0)) == -1)
	{
		ofstream file("./NumberExtractions.txt");//����һ�����������file
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
		//cout << ListStorager[check] << endl;//�����ȡ���ı��ļ�����
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
	hwnd = FindWindow(L"ConsoleWindowClass", NULL);//�ҵ���ǰ���ھ��
	if (hwnd) {
		ShowOwnedPopups(hwnd, SW_HIDE);//��ʾ��������ָ���������е�ȫ������ʽ����
		ShowWindow(hwnd, SW_HIDE);//���ƴ��ڵĿɼ���
	}
	HDC hdc;
	int client_width = 0, client_height = 0;
	hdc = GetDC(NULL);
	client_width = GetDeviceCaps(hdc, DESKTOPHORZRES);
	client_height = GetDeviceCaps(hdc, DESKTOPVERTRES);
	hdc = GetWindowDC(GetDesktopWindow());
	POINT p{};
	//GetCursorPos(&p);//��ȡ������� 
	int times = 350;
	while (times) {
		int midnumber = rand() % check;

		LPCSTR lpcstr = ListStorager[midnumber].c_str();

		//SetCursorPos(p.x, p.y);//�����������
		TextOutA(hdc, GetRand(10, client_width), GetRand(10, client_height), lpcstr, 3);
		Sleep(1);
		times--;
		if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState('E')) break;//������ϼ�ֹͣ
	}




	int resultnumber = rand() % check;
	//cout << resultnumber << endl;

	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	std::wstring wstr = converter.from_bytes(ListStorager[resultnumber]);

	LPCWSTR lpcwstr = wstr.c_str();

	if (MessageBox(NULL, lpcwstr, L"�������ˣ�", MB_OK) == IDYES)
	{
		return 0;
	}
	
	//std::cout << List;
	//return check;
}
