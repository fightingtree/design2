#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

	char c[100];
	char p[100];
	int k = 3;
	int i;

	printf("Please input ciphertext:\n");
	fgets(p,100,stdin);
	for (i = 0; p[i] != '\0'; i++) {
		c[i] = (p[i] - 'a' -k) % 26 + 'a';
	}
	c[i] = '\0';
	/*
	for (i = 0; p[i] != '\0'; i++) {
		c[i] = (p[i] - 'A'-k) % 26 + 'A';
	}
	c[i] = '\0';*/
	printf("plaintext\n%s\n", c);
	return 0;
}
