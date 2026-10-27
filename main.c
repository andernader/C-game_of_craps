#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int roll_dice(void);
bool play_game(void);

int main(void){
    char char_control;
    int wins = 0, losses = 0;

    srand((unsigned)time(NULL));

    printf("Shall we start the game of crap!?\n");
    printf("Press y for Yes and n for No.\n");
    printf("Enter: ");
    scanf(" %c", &char_control);

    if(char_control == 'n' || char_control == 'N')
        return 0;

    again:
    if(play_game())
        wins++;
    else
        losses++;

    printf("\n\nPlay again? ");
    scanf(" %c", &char_control);
    if(char_control == 'y' || char_control == 'Y')
        goto again;

    printf("Wins: %d, Loses: %d\n", wins, losses);
}

int roll_dice(void){
    int dice1, dice2;

    dice1 = 1 + rand() % 6;
    dice2 = 1 + rand() % 6;

    return dice1 + dice2;
}

bool play_game(void){
    int dices = roll_dice();
    int point;
    printf("\n\nYou rolled: %d\n", dices);
    if(dices == 7 || dices == 11){
        printf("You win!\n");
        return true;
    }else if(dices == 2 || dices == 3 || dices == 12){
        printf("You lose!\n");
        return false;
    }else{
        point = dices;
        printf("Your point is %d\n", point);
        for(;;){
            dices = roll_dice();
            printf("You rolled: %d\n", dices);
            if(dices == 7){
                printf("You lose!\n");
                return false;
            }else if(dices == point){
                printf("You win!\n");
                return true;
            }
        }
    }
}
