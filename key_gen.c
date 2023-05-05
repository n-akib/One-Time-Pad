#include <stdio.h>
#define LEN 12 // 12 bytes = 96 bits
int main()
{
    FILE *randFile, *outFile;
    int i;
    unsigned char next;

    randFile = fopen("/dev/urandom", "r");
    outFile = fopen("key.txt", "w");
    if (randFile == NULL || outFile == NULL)
    {
        printf("Error opening files");
        exit(1);
    }

    for (i = 0; i < LEN; i++)
    {
        fscanf(randFile, "%c", &next);
        fprintf(outFile, "%02X", next);
    }

    fclose(randFile);
    fclose(outFile);

    return 0;
}
