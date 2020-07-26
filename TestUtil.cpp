#include "TestUtil.h"
#include <Windows.h>
#include <stdio.h>

TestUtil::TestUtil()
{
}

TestUtil::~TestUtil()
{
}


void TestUtil::GetVolumeName()
{
	TCHAR buf[100];
	TCHAR res[100];
	HANDLE hDevice = NULL;
	DWORD error = 0;
	DWORD ret_size;

	ZeroMemory(buf, 100 * sizeof(TCHAR));
	ZeroMemory(res, 100 * sizeof(TCHAR));
	hDevice = FindFirstVolume(buf, 100);
	if (hDevice == INVALID_HANDLE_VALUE)
	{
		wprintf(L"Find First Volume failed with error code %d\n", GetLastError());
		return;
	}

	wprintf(L"The First Volume is %s\n", buf);

	if (!GetVolumePathNamesForVolumeName(buf, res, 100, &ret_size))
	{
		wprintf(L"Get Volume Path failed with error code %d\n", GetLastError());
		return;
	}

	wprintf(L"The Volume Path is %s\n", res);

	FindVolumeClose(hDevice);

}

