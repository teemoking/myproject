/***
** @date 2017.10.18
** @author AK
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
void mymemcpy(unsigned char *const des,unsigned char *const src,int num)
{
	assert(des!=NULL && src!= NULL);

	if(des > src)
	{
		for(int i=0; i<num; i++)
		{
			des[i] = src[i];
		}
	}
	else
	{
		for(int i=num; i>0; i--)
		{
			des[i-1] = src[i-1];
		}
	}
}

int main()
{
	char a[] = "abc123o";
	char b[sizeof(a)] ;
	mymemcpy((unsigned char*)&b,(unsigned char*)&a,sizeof(a));
	
	return 0;
}
