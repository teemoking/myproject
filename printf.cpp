#if 0

/**
*@date 2017-10-1
*@version 1.0
*@error 小数点前后的零无法正常输出
*/

#include <stdio.h>
#include <stdarg.h>

//int max_list(int a,...)//不定长度参数返回最大值
//{
//	va_list ap;
//	va_start(ap,a);
//
//	int max = a;
//	int temp = a;
//	while((temp=va_arg(ap,int)) != -1)
//	{
//		if(temp > max)
//		{
//			max = temp;
//		}
//	}
//	va_end(ap);
//	return max;
//}

void print_integer(int integer)//输出整数
{
	if(integer<0)
	{
		putchar('-');
		return print_integer(-integer);
	}
	if(integer == 0)
	{
		//putchar('0');
		return;
	}
	print_integer(integer/10);
	putchar(integer%10+'0');
}

void print_float(const float fla)//输出浮点数
{
	if(fla < 0)
	{
		putchar('-');
		print_float(-fla);
	}
	/*int floa = fla;
	if(fla == floa)
	{
		return print_integer(fla);
	}
	print_float(fla*10);*/
	else
	{
		int afla = (int)fla;
		int bfla = (int)(10000*(fla - afla));
		if((bfla%10)>5)
		{
			bfla = bfla/10+1;
		}
		else
		{
			bfla = bfla/10;
		}
		print_integer(afla);
		putchar('.');
		print_integer(bfla);
	}
}


int My1Printf(char * format,...)//打印函数 
{
	va_list pri;
	va_start(pri,format);
	while(*format)
	{
		if(*format == '%')
		{
			format++;
			switch(*format)
			{
				case 'c'://字符类型
					{
						char temp = va_arg(pri,char);
						putchar(temp);
						format++;
						break;
					}
				case 'd'://整数类型
					{
						int temp = va_arg(pri,int);
						if(temp == 0)
						putchar('0');
						print_integer(temp);
						format++;
						break;
					}
				case 'f'://浮点型
					{
						float temp = va_arg(pri,double);
						if(temp == 0)
						putchar('0');
						print_float(temp);
						format++;
						break;
					}
				case 's'://字符串类型
					{
						char *temp = va_arg(pri,char*);
						while(*temp != '\0')
						{
							putchar(*temp++);
						}
						format++;
						break;
					}
				default:
					{
						putchar(*format++);
					}

			}
		}
		else
		{
			putchar(*format++);
		}

	}
	va_end(pri);
	return 0;
}

int main()
{
	/*char *str = "asdf,qwer,wasd";
	putchar(*str);*/
	//printf("%d\n",max_list(10,11,80,88,0,2,23,-1));
	//int n = printf("%d%d33",10,11);
	//My1Printf("int = %d;\nchar = %c;\nstring = %s;\nfloat = %f\n",1988,'1',"   ",-12.3456);//-12.3456输出错误
	//My1Printf("int = %d;\nchar = %c;\nstring = %s;\nfloat = %f\n",-1988,'c',"",12.3456);//-1988 输出错误，12.3456输出为12.0346
	//My1Printf("int = %d;\nchar = %c;\nstring = %s;\nfloat = %f\n",0,'0',"sqw1234.572828",0.3456);//0无法输出
	//My1Printf("int = %d;\nchar = %c;\nstring = %s;\nfloat = %f\n",12222222,'-',"swwwwqw1234",12.000);
	//My1Printf("int = %d;\nchar = %c;\nstring = %s;\nfloat = %f\n",200222,'f',"sqw12www34",12.0);//12无法输出
	//My1Printf("int = %d;\nchar = %c;\nstring = %s;\nfloat = %f\n",00,'c',"sqw1wwww234",11112.3456);//00无法输出，
	//float  fla = 12.34567;
	/*int integer = 0;
	
	integer = fla;
	while(fla != (int)fla)
		fla *= 10;*/

	//printfloat(12.34567);
	return 0;
}


#endif