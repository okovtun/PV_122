#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<stdio.h>
#include"resource.h"

/*
------------------------------------------------------
BYTE - 8 bit	char
WORD - 16bit	short
DWORD- 32bit	long
QWORD- 64bit	long long
------------------------------------------------------
*/

CONST CHAR g_szCLASS_NAME[] = "MyWindowClass";
CONST CHAR g_szTitle[] = "My first MainWindow";

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	//1) ����������� ������ ����:
	WNDCLASSEX wc;	//wc - Window Class
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WndProc;//��������� �� ��������� ����. lp - long pointer, fn - function
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	//wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON_SUN));
	//wc.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON_MOON));
	wc.hIconSm = (HICON)LoadImage(hInstance, "raining.ico", IMAGE_ICON, 0, 0, LR_DEFAULTSIZE|LR_LOADFROMFILE);
	wc.hIcon = (HICON)LoadImage(hInstance, "umbrella.ico", IMAGE_ICON, 0, 0, LR_DEFAULTSIZE|LR_LOADFROMFILE);
	wc.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_CURSOR_MAIN));//Small Icon
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszClassName = g_szCLASS_NAME;
	wc.lpszMenuName = NULL;
	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Class registration failed!", "Error", MB_OK | MB_ICONERROR);
		return 0;
	}

	//2) �������� ����:

	int screen_width = GetSystemMetrics(SM_CXSCREEN);
	int screen_height = GetSystemMetrics(SM_CYSCREEN);
	int window_width = screen_width - screen_width / 4;
	int window_height = screen_height - screen_height / 4;
	int window_start_x = screen_width / 8;
	int window_start_y = screen_height / 8;

	HWND hwnd = CreateWindowEx
	(
		WS_EX_CLIENTEDGE,	//exStyle
		g_szCLASS_NAME,		//��� ������ ����
		g_szTitle,		//��������� ����
		WS_OVERLAPPEDWINDOW,//����� ���� OVERLAPPED ������ �������� ��� �������� ���� ���������
		window_start_x, window_start_y, //������� ���� �� ������
		window_width, window_height, //������ ����
		NULL,	//������������ ����
		NULL,	//���� �����������
		hInstance,//*.exe-���� ����
		NULL
	);

	if (hwnd == NULL)
	{
		MessageBox(NULL, "Window creation failed", "Error", MB_OK | MB_ICONERROR);
		return 0;
	}
	ShowWindow(hwnd, nCmdShow);	//������ ����� ����������� ����
	UpdateWindow(hwnd);		//���������� ���� (���������� ��������� WM_PAINT)

	//3) ��������� ���� ���������:
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:	//��������� �������� ����
		break;
	case WM_COMMAND:	//��������� ������ ������� ������, � ������ ��������� ����
		switch (LOWORD(wParam))
		{

		}
		break;
	case WM_SIZE:
	case WM_MOVE:
	{
		RECT rect;
		GetWindowRect(hwnd, &rect);
		CONST INT SIZE = 256;
		CHAR buffer[SIZE]{};
		SendMessage(hwnd, WM_GETTEXT, SIZE, (LPARAM)buffer);
		sprintf
		(
			buffer, "%s Position: %dx%d, Size: %dx%d",
			g_szTitle,
			rect.left, rect.top,	//������� ����
			rect.right-rect.left, rect.bottom-rect.top
		);
		//%s - ������
		//%d - decimal (���������� �����)
		SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)buffer);
	}
	break;
	case WM_CLOSE:
		switch (MessageBox(hwnd, "�� ������������� ������ ������� ����?", "��, �������?", MB_YESNO | MB_ICONQUESTION))
		{
		case IDYES:
			//MessageBox(hwnd, "����� � ����� ������� :-)", "Info", MB_OK | MB_ICONERROR);
			DestroyWindow(hwnd); break;
			//case IDNO: MessageBox(hwnd, "��� ������", "Info", MB_OK | MB_ICONINFORMATION); break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default: return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}