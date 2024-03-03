#include <windows.h>
#include <wchar.h>
#include <stdio.h>

#pragma warning(disable : 6386)
#pragma warning(disable : 6387)

int __cdecl wmain(int argc, wchar_t *argv[], wchar_t *envp[])
{
  HANDLE hProcessHeap = GetProcessHeap();
  WCHAR bConsent;

  ULONG nArgLength = lstrlenW(argv[1]);
  ULONG nOffset = 0;

  if (argv[1] == 0)
    return 1;

  WCHAR *wString = HeapAlloc(hProcessHeap, HEAP_ZERO_MEMORY, (nArgLength + 8) * sizeof(WCHAR)),
        *wBuffer = wString;

  wprintf(L"Argument passed to the command line:\n%s\n\n", argv[1]);

  if (wString == NULL)
    return 1;

  lstrcpyW(wString, argv[1]);
  if (wString[nArgLength - 1] == L'/')
    wString[nArgLength - 1] = 0;

  while (*wBuffer++ != 0)
  {
    static BOOL protocolPass  = FALSE,
                quotesOpen    = FALSE;

    if (!protocolPass)
      nOffset++;

    switch (*wBuffer)
    {
    case L'/':
    {
      if (!protocolPass)
      {
        protocolPass = TRUE;

        nOffset += 2;
        wBuffer++;
      }

      break;
    }

    case L'%':
    {
      ULONG nLength = lstrlenW(wBuffer);

      WCHAR hexNumber[4] = {0};
      WCHAR *yeahIRefuseToTypeThat;

      wmemcpy(hexNumber, wBuffer + 1, 2);

      WCHAR nChar = (WCHAR)wcstoul(hexNumber, &yeahIRefuseToTypeThat, 16);

      wBuffer[0] = (WCHAR)nChar;
      wBuffer[1] = 0;
      wBuffer[2] = 0;

      for (ULONG i = 0; i < nLength - 3; i++)
      {
        wBuffer[i + 1] = wBuffer[i + 3];
        wBuffer[i + 3] = 0;
      }

      break;
    }
    }
  }

  wBuffer = wString + nOffset;

  wprintf(L"Converted argument:\n%s\n\n", wBuffer);
  wprintf(L"Would you like to execute the command? (Y/N): ");

  wscanf(L"%c", &bConsent, 1);
  if (bConsent != 0 && toupper(bConsent) != L'Y')
    return 1;

  WCHAR *wNewString = HeapAlloc(hProcessHeap, HEAP_ZERO_MEMORY, (nArgLength + 8) * sizeof(WCHAR));

  lstrcpyW(wNewString, L"/c ");
  lstrcatW(wNewString, wBuffer);

  HeapFree(hProcessHeap, 0, wString);

  PROCESS_INFORMATION processInfo = {0};
  STARTUPINFOW startupInfo = {0};

  startupInfo.cb = sizeof(startupInfo);
  startupInfo.wShowWindow = STARTF_USESHOWWINDOW;

  CreateProcessW(
      L"C:\\Windows\\System32\\cmd.exe",
      wNewString,
      NULL,
      NULL,
      0,
      NORMAL_PRIORITY_CLASS | CREATE_NEW_CONSOLE,
      NULL,
      NULL,
      &startupInfo,
      &processInfo);

  CloseHandle(processInfo.hProcess);
  CloseHandle(processInfo.hThread);

  HeapFree(hProcessHeap, 0, wNewString);

  return 0;
}