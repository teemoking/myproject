/***
** @date 2017.9.23
** @author AK
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <conio.h>
#include <vld.h>


void MyShow(int (*arr)[6])
{
	system("cls");

	int n = 5;
	for(int i=1; i<n; i++)
	{
		for(int j=1; j<n; j++)
		{
			printf("%5d",arr[i][j]);
		}
		printf("\n");
	}
}

bool MyCheck(int (*arr)[6])
{
	int n = 5;
	for(int i=1; i<n; i++)
	{
		for(int j=1; j<n; j++)
		{
			if(arr[i][j] == 0)
			{
				return false;
			}
			if(arr[i][j] == arr[i-1][j]	|| arr[i][j] == arr[i][j-1] ||
				 arr[i][j] == arr[i+1][j] || arr[i][j] == arr[i][j+1])
					{
						return false;
					}
		}
	}
	return true;
}

bool Myvictory(int (*arr)[6])
{
	int n = 5;
	for(int i=1; i<n; i++)
	{
		for(int j=1; j<n; j++)
		{
			if(arr[i][j] == 1024)
			{
				return true;
			}
		}
	}

	return false;
}

int MyRandom(int (*arr)[6])
{
	srand((unsigned)time(NULL));
	int n = 5;
	int k = 0;
	int x = 0;
	int y = 0;

	while(k<60)
	{
		x = 1+rand()%4;
		y = 1+rand()%4;
		if(arr[x][y] == 0)
		{
			if(rand()%4 != 0)
			{
				arr[x][y] = 2;
				return 1;
			}
			else
			{
				arr[x][y] = 4;
				return 1;
			}
			
		}
		else;
		k++;
	}

	if(!MyCheck(arr))
	{
		for(int i=n-1; i>0; i--)
		{
			for(int j=1; j<n; j++)
			{
				if(arr[i][j] == 0)
				{
					if(rand()%4 != 1)
					{
						arr[i][j] = 2;
						return 1;
					}
					else
					{
						arr[i][j] = 4;
						return 1;
					}
					
				}
				else;
			}
		}
	}
	else
	{
		return -1;
	}
}

void Myshift(int (*arr)[6])
{
	int key = 0;
	int n = 5;
	getch();
	key = getch();

	if(key == 72)
	{
		for(int k=1; k<n-1;k++)
		{
			for(int i=2; i<n; i++)
			{
				for(int j=1; j<n; j++)
				{
					if(arr[i-1][j] == 0)
					{
						arr[i-1][j] = arr[i][j];
						arr[i][j] = 0;
					}
				}
			}
		}
	
		for(int i=1; i<n; i++)
		{
			for(int j=1; j<n-1; j++)
			{
				if(arr[j][i] == arr[j+1][i])
				{
					arr[j][i] = 2*arr[j][i];
					arr[j+1][i] = 0;
				}
			}
		}
		for(int i=2; i<n; i++)
		{
			for(int j=1; j<n; j++)
			{
				if(arr[i-1][j] == 0)
				{
					arr[i-1][j] = arr[i][j];
					arr[i][j] = 0;
				}
			}
		}		
	}
	else if(key == 80)
	{
		for(int k=1; k<n-1;k++)
		{
			for(int i=n-2; i>0; i--)
			{
				for(int j=1; j<n; j++)
				{
					if(arr[i+1][j] == 0)
					{
						arr[i+1][j] = arr[i][j];
						arr[i][j] = 0;
					}
				}
			}
		}
	
		for(int i=n-2; i>0; i--)
		{
			for(int j=1; j<n; j++)
			{
				if(arr[i][j] == arr[i+1][j])
				{
					arr[i+1][j] = 2*arr[i][j];
					arr[i][j] = 0;
				}
			}
		}

		for(int i=n-2; i>0; i--)
		{
			for(int j=1; j<n; j++)
			{
				if(arr[i+1][j] == 0)
				{
					arr[i+1][j] = arr[i][j];
					arr[i][j] = 0;
				}
			}
		}
				
	}
	else if(key == 75)
	{
		for(int k=1; k<n-1;k++)
		{
			for(int i=1; i<n; i++)
			{
				for(int j=2; j<n; j++)
				{
					if(arr[i][j-1] == 0)
					{
						arr[i][j-1] = arr[i][j];
						arr[i][j] = 0;
					}
				}
			}
		}
	
		for(int i=1; i<n; i++)
		{
			for(int j=2; j<n; j++)
			{
				if(arr[i][j] == arr[i][j-1])
				{
					arr[i][j-1] = 2*arr[i][j];
					arr[i][j] = 0;
				}
			}
		}
		for(int i=1; i<n; i++)
		{
			for(int j=2; j<n; j++)
			{
				if(arr[i][j-1] == 0)
				{
					arr[i][j-1] = arr[i][j];
					arr[i][j] = 0;
				}
			}
		}
		
	}
	else if(key == 77)
	{
		for(int k=1; k<n-1;k++)
		{
			for(int i=1; i<n; i++)
			{
				for(int j=n-2; j>0; j--)
				{
					if(arr[i][j+1] == 0)
					{
						arr[i][j+1] = arr[i][j];
						arr[i][j] = 0;
					}
				}
			}
		}
	
		for(int i=1; i<n; i++)
		{
			for(int j=n-2; j>0; j--)
			{
				if(arr[i][j] == arr[i][j+1])
				{
					arr[i][j+1] = 2*arr[i][j];
					arr[i][j] = 0;
				}
			}
		}
		for(int i=1; i<n; i++)
		{
			for(int j=n-2; j>0; j--)
			{
				if(arr[i][j+1] == 0)
				{
					arr[i][j+1] = arr[i][j];
					arr[i][j] = 0;
				}
			}
		}		
	}
	else
	{
		;
	}
}

int main(void)
{
	int (*arr)[6] = (int(*)[6])calloc(36,sizeof(int));
	assert(arr != NULL);
	MyRandom(arr);
	MyShow(arr);
	while(1)
	{
		if(Myvictory(arr))
		{
			break;
		}
		else if(MyCheck(arr))
		{
			break;
		}
		else
		{
			MyRandom(arr);
			MyShow(arr);
			Myshift(arr);
			MyShow(arr);
		}
			
	}
	


	free(arr);
	arr = NULL;
	return 0;
	
	

}



