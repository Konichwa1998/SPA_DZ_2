#include "game_of_life.h"
#include <algorithm>

bool game_of_life::slucajna_vrijednost()
{

	if (rand() % 4 == 0)
	{
		return true;
	}
	return false;
}

game_of_life::game_of_life()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = slucajna_vrijednost();
			_sljedeca_generacija[i][j] = false;
		}
	}
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			int n = 0;
			
			if (i == 0 && j >= 1 && j <= 38)		
			{
				if (_generacija[i][j - 1])
					n++;
				if (_generacija[i + 1][j - 1])
					n++;
				if (_generacija[i + 1][j])
					n++;
				if (_generacija[i + 1][j + 1])
					n++;
				if (_generacija[i][j + 1])
					n++;
			}
			else if (i == 19 && j >= 1 && j <= 38)		
			{
				if (_generacija[i][j - 1])
					n++;
				if (_generacija[i - 1][j - 1])
					n++;
				if (_generacija[i - 1][j])
					n++;
				if (_generacija[i - 1][j + 1])
					n++;
				if (_generacija[i][j + 1])
					n++;
			}
			else if (i >= 1 && i <= 18 && j == 0)		
			{
				if (_generacija[i - 1][j])
					n++;
				if (_generacija[i - 1][j + 1])
					n++;
				if (_generacija[i][j + 1])
					n++;
				if (_generacija[i + 1][j + 1])
					n++;
				if (_generacija[i + 1][j])
					n++;
			}
			else if (i >= 1 && i <= 18 && j == 39)		
			{
				if (_generacija[i - 1][j])
					n++;
				if (_generacija[i - 1][j - 1])
					n++;
				if (_generacija[i][j - 1])
					n++;
				if (_generacija[i + 1][j - 1])
					n++;
				if (_generacija[i + 1][j])
					n++;
			}
			else if (i >= 1 && i <= 18 && j >= 1 && j <= 38)
			{
				if (_generacija[i][j - 1])
					n++;
				if (_generacija[i - 1][j - 1])
					n++;
				if (_generacija[i - 1][j])
					n++;
				if (_generacija[i - 1][j + 1])
					n++;
				if (_generacija[i][j + 1])
					n++;
				if (_generacija[i + 1][j + 1])
					n++;
				if (_generacija[i + 1][j])
					n++;
				if (_generacija[i + 1][j - 1])
					n++;
			}
			if (_generacija[i][j])
			{
				if (n > 3 || n < 2)
				{
					_sljedeca_generacija[i][j] = false;
				}
			}
			else
			{
				if (n == 3)
				{
					_sljedeca_generacija[i][j] = true;
				}
			}
		}
	}
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}

void game_of_life::iscrtaj()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (_generacija[i][j])
			{
				cout << "*";
			}
			else
			{
				cout << "-";
			}
		}
		cout << endl;
	}
}

