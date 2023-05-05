#include <stdio.h>
#define LEN 12

int main()
{
    FILE *keyFile, *pFile, *cFile;
    int i;
    unsigned char ch1;
    char ch2;

    keyFile = fopen("key.txt", "r");
    pFile = fopen("ptext.txt", "r");
    cFile = fopen("ctext.txt", "w");
    if (keyFile == NULL || pFile == NULL || cFile == NULL)
    {
        printf("File error!\n");
        return 1;
    }

    for (i = 0; i < LEN; i++)
    {
        fscanf(keyFile, "%2hhX", &ch1);
        fscanf(pFile, "%c", &ch2);
        fprintf(cFile, "%02X", ch1 ^ ch2);
    }

    fclose(keyFile);
    fclose(pFile);
    fclose(cFile);
    return 0;
}
