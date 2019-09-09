
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
int main(int argc,char * argv[])
{
	if(argc<4){
	   printf("1:encrption/2:decrption keyword plaintext/ciphertext\n");
	   return 0;
	}
	int i, j, l, k, m, num[30];
	char key[30], plantext[100], plantext2[100], cipher[100];
	//printf("keyword\n");
	//scanf("%s", key);
        strcpy(key,argv[2]);
 
	l = strlen(key);

	for (i = 0; i < l; i++)
	{
		num[i] = 0;
		for (j = 0; j < l; j++)
		{

			if (key[j] <= key[i])
			{

				num[i] = num[i] + 1;
			}
			if (key[j] == key[i] && j > i)
				num[i] = num[i] - 1;

		}
	}
	if(atoi(argv[1])==1){
//	printf("plaintext\n");
//	scanf("%s", plantext);
        strcpy(plantext,argv[3]);
	k = strlen(plantext);

	i = 0;											/*末尾补x*/
	
	for (m = k % l; m < l; m++)
	{

		plantext[k + i] = 'x';
		i++;
	}

	if (k%l == 0)										/*计算有多少行*/
	
		m = k / l;
	else
		m = k / l + 1;
	printf("ciphertext:\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < l; j++)
		{

			cipher[i*l + j] = plantext[i*l + num[j] - 1];

		}
	}
	for (i = 0; i < l; i++)								/*输出密文*/

	{
		for (j = 0; j < m; j++)
			printf("%c", cipher[j*l + i]);
	}
	printf("\n");
	}

       else{
	//printf("cipher:\n");								/*解密密文*/
	//scanf("%s", cipher);
        strcpy(cipher,argv[3]);
	k = strlen(cipher);

	i = 0;											/*末尾补x*/
	
	for (m = k % l; m < l; m++)
	{

		plantext[k + i] = 'x';
		i++;
	}

	if (k%l == 0)										/*计算有多少行*/
	
		m = k / l;
	else
		m = k / l + 1;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < l; j++)
		{

			plantext2[i*l + num[j] - 1] = cipher[i*l + j];
		}
	}
	plantext2[(i - 1)*l + j] = '\0';
	printf("plaintext\n");
	printf("%s\n", plantext2);
       }
	return 0;
}










