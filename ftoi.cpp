#if 0

#include <stdio.h>
#include <memory.h>

//以二进制的形式输出unsigned long 
void MyShow(unsigned long ina)
{
	for(int i=31; i>=0; i--)
	{
		if((ina & 1<<i) != 0)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
	printf("\n");
}

//读出指定位二进制数字的大小,从右数第2位到第9位
int GetDigit(unsigned long ina)
{
	int num = 0;
	for(int i=23; i<31; i++)
	{
		num |= (ina & 1<<i);
	}

	num >>= 23;
	num -= 127;//ieee 规定指数位须减去127 为真正的指数
	
	return num;
}

//得到并记录符号位
int GetNe(unsigned long ina)
{
	int a = ina & (1<<31);

	if(a != 0)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

int MyFtoi(float fla)
{
	unsigned long ina;
	memcpy(&ina ,&fla,sizeof(float));
	int Na = GetNe(ina);//得到符号位;
	//printf("%d\n",Na);
	int num = GetDigit(ina);//得到指数位的大小
	
	ina &= (1<<23)-1;//保留小数位
	ina |= 1<<23;//填入小数位前的 1
	ina >>= (23-num);//整数部分右移到合适位置
//	MyShow(ina);
	//ina |= (Na<<31);//填上符号位,如果为负数，这种办法需要取补码
	/*if(GetNe)
	{
		ina *= -1;
	}
	else
	{
		ina *= 1;	
	}*/
	ina *= Na;
//	MyShow(ina);
	return ina;
}



int main()
{
	float fla = -12.5;
	int ia = MyFtoi(fla);
//	MyShow(ia);
	printf("%d\n",ia);
	printf("%d\n",MyFtoi(12.7));
	printf("%d\n",MyFtoi(0.7));
	printf("%d\n",MyFtoi(-2.7));
	printf("%d\n",MyFtoi(12.0));
	printf("%d\n",MyFtoi(1.7));
	printf("%d\n",MyFtoi(10.7));
	printf("%d\n",MyFtoi(100.7));

}


#endif