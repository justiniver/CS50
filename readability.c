#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words (string text);
int count_sentences (string text);

int main(void)
{
    string text = get_string("Text: ");
    int L = count_letters(text);
    int W = count_words(text);
    int S = count_sentences(text);
    printf("%s\n", text);
    printf("Letters: %i\n", L);
    printf("Words: %i\n", W);
    printf("Sentences: %i\n", S);

    int AL = 100 * L / W;
    int AS = 100 * S / W;
    int index = 0.0588 * AL - 0.296 * AS - 15.8;
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int num_letters = 0;
    for (int i = 0; i <= strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            num_letters++;
        }
    }
    return num_letters;
}

int count_words(string text)
{
    int num_words = 1;
    for (int t = 0; t <= strlen(text); t++)
    {
        if (isspace(text[t]))
        {
            num_words++;
        }
    }
    return num_words;
}

int count_sentences(string text)
{
    int num_sentences = 0;
    for (int s = 0; s <= strlen(text); s++)
    {
        if (text[s] == 46 || text[s] == 33 || text[s] == 63)
        {
            num_sentences++;
        }
    }
    return num_sentences;
}

