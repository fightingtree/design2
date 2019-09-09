#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int main()
{
	char key[100];
	char function, c, temp;
	int len, t, i = 0, j = 0;
	printf("Vigenere cipher:\n1:encrption\n2:decrption\ninput1/2:");
	scanf("%c", &function);
	if (function == '1')
	{
		if (getchar() == '\n')
			temp = ' ';
		printf("input keyword:");
		fgets(key,9,stdin);
		len = strlen(key)-1;
	//	printf("%d\n", len);
		if (len >= 10)
		{
			printf("ERROR!");
			return 0;
		}
		for (t = 0; t < len; t++)
		{
			if (key[j%len] >= 'A'&&key[j%len] <= 'Z')
			{
				key[t] = key[j%len] + 32;
			}
			else if (key[j%len] >= 'a'&&key[j%len] <= 'z')
			{
				key[t] = key[j%len];
			}
			else
			{
				printf("\nERR0R!");
				return 0;
			}
			j++;
		}
		printf("input plaintext:");
		while ((c = getchar()) != '\n')
		{
			if (c == ' ')
				continue;
			else if (c >= 'a'&&c <= 'z')
			{
				printf("%c", (c - 'a' + key[j%len] - 'a') % 26 + 'a');
				j++;
			}
			else if (c >= 'A'&&c <= 'Z')
			{
				printf("%c", (c - 'A' + key[j%len] - 'A') % 26 + 'A');
				j++;
			}
			else
				printf("\nERROR!");
		}
	}

	else if (function == '2')
	{
		if (getchar() == '\n')
			temp = ' ';
		printf("input keyword:");
		fgets(key,9,stdin);
		len = strlen(key)-1;
		if (len >= 10)
		{
			printf("ERROR!");
			return 0;
		}
		for (t = 0; t < len; t++)
		{
			if (key[j%len] >= 'A'&&key[j%len] <= 'Z')
			{
				key[t] = key[j%len] + 32;
			}
			else if (key[j%len] >= 'a'&&key[j%len] <= 'z')
			{
				key[t] = key[j%len];
			}
			else
			{
				printf("wrong!\n");
				return 0;
			}
			j++;
		}
		printf("input ciphertext:");
		while ((c = getchar()) != '\n')
		{
			if (c == ' ')
				continue;
			else if (c >= 'a'&&c <= 'z')
			{
				printf("%c", (c + 26 - key[j%len]) % 26 + 'a');
				j++;
			}
			else if (c >= 'A'&&c <= 'Z')
			{
				printf("%c", (c + 26 - key[j%len]) % 26 + 'A');
				j++;
			}
			else
				printf("\nERROR !");
		}
	}
	else
	{
		printf("\nFUNCATION ERROR £¡");
	}
	system("pause");
	return 0;
}





