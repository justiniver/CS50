#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string text);
char rotate(char c, int key);

int main(int argc, string argv[])
{
        if (argc == 2 && only_digits(argv[1]))
        {
            int key = atoi(argv[1]);
            string text = get_string("plaintext:  ");
            printf("ciphertext: ");
            for (int i = 0; i <= strlen(text); i++)
            {
                printf("%c", rotate(text[i], key));
            }
            printf("\n");
        }
        else
        {
            printf ("Usage: ./caesar key\n");
        }
}

bool only_digits(string text)
{
    bool result = true;
    for (int i = 0; i < strlen(text); i++)
    {
        if (!isdigit(text[i]))
        {
            result = false;
        }
    }
    return result;
}

char rotate(char c, int key)
{
    char d = c;
    if (isupper(c))
    {
        d = (c - 65 + key) % 26 + 65;
    }
    else if (islower(c))
    {
        d = (c - 97 + key) % 26 + 97;
    }
    else
    {
        d = c;
    }
    return d;
}
