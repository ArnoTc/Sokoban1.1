//==========================
//�������ƣ�������
//�����ˣ�������
//�汾�ţ�1.1
//����ʱ�䣺2016.12.17
//�ϴ��޸�ʱ�䣺2016.12.20 23:35
//������������4
//
//������־��
//1.1
//2017.5.22��
//	�޸����õ�ͼΪtxt�ļ��洢������Ӧ�޸Ĵ��룬���ӵ�ͼ�ļ���ȡ����void LoadMap(int level, int *map_high, char(*map)[50]);
//
//==========================
#include"tui.h"

int main()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut, &cci);//��ȡ�����Ϣ
	cci.bVisible = FALSE;//���ع��
	SetConsoleCursorInfo(hOut, &cci);//���ù����Ϣ

	system("title ������1.0");//�趨��������
	system("mode con cols=120 lines=30");//�趨���ڴ�С

	int level, level_option,i;
	char option;

	level = 0;
	option = 'M';
	//������1
	char main_interface[50][50] = {
									"\n\n\n\n\n\n\n",
									"\t\t\t\t\t\t\t ������",
									"\t\t\t\t\t\t   |===============|",
									"\t\t\t\t\t\t   |               |",
									"\t\t\t\t\t\t   |               |",
									"\t\t\t\t\t\t   |    ��ʼ(S)    |",
									"\t\t\t\t\t\t   |               |",
									"\t\t\t\t\t\t   |   �˳�(ESC)   |",
									"\t\t\t\t\t\t   |               |",
									"\t\t\t\t\t\t   |               |",
									"\t\t\t\t\t\t   |===============|",
									};
	//������
	while (option != 27)
	{
		system("cls");
		for (i = 0; i<11; i++)//���˵�1
			puts(main_interface[i]);
		while (1)
		{
			option = getch();
			if (option == 's' || option == 'S' || option == 27)
				break;
		}
		while (1)
		{
			if (option == 's' || option == 'S')//��ӡ���˵�2
			{
				system("cls");
				printf("\n\n\n\n\n\n\n\n");
				printf("\t\t\t\t\t\t\t ������\n");
				printf("\t\t\t\t\t\t   |===============|\n");
				printf("\t\t\t\t\t\t   |               |\n");
				printf("\t\t\t\t\t\t   |   ��ͷ��ʼ(A) |\n");
				printf("\t\t\t\t\t\t   |               |\n");
				printf("\t\t\t\t\t\t   |    ѡ��(X)    |\n");
				printf("\t\t\t\t\t\t   |               |\n");
				printf("\t\t\t\t\t\t   |    ����(R)    |\n");
				printf("\t\t\t\t\t\t   |               |\n");
				printf("\t\t\t\t\t\t   |===============|");
				while (1)
				{
					option = getch();
					if (option == 'a' || option == 'A' || option == 'x' || option == 'X' || option == 'r' || option == 'R')
						break;
				}
			}
			if (option == 'n' || option == 'N')//������һ��
			{
				system("cls");
				level++;
				option = game(level);//������Ϸ
			}
			if (option == 'q' || option == 'Q')//���汾��
			{
				system("cls");
				option = game(level);//������Ϸ
			}
			if (option == 'a' || option == 'A')//��ͷ��ʼ
			{
				system("cls");
				level = 0;
				option = game(level);//������Ϸ
			}
			if (option == 'x' || option == 'X')//ѡ��
			{
				while (1)
				{
					system("cls");
					printf("\n\n\n\n\n\n\n\n\n\n\n");
					printf("\t\t\t\t\t\t");
					printf("������ؿ�(1-%d):",maps_num);
					scanf("%d", &level_option);
					if (level_option > 0 && level_option < maps_num + 1)//�޶��ؿ�ѡ��Χ
					{
						level = level_option - 1;
						option = 'q';
						break;
					}
				}
			}
			if (option == 'p' || option == 'P')//ͨ����������
			{
				option = 'm';
				level = 0;
				break;
			}
			if (option == 'm' || option == 'M' || option == 'r' || option == 'R' )//���˵�1ѡ��
			{
				break;
			}
			if (option == 27)//�˳�����
				break;
		}
	}
	system("cls");
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t   �Ϲ����� ��Ʒ");
	printf("\n\n\t\t\t\t\t\t     ��� ����");
	Sleep(2500);
	return 0;
}