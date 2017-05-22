#include"tui.h"

char game(int level)
{
	
	

	//��������
	//i,t ѭ��������, x ������, y ������, pass ͨ���ж�����
	//restep_num ��¼ÿ�ֳ�������,step_num ��¼�����ܲ���,wide ��ͼ���
	int i,t, x, y, pass,restep_num,step_num,wide;
	//(ch ��Ϸ�����ж�ȡ������Ϣ, option��ͣ�����ж�ȡ������Ϣ����Ϸ��������ֵ,last_step ��¼��һ������)
	char ch, option,last_step;
	//���������飬��¼�յ�����
	int X_num[50] = { 0 }, Y_num[50] = { 0 },xnum,ynum;
	//lstep ��¼�Ƿ�����,x_box ��¼��һ��������ǰ�����������,y_box ��¼��һ��������ǰ��ĺ�������, rerestep_num ��¼��һ��������ǰ���ߵĲ���
	int lstep,x_box,y_box, rerestep_num;
	int map_high;


	//���弰��ʼ����ͼ
	char map[50][50] = { 0 };
	LoadMap(level, &map_high, map);

	//��ʼ������
	wide=step_num = restep_num= pass = 0;
	ch = option =last_step= NULL;
	xnum = ynum = 0;
	lstep = 0;

	//��ʼ����ʼλ��
	for ( i = 0;i<20; i++)
	{ 
		for (t = 0;map [i][t] != '\0'; t++)
			if (map [i][t] == '@')
			{
				x = i;
				y = t;
				i = 99;
				break;
			}
	}
	
	//Ѱ���յ�����
	for (i = 2; i<20; i++)
	{
		for (t = 2; map [i][t] != '\0'; t++)
		{
			if (map [i][t] == 'X'|| map [i][t] == 'Q')
			{
				X_num[xnum] = i;
				Y_num[ynum] = t;
				xnum++;
				ynum++;
			}
			if (i==map_high)
			{
				i = 99;
				break;
			}
		}
	}

	//�����ͼ���
	wide = strlen(map [0]);

	//��ӡ��ͼ
	system("cls");
	printf("\n\n\n\n\t\t\t\t\t\t         ��%d��",level+1);
	printf("\n\n");
	for (i = 0; i <= 17; i++)
	{
		for ( t = 0; t <(120-wide)/2; t++)
			printf(" ");
		puts(map[i]);
	}
	printf("\t\t\t\t\t\t������%d  ʣ�೷��������%d", step_num, 3 - restep_num);
	printf("\n\n\t\t\t\t\t      ���汾��(Q) ����(B) �˵�(ESC)");

	//��Ϸ������
	while (1)
	{
		ch = getch();
		ch= tolower(ch);
		
		switch (ch)
		{
		//�����ƶ�
		case 's':
			if (map [x + 1][y] == ' ' || map [x + 1][y] == 'X')
			{
				map [x][y] = ' ';
				x++;
				map [x][y] = '@';
				step_num++;
			}
			else if ((map [x + 1][y] == 'O' || map [x + 1][y] == 'Q') && map [x + 2][y] != 'O' && map [x + 2][y] != 'Q' && map [x + 2][y] != '#')
			{
				map [x][y] = ' ';
				x++;
				map [x][y] = '@';
				map [x + 1][y] = 'O';
				lstep = 1;
				x_box = x;
				y_box = y;
				rerestep_num = step_num;
				step_num++;
				last_step = ch;//�洢��һ����Ϣ
			}
			break;
		//�����ƶ�
		case 'w':
			if (map [x - 1][y] == ' ' || map [x - 1][y] == 'X')
			{
				map [x][y] = ' ';
				x--;
				map [x][y] = '@';
				step_num++;
			}
			else if ((map [x - 1][y] == 'O' || map [x - 1][y] == 'Q') && map [x - 2][y] != 'O' && map [x - 2][y] != 'Q' && map [x - 2][y] != '#')
			{
				map [x][y] = ' ';
				x--;
				map [x][y] = '@';
				map [x - 1][y] = 'O';
				lstep = 1;
				x_box = x;
				y_box = y;
				rerestep_num = step_num;
				step_num++;
				last_step = ch;//�洢��һ����Ϣ
			}
			break;
		//�����ƶ�
		case 'a':
			if (map [x][y - 1] == ' ' || map [x][y - 1] == 'X')
			{
				map [x][y] = ' ';
				y--;
				map [x][y] = '@';
				step_num++;
			}
			else if ((map [x][y - 1] == 'O' || map [x][y - 1] == 'Q') && map [x][y - 2] != 'O' && map [x][y - 2] != 'Q' && map [x][y - 2] != '#')
			{
				map [x][y] = ' ';
				y--;
				map [x][y] = '@';
				map [x][y - 1] = 'O';
				lstep = 1;
				x_box = x;
				y_box = y;
				rerestep_num = step_num;
				step_num++;
				last_step = ch;//�洢��һ����Ϣ
			}
			break;
		//�����ƶ�
		case 'd':
			if (map [x][y + 1] == ' ' || map [x][y + 1] == 'X')
			{
				map [x][y] = ' ';
				y++;
				map [x][y] = '@';
				step_num++;
			}
			else if ((map [x][y + 1] == 'O' || map [x][y + 1] == 'Q') && map [x][y + 2] != 'O' && map [x][y + 2] != 'Q'&&map [x][y + 2] != '#')
			{
				map [x][y] = ' ';
				y++;
				map [x][y] = '@';
				map [x][y + 1] = 'O';
				lstep = 1;
				x_box = x;
				y_box = y;
				rerestep_num = step_num;
				step_num++;
				last_step = ch;//�洢��һ����Ϣ
			}
			break;

		case 27://��ͣ����
			system("cls");
			printf("\n\n\n\n\n\t\t\t\t\t\t        ����(R)\n");
			printf("\n\n\t\t\t\t         ѡ��(X)  ����(Q)  ��һ��(N)  ���˵�(M)  \n");
			printf("\n\n\n\t\t\t\t\t\t      ����˵��");
			printf("\n\n\t\t\t\t\t        W:��  S:��  A:��  D:��");
			printf("\n\n\t\t\t\t\t         @:��  O:����  X:�յ� ");
			while (ch != 'r')
			{
				ch = getch();
				if (ch == 'x' || ch == 'q' || ch == 'n' || ch == 'm'||ch == 'X' || ch == 'Q' || ch == 'N' || ch == 'M')
				{
					option = ch;
					ch = 27;
					break;
				}
			}
			break;

		case 'q'://����
			option = ch;
			break;
		}

		//����һ��
		if (lstep == 1 && ch == 'b'&&restep_num<3)
		{
			switch (last_step)
			{
			//���������ƶ�
			case 's':
				map [x][y] = ' ';
				map [x_box+1][y_box] = ' ';
				map [x_box][y_box] = 'O';
				x_box--;
				x = x_box;
				y = y_box;
				map [x][y] = '@';
				step_num=rerestep_num;
				restep_num++;
				lstep = 0;
				break;
			//���������ƶ�
			case 'w':
				map [x][y] = ' ';
				map [x_box -1][y_box] = ' ';
				map [x_box][y_box] = 'O';
				x_box++;
				x = x_box;
				y = y_box;
				map [x][y] = '@';
				step_num = rerestep_num;
				restep_num++;
				lstep = 0;
				break;
				//���������ƶ�
			case 'a':
				map [x][y] = ' ';
				map [x_box][y_box-1] = ' ';
				map [x_box][y_box] = 'O';
				y_box++;
				x = x_box;
				y = y_box;
				map [x][y] = '@';
				step_num = rerestep_num;
				restep_num++;
				lstep = 0;
				break;
				//���������ƶ�
			case 'd':
				map [x][y] = ' ';
				map [x_box][y_box + 1] = ' ';
				map [x_box][y_box] = 'O';
				y_box--;
				x = x_box;
				y = y_box;
				map [x][y] = '@';
				step_num = rerestep_num;
				restep_num++;
				lstep = 0;
				break;
			}
		}

		//if (lstep = 1)
		//	last_step = ch;//�洢��һ����Ϣ

		//��ԭ�յ���
		for ( i = 0;X_num[i]!=0; i++)
		{
			if (map [X_num[i]][Y_num[i]] == ' ')
				map [X_num[i]][Y_num[i]] = 'X';
			if (map [X_num[i]][Y_num[i]] == 'O')
				map [X_num[i]][Y_num[i]] ='Q';
		}

		//��ӡ��ͼ
		if (option != 'q')
		{
			system("cls");
			printf("\n\n\n\n\t\t\t\t\t\t         ��%d��", level + 1);
			printf("\n\n");
			for (i = 0; i <= 17; i++)
			{
				for (t = 0; t <(120 - wide) / 2; t++)
					printf(" ");
				puts(map [i]);
			}
			printf("\t\t\t\t\t\t������%d  ʣ�೷��������%d", step_num, 3 - restep_num);
			printf("\n\n\t\t\t\t\t      ���汾��(Q) ����(B) �˵�(ESC)");
		}

		//ͨ�������ж�
		for (i = 0; X_num[i] != 0; i++)
		{
			if (map [X_num[i]][Y_num[i]] == 'Q')
				pass++;
		}
		if (pass == xnum)
		{
			pass = 1;
			ch = 27;
			break;
		}
		else
			pass = 0;

		//��;�˳�������
		if (ch == 27||ch=='q')
		{
			pass = 0;
			break;
		}
	}

	//�ж��ܷ������һ��
	system("cls");
	if (option != NULL)
	{
		if (option == 'n')
		{
			if (level == maps_num - 1)
			{
				system("cls");
				printf(" \n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t���Ѿ������һ���ˣ�");
				option = 'p';
				Sleep(1500);
				system("cls");
			}
		}
		return option;
	}

	//ͨ�ؽ���
	if (pass == 1)
	{
		printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t  ����!");
		printf("\n\n\t\t\t\t\t\t    �����ܼƲ�����%d", step_num);
		printf("\n\n\t\t\t\t\t  ѡ��(X)  ����(Q)  ��һ��(N)  ���˵�(M)  \n");
	}
	while (pass == 1)
	{
		option= getch();
		if (option == 'm'|| option == 'M')
			option = 'm';
		if (option == 'n'|| option == 'N')
		{
			if (level == maps_num - 1)
			{
				system("cls");
				printf(" \n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t���Ѿ������һ���ˣ�");
				option = 'p';
				Sleep(1500);
				system("cls");
			}
		}
		if (option == 'x' || option == 'q'  || option == 'n' || option == 'p' || option == 'm' || option == 'X' || option == 'Q' || option == 'N' || option == 'P' || option == 'M')
		{
			system("cls");
			return option;
		}
	}
	return option;
}

void LoadMap(int level,int *map_high, char(*map)[50])
{
	char buffer[256];
	FILE *fp;
	sprintf(buffer, "data\\Map\\%d.txt", level + 1);
	fp = fopen(buffer, "r");
	for (int i = 0;; i++)
	{
		fgets(map[i], 256, fp);
		map[i][strlen(map[i])-1] = '\0';
		if (map[i][1] == '|')
		{
			map[i][1] = '=';
			map_high = i;
			break;
		}
	}
	fclose(fp);
}
