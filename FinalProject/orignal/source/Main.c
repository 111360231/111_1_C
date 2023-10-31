#define   WIDTH        80
#define   HIGH         10
#define   SNAKE_MAX_LENGHT   100 
#define   SPEED        500
#define   playtimes       100
#define   clrscr()       system("cls");

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <conio.h> 

int food_flag = 0, key = 72, conti, times = 0, history[playtimes]; //food_flag��1�ɭ����s�b�A�Ϥ��h�_

struct //�غcfood���Ҧ��ݩ�
{
	int x;
	int y;
}food;

struct //�غcsnake���Ҧ��ݩ�
{
	int len;
	int x_buf[SNAKE_MAX_LENGHT];
	int y_buf[SNAKE_MAX_LENGHT];
	int score;
}snake;

void gotoxy(int x, int y)
{
	COORD coord; //�Rcoord���y�Ю榡
	coord.X = x; //�Rcoord.X��x�y��
	coord.Y = y; //�Rcoord.Y��y�y��
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); //�T�O�a�Ϥj�p����Q�ù��Үe��
}

void DrawMap(void)
{
	int a, b;
	for (a = 0; a < WIDTH + 4; a += 2) //�e�W�U���䪺��
	{
		b = 0;
		gotoxy(a, b); //���w���I����Ӯy��
		printf("��");
		b = HIGH + 2;
		gotoxy(a, b); //���w���I����s�y��
		printf("��");
	}
	for (b = 1; b < HIGH + 2; b++) //�e���k���䪺��
	{
		a = 0;
		gotoxy(a, b);
		printf("��");
		a = WIDTH + 2;
		gotoxy(a, b);
		printf("��");
	}
	gotoxy(0, HIGH + 5); //�N�w���I���X�C���ϰ�A���\��]�i���s�b
}

void CreateSnake(void) //�гy�X�D�M���l��m�A���ɳD�٤��|����
{
	int orgin_x, orgin_y;
	orgin_x = WIDTH / 2 + 2;
	orgin_y = HIGH / 2 + 1;

	snake.len = 3;
	snake.x_buf[0] = orgin_x;
	snake.y_buf[0] = orgin_y;
	snake.x_buf[1] = orgin_x;
	snake.y_buf[1] = ++orgin_y;
	snake.x_buf[2] = orgin_x;
	snake.y_buf[2] = ++orgin_y;

	snake.score = -1;

	int i;
	for (i = 0; i < snake.len; i++)
	{
		gotoxy(snake.x_buf[i], snake.y_buf[i]);
		printf("��");
	}
	gotoxy(0, HIGH + 5); //�N�w���I���X�C���ϰ�A���\��]�i���s�b
}

void CreateFood(void)
{
	if (food_flag == 0)
	{
		int flag = 0, i;
		do
		{
			srand((unsigned int)time(NULL)); //�C�����H���@��,�ýT�O���|�����ƪ����p
			food.x = (rand(0) % (WIDTH / 2)) * 2 + 2; //�T�Ox�y�Эȥi�b���{�����B�@
			food.y = (rand(0) % (HIGH / 2)) * 2 + 2;

			for (i = 0; i < snake.len; i++) //�P�_�����O�_�M�D�����X
			{
				if (snake.x_buf[i] == food.x && snake.y_buf[i] == food.y)
				{
					flag = 1;
					break;
				}
			}

		} while (flag);

		gotoxy(food.x, food.y);
		printf("��");

		snake.score++; //�Y�쭹���A�h���ƥ[1

		food_flag = 1;
	}
	gotoxy(0, HIGH + 5);
}

void SnakeMove(int x, int y)
{
	// �P�_�O�_�Y�쭹���A�Y����ץ[1
	if (!food_flag)
		snake.len++;
	// �S�Y��h�٥h�̫�@�`
	else
	{
		gotoxy(snake.x_buf[snake.len - 1], snake.y_buf[snake.len - 1]);
		printf("  ");
	}
	int i;
	for (i = snake.len - 1; i > 0; i--)
	{
		snake.x_buf[i] = snake.x_buf[i - 1];
		snake.y_buf[i] = snake.y_buf[i - 1];
	}
	snake.x_buf[0] = x;
	snake.y_buf[0] = y;
	gotoxy(snake.x_buf[0], snake.y_buf[0]);
	printf("��");
	gotoxy(0, HIGH + 5);
}

void move()
{
	int pre_key = key, x, y;

	if (_kbhit())//�p�G�ϥΪ̫��U�F��L�����Y����
	{
		fflush(stdin);//�M�Žw�İϪ��r��

		//getch()Ū����V�䪺�ɭԡA�|��^�⦸�A�Ĥ@���I�s��^0�Ϊ�224�A�ĤG���I�s��^���~�O��ڭ�
		key = _getch();//�Ĥ@���I�s��^�����O��ڭ�
		key = _getch();//�ĤG���I�s��^��ڭ�
	}

	// �p�D���ʤ�V����M�W�@������V�ۤ�
	if (pre_key == 72 && key == 80)
		key = 72;
	if (pre_key == 80 && key == 72)
		key = 80;
	if (pre_key == 75 && key == 77)
		key = 75;
	if (pre_key == 77 && key == 75)
		key = 77;

	switch (key)
	{
	case 75:
		x = snake.x_buf[0] - 2;//����
		y = snake.y_buf[0];
		break;
	case 77:
		x = snake.x_buf[0] + 2;//���k
		y = snake.y_buf[0];
		break;
	case 72:
		x = snake.x_buf[0];
		y = snake.y_buf[0] - 1;//���W
		break;
	case 80:
		x = snake.x_buf[0];
		y = snake.y_buf[0] + 1;//���U
		break;
	}

	if (x == food.x&&y == food.y)
		food_flag = 0;
	SnakeMove(x, y);
}

int check(void)
{
	int i;
	int stop = 0;

	// ���ѱ���1�G�D������
	if (snake.x_buf[0] == 0 | snake.x_buf[0] == WIDTH + 4 | snake.y_buf[0] == 0 | snake.y_buf[0] == HIGH + 2)
	{
		printf("Game Over!\n");
		stop = 1;
	}
	else {
		// ���ѱ���2�G�D����ۤv
		for (i = 1; i < snake.len; i++)
		{
			if (snake.x_buf[0] == snake.x_buf[i] && snake.y_buf[0] == snake.y_buf[i])
			{
				printf("You lose!\n");
				stop = 1;
			}
		}

		// �ӧQ����
		if (snake.len == SNAKE_MAX_LENGHT) {
			printf("You win!\n");
			stop = 1;
		}

		// �C�L�o��
		else {
			gotoxy(0, HIGH + 6);
			printf("Your score: %d", snake.score);
		}
	}
	if (stop) {
		history[times] = snake.score;
		gotoxy(0, HIGH + 7);
		printf("��J1�H���s���C���G");
		scanf_s("%d", &conti);
		if (conti == 1) {
			clrscr();
			gotoxy(0, 0);
			food_flag = 0;
			return 0;
		}
		else {
			exit(0);
			return 0;
		}
	}
	else {
		return 1;
	}
}

int main(void)
{
	int i, out, level = 0;
	while (1) {
		//�w�虜��
		gotoxy(0, 0);
		printf("�w��Ө�[�g�Y�D Snake] !\n\n");
		printf("�W�h�p�U:\n");
		printf("1.�ΤW�U���k��ޱ��g�Y�D\n");
		printf("2.�D�Y�I��ۤv�]��������\n");
		printf("3.�H�ۤ��ƼW�[�A�D�]�|�V�]�V�ֳ� !");

		//��ܾ��v����
		gotoxy(0, 9);
		if (times) {
			printf("�����v�����G\n");
			for (i = 0; i < times; i++) {
				gotoxy(0, 10 + i);
				printf("[�� %d ���C�����ƬO %d]", (i + 1), history[i]);
			}
		}
		else {
			printf("�����v�����G�L\n");
		}

		gotoxy(0, 7);
		printf("��J�C������1~5(1����²��A5���̧x��)�G");
		scanf_s("%d", &level);

		clrscr();
		fflush(stdin);
		//�C������
		gotoxy(0, 0);
		DrawMap();
		CreateSnake();
		do
		{
			CreateFood();
			move();
			Sleep(SPEED - 20 * snake.len * level); //����D����ɶ��ӱ����t��
			out = check(); //�ˬd�O�ӧQ�٬O���ѡA�����O���ܴN�~��while�j��
		} while (out == 1);

		times += 1;
	}
}
