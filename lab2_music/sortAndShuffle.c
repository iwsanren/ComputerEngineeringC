#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sortAndShuffle.h"

/*
 * This function sorts the songs provided as input alphabetically
 *
 * Inputs:
 *   char songs[MAX_SONGS][MAX_LENGHT]: The songs to be sorted
 *   int numOfSongd: the number of songs to be sorted
 *
 */

void sortSongs(char songs[MAX_SONGS][MAX_LENGTH], int numOfSongs){
    int i =0;
    int j=0;
    int minIndex = 0;
    int minIndexChanged = 0;

    char swap [MAX_LENGTH];



    for(i=0; i< (numOfSongs-1); i ++){
        minIndex = i;
        for(j=i+1; j<numOfSongs; j++){

            if(strcmp(songs[j], songs[minIndex]) < 0){
                minIndex = j;
                minIndexChanged =1;
            }
        }

            if(minIndexChanged == 1){
                memset(swap, '$', MAX_LENGTH-2);
                swap[MAX_LENGTH -1] = '\0';
                printf("%s\n", swap);
                strcpy(swap,songs[i]);
                strcpy(songs[i], songs[minIndex]);
                strcpy(songs[minIndex], swap);
                minIndexChanged =0;
            }

    }
}


/*
 * This function sorts the artists provided as input alphabetically
 *
 * Inputs:
 *   char sortedArtists[][MAX_LENGHT]: The artists to be sorted
 *   int numOfArtists: the number of artists to be sorted
 *
 */
void sortArtists(char sortedArtists[MAX_ARTISTS][MAX_LENGTH] , int numOfArtists){
    int i =0;
    int j=0;
    int minIndex = 0;
    int minIndexChanged = 0;

    char swap [MAX_LENGTH];


    for(i=0; i< (numOfArtists-1); i ++){
        minIndex = i;
        for(j=i+1; j<numOfArtists; j++){

            if(strcmp(sortedArtists[j], sortedArtists[minIndex]) < 0){
                minIndex = j;
                minIndexChanged =1;
            }
        }

            if(minIndexChanged == 1){
                memset(swap, '$', MAX_LENGTH-2);
                swap[MAX_LENGTH -1] = '\0';
                printf("%s\n", swap);
                strcpy(swap,sortedArtists[i]);
                strcpy(sortedArtists[i], sortedArtists[minIndex]);
                strcpy(sortedArtists[minIndex], swap);
                minIndexChanged =0;
            }

    }
}

/*
 * This function adds to the array shuffledSongs  the songs of a specific artist to be shuffled
 * Songs will be represented in the format <artist name> - <song name>
 *
 * Inputs:
 *   char artist[MAX_LENGTH]: The artists of the song,
 *   char songs[][MAX_LENGTH]: The songs of the artist
 *   char shuffledSongs[][MAX_LENGTH]: the array containing all the songs to be shuffled
 *   int artistIndex: the index in the array of the songs to be shuffled from where the songs should be added
 *   int numOfSongs: the number of songs to be added for a specific artist
 *
 */
void fillShuffledSongs(char artist[MAX_LENGTH], char songs[][MAX_LENGTH], char shuffledSongs[][MAX_LENGTH], int artistIndex, int numOfSongs ){

    for(int i=0; i< numOfSongs; i++){
        strcpy(shuffledSongs[artistIndex], artist);

        strcat(shuffledSongs[artistIndex], " - ");

        strcat(shuffledSongs[artistIndex], songs[i]);

        artistIndex++;
    }

}

/*
 * This function shuffles the songs provided as input
 *
 * Inputs:
 *   char char songsToBeShuffled[][MAX_LENGTH]: The songs to be shuffled
 *   int numOfSongs: the total number of songs to be shuffled
 *
 */
void shuffleSongs(char shuffledSongs[][MAX_LENGTH] , int numOfSongs){

    int i, j;
    char swap[MAX_LENGTH];
    srand(time(NULL));   // should only be called once

    do {
        for (i = 1; i < numOfSongs; i++) {
            j = rand()%(i+1);

            if(j!=i){
                strcpy(swap,shuffledSongs[j]);
                strcpy(shuffledSongs[j],shuffledSongs[i]);
                strcpy(shuffledSongs[i],swap);
            }
        }
    } while(check5Songs(shuffledSongs,numOfSongs) == 0);
}


/*
 * This function checks whether a song it is not repeated at least after 5 other different songs
 *
 * Inputs:
 *   char shuffledSongs[][MAX_LENGTH]: The songs to be shuffled
 *   int numOfSongs: the total number of songs to be shuffled
 *
 * Outputs:
 * returns 0 if a song is repeated before 5 other different songs
 * returns 1 otherwise
 */
int check5Songs(char shuffledSongs[][MAX_LENGTH] , int numOfSongs){

    int songsChecked =0;
    for (int i = 0;  i < numOfSongs && songsChecked < numOfSongs/2; i++) {
        for(int j = 1; j <= 5 && i+j < numOfSongs; j++){
            if(strcmp(shuffledSongs[i], shuffledSongs[i+j]) == 0)
                return 0;
            }
        songsChecked++;

	}
	return 1;
}


