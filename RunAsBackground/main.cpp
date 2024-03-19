#include <windows.h>
#include <stdlib.h>
#include <TCHAR.h>
#include <strsafe.h>
#include <shellapi.h>

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpCmdLine, int nCmdShow)
{
    int argc = 0;
    LPWSTR* wargv = CommandLineToArgvW(GetCommandLine(), &argc);

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    ZeroMemory(&pi, sizeof(pi));
    si.cb = sizeof(si);

    if (argc > 1) CreateProcess(NULL, wargv[1], NULL, NULL, false, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    exit(0);
}