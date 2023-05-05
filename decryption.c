#include <stdio.h>
#define LEN 12

int main()
{
    FILE *keyFile, *dFile, *cFile;
    int i;
    unsigned char ch1, ch2;

    keyFile = fopen("key.txt", "r");
    dFile = fopen("dtext.txt", "w");
    cFile = fopen("ctext.txt", "r");

    if (keyFile == NULL || dFile == NULL || cFile == NULL)
    {
        printf("File error!\n");
        return 1;
    }

    for (i = 0; i < LEN; i++)
    {
        fscanf(keyFile, "%2hhX", &ch1);
        fscanf(cFile, "%2hhX", &ch2);
        fprintf(dFile, "%c", (char)ch1 ^ ch2);
    }

    fclose(keyFile);
    fclose(dFile);
    fclose(cFile);
    return 0;
}
