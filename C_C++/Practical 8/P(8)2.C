#include<stdio.h>
#include<conio.h>

struct cricket 
{
    char player_name[50];
    char team_name[50];
    float batting_average;
};

void main() 
{
    struct cricket player1;
    clrscr();

    // Example usage of the cricket structure
    printf("Enter player name: ");
    fgets(player1.player_name, 50, stdin);

    printf("Enter team name: ");
    fgets(player1.team_name, 50, stdin);

    printf("Enter batting average: ");
    scanf("%f", &player1.batting_average);

    printf("Player name:     %s", player1.player_name);
    printf("Team name:       %s", player1.team_name);
    printf("Batting average: %.2f\n", player1.batting_average);

    getch();
}
