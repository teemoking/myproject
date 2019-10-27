#if 0

#include <stdio.h>
#include <memory.h>

//�Զ����Ƶ���ʽ���unsigned long 
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

//����ָ��λ���������ֵĴ�С,��������2λ����9λ
int GetDigit(unsigned long ina)
{
	int num = 0;
	for(int i=23; i<31; i++)
	{
		num |= (ina & 1<<i);
	}

	num >>= 23;
	num -= 127;//ieee �涨ָ��λ���ȥ127 Ϊ������ָ��
	
	return num;
}

//�õ�����¼����λ
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
	int Na = GetNe(ina);//�õ�����λ;
	//printf("%d\n",Na);
	int num = GetDigit(ina);//�õ�ָ��λ�Ĵ�С
	
	ina &= (1<<23)-1;//����С��λ
	ina |= 1<<23;//����С��λǰ�� 1
	ina >>= (23-num);//�����������Ƶ�����λ��
//	MyShow(ina);
	//ina |= (Na<<31);//���Ϸ���λ,���Ϊ���������ְ취��Ҫȡ����
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