#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);
string maiuscula(string str);


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
        candidates[i].name = maiuscula(argv[i + 1]);
        candidates[i].votes = 0;
    }


    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        name = maiuscula( name);
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
    for( int i = 0;  i < candidate_count; i++){
        if(  strcmp( maiuscula(candidates[i].name), maiuscula(name) ) == 0 ){
            candidates[i].votes+= 1;
            return true;
        }
    }
    return false;

 }

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    // controlar total de votoa e ver votos nulos

    int ganhador = candidates[0].votes;
    for( int i = 0;  i < candidate_count; i++){
       if( candidates[i].votes > ganhador){
            ganhador = candidates[i].votes;
        }
    }

    if ( ganhador >0 ){
        for( int i = 0;  i < MAX; i++){
           if( candidates[i].votes == ganhador){
               printf("%s\n",  candidates[i].name);
            }
        }
    }else{
        printf("\n");
    }

//    return;
}


string maiuscula(string str){

    int TamStr = strlen(str);
    for( int i=0;  i< TamStr; i++)
    {
        str[i] = toupper(str[i]);
    }
    return str;
}