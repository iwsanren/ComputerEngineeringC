#include <stdio.h>
#include <string.h>
#include "inputOutput.h"


/*
 * This method finds the order in which an artist was inserted
 *
 * Inputs:
 * char artists[MAX_ARTISTS][MAX_LENGHT]: The array of artists provided as input
 * char artist[MAX_LENGTH]: The artist to be looked for
 * int numOfArtists : the total number of artists
 *
 * Outputs:
 * it returns an integer indicating the order in which the artist was inserted
 */
int findArtist(char artists[MAX_ARTISTS][MAX_LENGTH], char artist[MAX_LENGTH], int numOfArtists){
    int i;
    for(i=0; i< numOfArtists; i++){
        if(strcmp(artists[i],artist)== 0)
            break;
    }
    return i;
}


/*
 * This method writes a set of songs provided  from the command line
 * in an array provided as input.
 *
 * Inputs:
 * char songs[MAX_SONGS][]: The array of songs to be written
 *
 * Output: The number of songs provided as input
 */
    int insertSongs(char artistName[MAX_LENGTH], char songs[MAX_SONGS][MAX_LENGTH]) {
        int j, lengthSong;
        // Insert the songs
        for(j=0; j < MAX_SONGS; j++){
            printf("Insert Song %d for %s: ", j+1,  artistName);
            fgets(songs[j], MAX_LENGTH, stdin);

             //Makes sure at least one song is inserted
            while(j== 0 && songs[j][0] == '\n'){
                printf("******At least 1 song for each artist should be inserted******\n\n");
                printf("Insert Song %d for %s: ", j+1, artistName);
                fgets(songs[j], MAX_LENGTH, stdin);
            }

            //If the return command is pressed it exits
            if(songs[j][0]=='\n'){
                break;
            }
            lengthSong = strlen(songs[j]);
            songs[j][lengthSong -1] = '\0';
        }
        return j;

       }


/*
 * This method prints the songs provided as input
 *
 * Inputs:
 * char songs[MAX_SONGS][MAX_LENGHT]: The array of songs to be printed
 * int numOfSongs: The number of songs to be printed
 *
 */

void printSongs(char songs [][MAX_LENGTH], int numOfSongs){
    int i ;
    for(i=0; i< numOfSongs; i++){
        printf("\n\t - %s", songs[i]);
    }
}

