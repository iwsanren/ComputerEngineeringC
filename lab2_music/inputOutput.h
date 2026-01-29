#include "sortAndShuffle.h"


/*
 * This method writes a set of songs provided  from the command line
 * in an array provided as input.
 *
 * Inputs:
 * char songs[MAX_SONGS][]: The array of songs to be written
 *
 * Output: The number of songs provided as input
 */
int insertSongs(char artistName[MAX_LENGTH], char songs[MAX_SONGS][MAX_LENGTH]);

/*
 * This method prints the songs provided as input
 *
 * Inputs:
 * char songs[MAX_SONGS][MAX_LENGHT]: The array of songs to be printed
 * int numOfSongs: The number of songs to be printed
 *
 */

void printSongs(char songs [MAX_SONGS][MAX_LENGTH], int numOfSongs);

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
int findArtist(char artists[MAX_ARTISTS][MAX_LENGTH], char artist[MAX_LENGTH], int numOfArtists);
