#include "stdafx.h"
#include <iostream>
#include <locale.h>
#include "icrsint.h"
#include "odbcinst.h"
#import "C:\Program Files (x86)\Common Files\System\ado\msado15.dll" no_namespace rename("EOF", "EndOfFile")
#pragma comment(lib, "odbccp32.lib")


using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	CoInitialize(NULL);
	_ConnectionPtr con("ADODB.Connection");
	try {
		SQLConfigDataSource(NULL, ODBC_ADD_DSN, L"Microsoft Access Driver (*.mdb)", L"CREATE_DB=C:\\DB\\Likhanova.mdb;User Id=root;Pwd=;");
		cout << "������� ��" << endl;
		con->Open("Driver={Microsoft Access Driver (*.mdb)};DBQ=C:\\DB\\Likhanova.mdb;", "root", "", adConnectUnspecified);
		cout << "������������ � ��" << endl;
		con->Execute("CREATE TABLE mytable(firstname char(20), lastname char(20), age Integer, group Integer);", NULL, adCmdText);
		cout << "������� ��������" << endl;
	}
	catch (_com_error& e) {
	}
	con->Close();
	CoUninitialize();
	system("Pause");
	return 0;
}
