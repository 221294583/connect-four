#include"FOUR.h"
#include"iostream"
#include"conio.h"
using namespace std;
int main()
{
	struct FOUR gaming = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, };
	int flag = 1;
	int bas[8][8] = { 0,1,1,1,1,1,1,2,
				   3,4,4,4,4,4,4,5,
				   3,4,4,4,4,4,4,5,
				   3,4,4,4,4,4,4,5,
				   3,4,4,4,4,4,4,5,
				   3,4,4,4,4,4,4,5,
				   3,4,4,4,4,4,4,5,
				   6,7,7,7,7,7,7,8 };

	while (flag)
	{
		mainmenu(bas, gaming);
		int choice;
	label_1:cin >> choice;
		switch (choice)
		{
		case 1:battle(bas, gaming); flag = 1; break;
		case 2:vsAI(bas, gaming); flag = 1; break;
		case 3:aboutauthor(); flag = 1; break;
		case 4:exit(); flag = 0; break;
		default:cout << "输入错误，请重新输入" << endl; goto label_1;
		}
	}
	system("pause");
	_getch();
}