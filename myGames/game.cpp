#include <iostream>
#include<conio.h>

using namespace std;

bool hardmode = false;
bool gameover;
const int width = 40;
const int height = 20;
int x, y, fx, fy;
int score;
int teilx[100];
int teily[100];
int ntail;
enum edirection 
{
	STOP=0,LEFT,RIGHT,UP,DOWN
};
edirection dir;

void Setup()
{
	gameover = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fx = rand() % width;
	fy = rand() % height;
	score = 0;
}
void Draw() 
{
	system("cls");
	for (int i=0;i<width;i++)
	{
		cout << "#";
	}
	cout << endl;

	for (int i =0; i<height;i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0 || j==(width-1))
			{
				cout << "#";

			}
			else
			{
				if (i == y && j == x)
				{
					cout << "0";

				}
				else
				{
					if (i == fy && j == fx)
					{
						cout << "f";
					}
					else
					{
						bool print = false;
						for (int k = 0; k < ntail; k++)
						{
							if (teilx[k] == j && teily[k] == i)
							{
								print = true;
								cout << "o";
							}
						}
						if (!print)
						{
							cout << " ";
						}
						

					}
				}
				
			}
					
		}
		cout << endl;
	}
	



	for (int i = 0; i < width; i++)
	{
		cout << "#";
	}
	cout << endl;
	
	cout << "score=" << score;
	
	if (hardmode == true)
	{
		cout <<endl<< "you become hardmode";
	}
	
}
void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;

			break;
		case 'w':
			dir = UP;
			break;
		case's':
			dir = DOWN;
			break;
		case'd':
			dir = RIGHT;
			break;
		case'x':
			gameover = true;
			if (gameover == true)
			{
				cout <<endl<< "ty prograv";
			}
			break;
		}
	}
}

void Logic()
{
	int prevx=teilx[0];
	int prevy = teily[0];
	int prev2x, prev2y;
	teilx[0] = x;
	teily[0] = y;
	for (int i = 1; i < ntail; i++)
	{
		prev2x = teilx[i];
		prev2y = teily[i];
		teilx[i] = prevx;
		teily[i] = prevy;
		prevx = prev2x;
		prevy = prev2y;
	}


	switch (dir)
	{
	case LEFT:
		x = x - 1;
		break;
	case RIGHT:
		x = x + 1;
		break;
	case UP:
		y = y - 1;
		break;
	case DOWN:
		y = y + 1;
		break;

	}
	if (hardmode==false)
	{
		if (x >= width)
		{
			x = 0;
		}
		else
		{
			if (x < 0)
			{
				x = width;
			}
		}

		if (y >= height)
		{
			y = 0;
		}
		else
		{
			if (y < 0)
			{
				y = height;
			}
		}



	}
	else
	{
		if (x > width || x<0 || y > height || y < 0 )
		{
			gameover = true;
			cout << endl << "ty prograv";
		}
	}
	
	for (int i = 0; i < ntail; i++)
	{
		if (teilx[i] == x && teily[i] == y)
		{
			gameover = true;
			cout << endl << "ty prograv";
		}
	}
	if (x == fx && y == fy)
	{
		score = score + 10;
		if (score == 100)
		{
			hardmode = true;
			
		}
		
		fx = rand() % width;
		fy = rand() % height;
		ntail++;
	}




}


int main()
{
	

	Setup();
	do
	{
		Draw();
		Input();
		Logic();
	} while (gameover == false);
	return 0;
}