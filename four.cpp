#include"FOUR.h"
#include"iostream"
#include"string.h"
#include"conio.h"
#include"time.h"
using namespace std;
static const char ch[11][4] = { "┌","┬","┐","├","┼","┤","└","┴","┘","○","●" };
void mainmenu(int bas[8][8], FOUR gaming)
{
	cout << "————————————————————" << endl;
	cout << " 1.双人对战" << endl;
	cout << " 2.电脑对战" << endl;
	cout << " 3.作者信息" << endl;
	cout << " 4.退出系统" << endl;
	cout << "————————————————————" << endl;
	cout << "请输入选择..." << endl;
	system("pause");
}
int exit()
{
	cout << "确认退出?[Y确认]" << endl;
	char choice;
	cin >> choice;
	if (choice == 'y' || choice == 'Y')
	{
		cout << "感谢使用" << endl;
	}
	_getch();
	return 0;
}
int aboutauthor()
{
	cout << "由b站用户自摸天胡编写" << endl;
	cout << "联系方式qq1439166424" << endl;
	cout << "按任意键继续" << endl;
	_getch();
	return 1;
}
int battle(int bas[8][8], FOUR gaming)
{
	initialize(gaming);
	int x, y, mark;
	int i, j;
	int flag;
label_2:printmap(bas, gaming);
	int next = turn(gaming);
	if (next == 1)
	{
		cout << "请玩家1走棋[输入(A,B)]" << endl;
		cin >> i >> j;
		mark = 1;
	}
	else if (next == 2)
	{
		cout << "请玩家2走棋[输入(A,B)]" << endl;
		cin >> i >> j;
		mark = 2;
	}
	x = 8 - i;
	y = j - 1;
	int legal = legit(x, y, gaming);
	if (legal)
	{
		if (next == 1)
		{
			gaming.pc[x][y] = 1;
		}
		else if (next == 2)
		{
			gaming.pc[x][y] = 2;
		}
		system("cls");
		printmap(bas, gaming);
	}
	else
	{
		cout << "位置不合法，请重新走棋" << endl << "按任意键继续" << endl;
		_getch();
		system("cls");
		goto label_2;
	}
	flag = victory(gaming, x, y, mark);
	if (flag == -1)
	{
		goto label_2;
	}
	_getch();
	return 0;
}
void printmap(int bas[8][8], FOUR gaming)
{
	int i, j;
	cout << "A" << endl;
	for (i = 0; i < 8; i++)
	{
		cout << 8 - i;
		for (j = 0; j < 8; j++)
		{
			if (gaming.pc[i][j] == 1 || gaming.pc[i][j] == 2)
			{
				printchequer(gaming, i, j);
			}
			else
			{
				printbackground(bas, i, j);
			}
		}
		cout << endl;
	}
	cout << "  " << 1 << " " << 2 << " " << 3 << " " << 4 << " " << 5 << " " << 6 << " " << 7 << " " << 8 << " " << "B" << endl;
}
void printbackground(int bas[8][8], int i, int j)
{
	int flag;
	flag = bas[i][j];
	cout << ch[flag];
}
void printchequer(FOUR gaming, int i, int j)
{
	int flag;
	flag = gaming.pc[i][j];
	if (flag == 1)
	{
		cout << ch[9];
	}
	else if (flag == 2)
	{
		cout << ch[10];
	}
}
int turn(FOUR gaming)
{
	int count1 = 0, count2 = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (gaming.pc[i][j] == 1)
			{
				count1++;
			}
			else if (gaming.pc[i][j] == 2)
			{
				count2++;
			}
		}
	}
	if (count1 > count2)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}
int victory(FOUR gaming, int x, int y, int mark)
{
	int i, j, k;
	int count = 1, total = 0;
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			if (i != 0 || j != 0)
			{
				for (k = 1; k < 4; k++)
				{
					if (x + k * i >= 0 && x + k * i <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i][y + k * j] != mark && gaming.pc[x + k * i][y + k * j] != 0)
					{
						break;
					}
					else if (x + k * i >= 0 && x + k * i <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i][y + k * j] == mark)
					{
						count++;
					}
				}
				for (k = -1; k > -4; k--)
				{
					if (x + k * i >= 0 && x + k * i <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i][y + k * j] != mark && gaming.pc[x + k * i][y + k * j] != 0)
					{
						break;
					}
					else if (x + k * i >= 0 && x + k * i <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i][y + k * j] == mark)
					{
						count++;
					}
				}
			}
			if (count >= 4)
			{
				cout << "恭喜！玩家" << mark << "获得胜利！" << endl;
				_getch();
				return 1;
			}
			else
			{
				count = 1;
			}
		}
	}
	for (i = 0; i < 8; i++)
	{
		for (i = 0; i < 8; i++)
		{
			if (gaming.pc[i][j] == 1 || gaming.pc[i][j] == 2)
			{
				total++;
			}
		}
	}
	if (total >= 64)
	{
		cout << "DRAWGAME平局!" << endl;
		_getch();
		return 1;
	}
	return -1;
}
void initialize(FOUR gaming)
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			gaming.pc[i][j] = 0;
		}
	}
}
int legit(int x, int y, FOUR gaming)
{
	if (x < 0 || x >= 8)
	{
		return 0;
	}
	if (y < 0 || y >= 8)
	{
		return 0;
	}
	if (gaming.pc[x][y] != 0)
	{
		return 0;
	}
	if (((x + 1) <= 7 && gaming.pc[x + 1][y] == 0))
	{
		return 0;
	}
	return 1;
}
int vicsimulator(FOUR gaming, int x, int y, int mark)
{
	int i, j, k;
	int count = 1, total = 0;
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			if (i != 0 || j != 0)
			{
				for (k = 1; k < 4; k++)
				{
					if (x + k * i >= 0 && x + k * i <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i][y + k * j] != mark && gaming.pc[x + k * i][y + k * j] != 0)
					{
						break;
					}
					else if (x + k * i >= 0 && x + k * i <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i][y + k * j] == mark)
					{
						count++;
					}
				}
				for (k = -1; k > -4; k--)
				{
					if (x + k * i >= 0 && x + k * i <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i][y + k * j] != mark && gaming.pc[x + k * i][y + k * j] != 0)
					{
						break;
					}
					else if (x + k * i >= 0 && x + k * i <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i][y + k * j] == mark)
					{
						count++;
					}
				}
			}
			if (count >= 4)
			{
				_getch();
				return 1;
			}
			else
			{
				count = 1;
			}
		}
	}
	for (i = 0; i < 8; i++)
	{
		for (i = 0; i < 8; i++)
		{
			if (gaming.pc[i][j] == 1 || gaming.pc[i][j] == 2)
			{
				total++;
			}
		}
	}
	if (total >= 64)
	{
		_getch();
		return 1;
	}
	return -1;
}
int AIScript(FOUR gaming, int x, int y, int mark, int AIpost[2])
{
	int i, j, k, attack, defense[8] = {};
	int attackpost[2] = {}, defensepost[2] = {};
	int post[8][2] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	int max, kmax;
	for (j = 0; j < 8; j++)
	{
		post[j][1] = j;
		for (i = 7; i >= 0; i--)
		{
			if (gaming.pc[i][j] == 0)
			{
				post[j][0] = i;
				break;
			}
		}
	}
	for (j = 0; j < 8; j++)
	{
		if (post[j][0] >= 0 && post[j][0] < 8)
		{
			attack = vicsimulator(gaming, post[j][0], post[j][1], 2);
			if (attack == 1)
			{
				attackpost[0] = post[j][0];
				attackpost[1] = post[j][1];
				AIpost[0] = attackpost[0];
				AIpost[1] = attackpost[1];
				return 0;
			}
			defense[j] = score(gaming, post[j][0], post[j][1]);
			cout << defense[j] << endl;
		}
	}
	max = defense[0];
	kmax = 0;
	for (k = 1; k < 8; k++)
	{
		if (defense[k] > max)
		{
			max = defense[k];
			kmax = k;
		}
	}
	defensepost[0] = post[kmax][0];
	defensepost[1] = post[kmax][1];
	AIpost[0] = defensepost[0];
	AIpost[1] = defensepost[1];
	_getch();
	return 0;
}
int score(FOUR gaming, int x, int y)
{
	int i, j, k;
	int count;
	int grade = 0;
	{
		i = 0;
		j = 1;
		count = 1;
		for (k = 1; k < 4; k++)
		{
			if (x + k * i >= 0 && x + k * i <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i][y + k * j] == 2)
			{
				break;
			}
			else if (x + k * i >= 0 && x + k * i <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i][y + k * j] == 1)
			{
				count++;
			}
		}
		for (k = -1; k > -4; k--)
		{
			if (x + k * i >= 0 && x + k * i <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i][y + k * j] == 2)
			{
				break;
			}
			else if (x + k * i >= 0 && x + k * i <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i][y + k * j] == 1)
			{
				count++;
			}
		}
		if (count == 2)
		{
			grade += 1;
		}
		if (count == 3)
		{
			grade += 3;
		}
		if (count == 4)
		{
			grade += 7;
		}
	}
	{
		i = 1;
		j = 1;
		count = 1;
		for (k = 1; k < 4; k++)
		{
			if (x + k * i >= 0 && x + k * i <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i][y + k * j] == 2)
			{
				break;
			}
			else if (x + k * i >= 0 && x + k * i <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i][y + k * j] == 1)
			{
				count++;
			}
		}
		for (k = -1; k > -4; k--)
		{
			if (x + k * i >= 0 && x + k * i <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i][y + k * j] == 2)
			{
				break;
			}
			else if (x + k * i >= 0 && x + k * i <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i][y + k * j] == 1)
			{
				count++;
			}
		}
		if (count == 2)
		{
			grade += 1;
		}
		if (count == 3)
		{
			grade += 3;
		}
		if (count == 4)
		{
			grade += 7;
		}
	}
	{
		i = 1;
		j = 0;
		count = 1;
		for (k = 1; k < 4; k++)
		{
			if (x + k * i >= 0 && x + k * i <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i][y + k * j] == 2)
			{
				break;
			}
			else if (x + k * i >= 0 && x + k * i <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i][y + k * j] == 1)
			{
				count++;
			}
		}
		for (k = -1; k > -4; k--)
		{
			if (x + k * i >= 0 && x + k * i <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i][y + k * j] == 2)
			{
				break;
			}
			else if (x + k * i >= 0 && x + k * i <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i][y + k * j] == 1)
			{
				count++;
			}
		}
		if (count == 2)
		{
			grade += 1;
		}
		if (count == 3)
		{
			grade += 3;
		}
		if (count == 4)
		{
			grade += 7;
		}
	}
	{
		i = 1;
		j = -1;
		count = 1;
		for (k = 1; k < 4; k++)
		{
			if (x + k * i >= 0 && x + k * i <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i][y + k * j] == 2)
			{
				break;
			}
			else if (x + k * i >= 0 && x + k * i <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i][y + k * j] == 1)
			{
				count++;
			}
		}
		for (k = -1; k > -4; k--)
		{
			if (x + k * i >= 0 && x + k * i <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i][y + k * j] == 2)
			{
				break;
			}
			else if (x + k * i >= 0 && x + k * i <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i][y + k * j] == 1)
			{
				count++;
			}


		}
		if (count == 2)
		{
			grade += 1;
		}
		if (count == 3)
		{
			grade += 3;
		}
		if (count == 4)
		{
			grade += 7;
		}
	}
	cout << grade << " ";
	{
		if (gaming.pc[x + 1][y] == 1 && x + 1 >= 0 && x + 1 <= 7)
		{
			grade++;
		}
		if (gaming.pc[x + 1][y + 1] == 1 && x + 1 >= 0 && x + 1 <= 7 && y + 1 >= 0 && y + 1 <= 7)
		{
			grade++;
		}
		if (gaming.pc[x][y + 1] == 1 && y + 1 >= 0 && y + 1 <= 7)
		{
			grade++;
		}

		if (gaming.pc[x - 1][y + 1] == 1 && x - 1 >= 0 && x - 1 <= 7 && y + 1 >= 0 && y + 1 <= 7)
		{
			grade++;
		}
		if (gaming.pc[x - 1][y] == 1 && x - 1 >= 0 && x - 1 <= 7)
		{
			grade++;
		}
		if (gaming.pc[x - 1][y - 1] == 1 && x - 1 >= 0 && x - 1 <= 7 && y - 1 >= 0 && y - 1 <= 7)
		{
			grade++;
		}
		if (gaming.pc[x][y - 1] == 1 && y - 1 >= 0 && y - 1 <= 7)
		{
			grade++;
		}
		if (gaming.pc[x + 1][y - 1] == 1 && y - 1 >= 0 && y - 1 <= 7 && x + 1 >= 0 && x + 1 <= 7)
		{
			grade++;
		}
	}
	{
		{
			i = 0;
			j = 1;
			count = 1;
			for (k = 1; k < 4; k++)
			{
				if (x + k * i - 1 >= 0 && x + k * i - 1 <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i - 1][y + k * j] == 1)
				{
					count++;
				}
			}
			for (k = -1; k > -4; k--)
			{
				if (x + k * i - 1 >= 0 && x + k * i - 1 <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i - 1][y + k * j] == 1)
				{
					count++;
				}
			}
			if (count >= 4)
			{
				grade = 0;
			}
		}
		{
			i = 1;
			j = 1;
			count = 1;
			for (k = 1; k < 4; k++)
			{
				if (x + k * i - 1 >= 0 && x + k * i - 1 <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i - 1][y + k * j] == 1)
				{
					count++;
				}
			}
			for (k = -1; k > -4; k--)
			{
				if (x + k * i - 1 >= 0 && x + k * i - 1 <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i - 1][y + k * j] == 1)
				{
					count++;
				}
			}
			if (count >= 4)
			{
				grade = 0;
			}
		}
		{
			i = 1;
			j = 0;
			count = 1;
			for (k = 1; k < 4; k++)
			{
				if (x + k * i - 1 >= 0 && x + k * i - 1 <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i - 1][y + k * j] == 1)
				{
					count++;
				}
			}
			for (k = -1; k > -4; k--)
			{
				if (x + k * i - 1 >= 0 && x + k * i - 1 <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i - 1][y + k * j] == 1)
				{
					count++;
				}
			}
			if (count >= 4)
			{
				grade = 0;
			}
		}
		{
			i = 1;
			j = -1;
			count = 1;
			for (k = 1; k < 4; k++)
			{
				if (x + k * i - 1 >= 0 && x + k * i - 1 <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i - 1][y + k * j] == 1)
				{
					count++;
				}
			}
			for (k = -1; k > -4; k--)
			{
				if (x + k * i - 1 >= 0 && x + k * i - 1 <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i - 1][y + k * j] == 1)
				{
					count++;
				}
			}
			if (count >= 4)
			{
				grade = 0;
			}
		}
	}
	return grade;
}
int vsAI(int bas[8][8], FOUR gaming)
{
	initialize(gaming);
	int x, y, mark;
	int i, j;
	int flag;
	int post[2] = {};
label_2:printmap(bas, gaming);
	int next = turn(gaming);
	if (next == 1)
	{
		cout << "请玩家1走棋[输入(A,B)]" << endl;
		cin >> i >> j;
		mark = 1;
		x = 8 - i;
		y = j - 1;
	}
	if (next == 2)
	{
		AIScript(gaming, x, y, 1, post);
		x = post[0];
		y = post[1];
		mark = 2;
	}
	int legal = legit(x, y, gaming);
	if (legal)
	{
		if (next == 1)
		{
			gaming.pc[x][y] = 1;
		}
		else if (next == 2)
		{
			gaming.pc[x][y] = 2;
		}
		system("cls");
		printmap(bas, gaming);
	}
	else
	{
		cout << "位置不合法，请重新走棋" << endl << "按任意键继续" << endl;
		_getch();
		system("cls");
		goto label_2;
	}
	flag = vsAIvictory(gaming, x, y, mark);
	if (flag == -1)
	{
		goto label_2;
	}
	_getch();
	return 0;
}
int vsAIvictory(FOUR gaming, int x, int y, int mark)
{
	int i, j, k;
	int count = 1, total = 0;
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			if (i != 0 || j != 0)
			{
				for (k = 1; k < 4; k++)
				{
					if (x + k * i >= 0 && x + k * i <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i][y + k * j] != mark && gaming.pc[x + k * i][y + k * j] != 0)
					{
						break;
					}
					else if (x + k * i >= 0 && x + k * i <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i][y + k * j] == mark)
					{
						count++;
					}
				}
				for (k = -1; k > -4; k--)
				{
					if (x + k * i >= 0 && x + k * i <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i][y + k * j] != mark && gaming.pc[x + k * i][y + k * j] != 0)
					{
						break;
					}
					else if (x + k * i >= 0 && x + k * i <= 7 && y + k * j >= 0 && y + k * j <= 7 && gaming.pc[x + k * i][y + k * j] == mark)
					{
						count++;
					}
				}
			}
			if (count >= 4 && mark == 1)
			{
				cout << "恭喜！玩家1获得胜利！" << endl;
				_getch();
				return 1;
			}
			else if (count >= 4 && mark == 2)
			{
				cout << "抱歉，电脑胜利了!" << endl;
				_getch();
				return 1;
			}
			else
			{
				count = 1;
			}
		}
	}
	for (i = 0; i < 8; i++)
	{
		for (i = 0; i < 8; i++)
		{
			if (gaming.pc[i][j] == 1 || gaming.pc[i][j] == 2)
			{
				total++;
			}
		}
	}
	if (total >= 64)
	{
		cout << "DRAWGAME平局!" << endl;
		_getch();
		return 1;
	}
	return -1;
}