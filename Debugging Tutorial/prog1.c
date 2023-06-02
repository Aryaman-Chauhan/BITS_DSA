#include <stdio.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    // read character by character from file test.txt
    FILE *fp = fopen("test.txt", "r");
    char c = fgetc(fp);
    while (c != EOF)
    {
        if (isalpha(c))
        {
            printf("%c", c);
        }
    }
    printf("\nFile read complete.\n");
    return 0;
}