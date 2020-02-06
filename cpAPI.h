/*
Logan Passi
01/30/20
cpAPI.h
*/

#include <stdio.h>
#include <Windows.h> //<--Windows API

using namespace std;

int cp(const char * src, const char * dst) {

	HANDLE inFile;
	HANDLE outFile;
	DWORD numberOfBytesRead;
	DWORD numberOfBytesWritten;

	char buffer[20];

	inFile = CreateFileA(src, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL); //System Call

	if (GetLastError() == ERROR_FILE_NOT_FOUND) {
		printf("Could not find file!");
		return 1;
	}

	outFile = CreateFileA(dst, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	while (true) {
		ReadFile(inFile, buffer, 20, &numberOfBytesRead, NULL);
		if (numberOfBytesRead == 0) {
			break;
		}

		WriteFile(outFile, buffer, numberOfBytesRead, &numberOfBytesWritten, NULL);
	}

	CloseHandle(inFile);
	CloseHandle(outFile);

	return 0;
}