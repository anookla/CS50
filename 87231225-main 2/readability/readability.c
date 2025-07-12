#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int countWords(string s);
int countLetters(string s);
int countSentences(string s);

int main(void)
{

    // take input text to analyze
    string s = get_string("Text:");

    // process the provided text and output the grade rounded to nearest integer

    // total words = total of length of input string excluding spaces

    int totalWords = countWords(s);

    // total number of sentences = total number of fullstops+1

    int totalSentences = countSentences(s);

    // total number of letters = sum(letters in each word)
    int totalLetters = countLetters(s);

    // average number of letters AL = total number letters / total number of words

    float averageLetters = (totalLetters / (float) totalWords) * 100;

    // average number of sentences AS = total number of sentences/total number of words

    float averageSentences = (totalSentences / (float) totalWords) * 100;

    // L = AL * 100

    // S = AS * 100

    // formula to calculate index = 0.0588 * L - 0.296 * S - 15.8
    // where L is the average number of letters per 100 words in the text, and S is the average
    // number of sentences per 100 words in the text.

    int index = (int) round(0.0588 * averageLetters - 0.296 * averageSentences - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+");
    }
    else if (index < 1)
    {
        printf("Before Grade 1");
    }
    else
    {
        printf("Grade %i", index);
    }

    printf("\n");

    //  if index >= grade 16 or higher then print "Grade 16+" else if index less than grade 1 then
    //  print "Before Grade 1" else  integer grade(index)
}

int countLetters(string s)
{
    int TotalLetters = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]))
        {
            TotalLetters++;
        }
    }
    return TotalLetters;
}

int countWords(string s)
{
    int TotalSpaces = 0;
    char subString = ' ';

    for (int i = 0, n = strlen(s); i < n; i++)
    {

        if (s[i] == subString)
        {
            TotalSpaces++;
        }
    }

    return TotalSpaces + 1;
}

int countSentences(string s)
{
    int TotalSentences = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == '.')
        {
            TotalSentences++;
        }
        else if (s[i] == '?')
        {
            TotalSentences++;
        }
        if (s[i] == '!')
        {
            TotalSentences++;
        }
    }
    return TotalSentences;
}
