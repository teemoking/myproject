/***
** @date 2017.10.14
** @author AK
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Myitoa(char **strs,int in,int n)//n:2-36
{
	char *substr = "abcdefghijklmnopqrstuvwxyz";

	int in1 = in;
	int in2 = in;
	int i = 0;
	int j = 0;
	char temp;
	while(in>0)
	{
		in /= n;
		i++;
	}
	char *str = (char*)malloc(sizeof(char)*(i));
	char *str1= str;
	char *str2= str;
	for(;in1>0;)
	{
		in1 %= n;
		if(in1<10)
		{
			*str = '0'+in1;
		}
		else
		{
			*str = substr[in1-10];
		}
		str++;
		in2 /= n;
		in1 = in2;
	}
	*str = '\0';
	//ÄæÐò×Ö·û´®
	str--;
	while(i>j)
	{
		temp  = *str;
		*str-- = *str1;
		*str1++ = temp;
		i--;
		j++;
	}
	//strcpy(*strs,str2);
	free(str2);
	str2 = NULL;

}

//int fun (void *arr)
//{
//	int i = 0;
//	arr[i]; 
//}
int main()
{
	char *str = NULL;
	////strcpy(str,str1);
	//Myitoa(&str,1233,2);
	//printf("%s",str);
	void *vp = str;
	//*vp;
	printf("%d",sizeof(vp));
	float t = 0.12345678910111213141516;
	printf("%f",t);
	char *s ="12222";
	char *ss ="12222";
	printf("%d",strcmp("1111","1111"));

	/*free(str);//error:ÎÞ·¨Ö´ÐÐ
	str = NULL;*/
	return 0;
}
