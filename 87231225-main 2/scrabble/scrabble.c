#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int computescore(string word);

int main(void)
{

    // Take input from users for two strings for comparision

    string firstword = get_string("Player 1: ");
    string secondword = get_string("Player 2: ");

    int player1score = computescore(firstword);

    int player2score = computescore(secondword);

    // compare the points based on letters entered by each user and print who is the winner

    // store the point value for each letter

    // compare the total points for each user and print the winner details  or print tie if both are
    // equal

    if (player1score > player2score)
    {
        printf("Player 1 wins!");
    }
    else if (player2score > player1score)
    {
        printf("Player 2 wins!");
    }
    else if (player1score == player2score)
    {
        printf("Tie!");
    }
}

int computescore(string word)
{

    // compare the points based on letters entered by each user and print who is the winner

    // store the point value for each letter

    int alphabets[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                       1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int score = 0;

    // Compute total points for each user based on point values for letters entered

    for (int i = 0; i < strlen(word); i++)
    {

        int upperchar = toupper(word[i]);

        if (isalpha(upperchar))
        {
            int alphabetscore = upperchar - 'A';

            score = score + alphabets[alphabetscore];
        }
    }

    return score;
}
