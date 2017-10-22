/***
** @date 2017.9.23
** @author AK
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool MyCheck(int (*arr)[8], int x,int y)//���ָ��λ���Ƿ����
{
	int i;
	for(i=-7; i<8; i++)//�ж� x+i y+i x-i y-i ��Χ
	{
		if(i==0)//�ų�arr[x][y]����
		{
			continue;
		}
		if((x+i)>=0 && (x+i)<8)//����������к��еġ�1���Ƿ��ͻ
		{
			if((y+i)>=0 && (y+i)<8)
			{
				if(arr[x+i][y+i]==1)
				{
					return false;
				}
			}
			if((y-i)>=0 && (y-i)<8)
			{
				if(arr[x+i][y-i]==1)
				{
					return false;
				}
			}
			if(y>=0 && y<8)
			{
				if(arr[x+i][y]==1)
				{
					return false;
				}
			}
		}
		if((y+i)>=0 && (y+i)<8)//����������к��еġ�1���Ƿ��ͻ
		{
			if(arr[x][y+i]==1)
			{
				return false;
			}
		}
		
	}
	return true;
}

void MyShow(int (*arr)[8],int n)//����ʺ�����з�ʽ
{
	printf("\n---��%d��\n",n);
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
		{
			printf("%3d",arr[i][j]);
		}
		printf("\n");
	}
	printf("-----------------------------------------\n");
}

int MyInit(void)//����������ʺ�����
{
	int (*arr)[8] = (int(*)[8])calloc(64,sizeof(int));
	int i,j;
	int n=0;
	int count = 0;
	
	for(int x0=0; x0<8; x0++)//���������и�ֵ
	{
		memset(arr,0,8*sizeof(int));//��һ��Ԫ����Ϊ0
		arr[0][x0] = 1;
		for(int x1=0; x1<8; x1++)
		{
			memset(arr+1,0,8*sizeof(int));
			arr[1][x1] = 1;
			for(int x2=0; x2<8; x2++)
			{
				memset(arr+2,0,8*sizeof(int));
				arr[2][x2] = 1;
				for(int x3=0; x3<8; x3++)
				{
					memset(arr+3,0,8*sizeof(int));
					arr[3][x3] = 1; 
					for(int x4=0; x4<8; x4++)
					{
						memset(arr+4,0,8*sizeof(int));
						arr[4][x4] = 1;
						for(int x5=0; x5<8; x5++)
						{
							memset(arr+5,0,8*sizeof(int));
							arr[5][x5] = 1;
							for(int x6=0; x6<8; x6++)
							{
								memset(arr+6,0,8*sizeof(int));
								arr[6][x6] = 1;
								for(int x7=0; x7<8; x7++)
								{
									memset(arr+7,0,8*sizeof(int));
									arr[7][x7] = 1;
								//action�����Ϊ��1����λ���Ƿ����
									//MyShow(arr);
									n = 0;
									for(i=0; i<8; i++)
									{
										for(j=0; j<8; j++)
										{
											if(arr[i][j] == 1)
											{
												if(!MyCheck(arr,i,j))
												{
													goto loop;//��������ѭ��
												}
												else
												{
													n++;
												}
												if(n==8)
												{
													count++;
													MyShow(arr,count);
												}
											}
				
										}
									}
									loop:;
									//end
								}
							}
						}
					}
				}
			}
		}
	}
	free(arr);
	arr = NULL;
	return count;
}

int main()
{
	MyInit();
	return 0;
}
