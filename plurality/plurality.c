#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    // iterate over each candidate
    for (int j = 0; j < candidate_count; j++)
    {
        // check if candidate's name mathes given name
        if (strcmp(name, candidates[j].name) == 0)
        {
            candidates[j].votes++;
            return true;
        }
    }
    // if not match, return false
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    int max = 0;

    for (int k = 0; k < candidate_count; k++)
    {

        if (candidates[k].votes > max)
        {
            max = candidates[k].votes;
        }
    }
    for (int l = 0; l < candidate_count; l++)
    {
        if (candidates[l].votes == max)
        {
            printf("%s\n", candidates[l].name);
        }
    }
    return;
}
