#define   WIDTH        80
#define   HIGH         10
#define   SNAKE_MAX_LENGHT   100 
#define   SPEED        500
#define   MAX_PLAYTIMES       100
#define   clrscr()       system("cls");

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <conio.h> 

int food_flag = 0;
int key = 72;
int conti;
int playtimes = 0;
int history[MAX_PLAYTIMES];

struct
{
	int x;
	int y;
}food;

struct
{
	int len;
	int x_buf[SNAKE_MAX_LENGHT];
	int y_buf[SNAKE_MAX_LENGHT];
	int score;
}snake;

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void DrawMap(void)
{
	int a, b;
	for (a = 0; a < WIDTH + 4; a += 2)
	{
		b = 0;
		gotoxy(a, b);
		printf("��");
		b = HIGH + 2;
		gotoxy(a, b);
		printf("��");
	}
	for (b = 1; b < HIGH + 2; b++)
	{
		a = 0;
		gotoxy(a, b);
		printf("��");
		a = WIDTH + 2;
		gotoxy(a, b);
		printf("��");
	}
	gotoxy(0, HIGH + 5);
}

void CreateSnake(void)
{
	int orgin_x, orgin_y;
	orgin_x = (WIDTH / 2) + 2;
	orgin_y = (HIGH / 2) + 1;

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
	gotoxy(0, HIGH + 5);
}

void CreateFood(void)
{
	if (food_flag == 0)
	{
		int a = 0, i;
		do
		{
			srand((unsigned int)time(NULL));
			food.x = ((rand(0) % (WIDTH / 2)) * 2) + 2;
			food.y = ((rand(0) % (HIGH / 2)) * 2) + 2;

			for (i = 0; i < snake.len; i++)
			{
				if (snake.x_buf[i] == food.x && snake.y_buf[i] == food.y)
				{
					a = 1;
					break;
				}
			}

		} while (a);

		gotoxy(food.x, food.y);
		printf("��");

		snake.score++;

		food_flag = 1;
	}
	gotoxy(0, HIGH + 5);
}

void SnakeMove(int x, int y)
{

	if (!food_flag)
		snake.len++;
	else
	{
		gotoxy(snake.x_buf[snake.len - 1], snake.y_buf[snake.len - 1]);
		printf("  ");
	}
	for (int i = snake.len - 1; i > 0; i--)
	{
		snake.x_buf[i] = snake.x_buf[i - 1];
		snake.y_buf[i] = snake.y_buf[i - 1];
	}

	snake.x_buf[0] = x;
	snake.y_buf[0] = y;
	gotoxy(snake.x_buf[0], snake.y_buf[0]);
	gotoxy(0, HIGH + 5);
}

void move()
{
	int pre_key = key, x, y;

	if (_kbhit())
	{
		fflush(stdin);
		key = _getch();
		key = _getch();
	}

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
		x = snake.x_buf[0] - 2;
		y = snake.y_buf[0];
		break;
	case 77:
		x = snake.x_buf[0] + 2;
		y = snake.y_buf[0];
		break;
	case 72:
		x = snake.x_buf[0];
		y = snake.y_buf[0] - 1;
		break;
	case 80:
		x = snake.x_buf[0];
		y = snake.y_buf[0] + 1;
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

	if (snake.x_buf[0] == 0 | snake.x_buf[0] == WIDTH + 4 | snake.y_buf[0] == 0 | snake.y_buf[0] == HIGH + 2)
	{
		printf("Game Over!\n");
		stop = 1;
	}
	else
	{
		for (i = 1; i < snake.len; i++)
		{
			if (snake.x_buf[0] == snake.x_buf[i] && snake.y_buf[0] == snake.y_buf[i])
			{
				printf("You lose!\n");
				stop = 1;
			}
		}

		if (snake.len == SNAKE_MAX_LENGHT)
		{
			printf("You win!\n");
			stop = 1;
		}

		else
		{
			gotoxy(0, HIGH + 6);
			printf("Your score: %d", snake.score);
		}
	}
	if (stop)
	{
		history[playtimes] = snake.score;
		gotoxy(0, HIGH + 7);
		printf("��J1�H���s���C���G");
		scanf_s("%d", &conti);
		if (conti == 1)
		{
			clrscr();
			gotoxy(0, 0);
			food_flag = 0;
		}
		else
		{
			exit(0);
		}
		return 0;
	}
	else
	{
		return 1;
	}
}

void welcome()
{
	gotoxy(0, 0);
	printf("�w��Ө�[�g�Y�D Snake] !\n\n");
	printf("�W�h�p�U:\n");
	printf("1.�ΤW�U���k��ޱ��g�Y�D\n");
	printf("2.�D�Y�I��ۤv�]��������\n");
	printf("3.�H�ۤ��ƼW�[�A�D�]�|�V�]�V�ֳ� !");
}

void HistoryRecord()
{
	gotoxy(0, 9);
	if (playtimes)
	{
		printf("�����v�����G\n");
		for (int i = 0; i < playtimes; i++)
		{
			gotoxy(0, 10 + i);
			printf("[�� %d ���C�����ƬO %d]", (i + 1), history[i]);
		}
	}
	else
	{
		printf("�����v�����G�L\n");
	}
}

void GameLevel()
{
	int out, level;
	gotoxy(0, 7);
	printf("��J�C������1~5(1����²��A5���̧x��)�G");
	scanf_s("%d", &level);
	clrscr();
	fflush(stdin);

	gotoxy(0, 0);
	DrawMap();
	CreateSnake();
	do
	{
		CreateFood();
		move();
		Sleep(SPEED - (20 * snake.len * level));
		out = check();
	} while (out == 1);
}

int main(void)
{
	while (1)
	{
		welcome();
		HistoryRecord();
		GameLevel();
		playtimes += 1;
	}
}
