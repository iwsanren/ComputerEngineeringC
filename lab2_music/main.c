#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortAndShuffle.h"
#include "inputOutput.h"




int main()
{
    //The array containing artists names
    char artists[MAX_ARTISTS][MAX_LENGTH];
    //The array containing the sorted artists
    char sortedArtists[MAX_ARTISTS][MAX_LENGTH];
    //Songs for Artist 1
    char songsArtist1[MAX_SONGS][MAX_LENGTH];
    //Songs for Artist 2
    char songsArtist2[MAX_SONGS][MAX_LENGTH];
    //Songs for Artist 3
    char songsArtist3[MAX_SONGS][MAX_LENGTH];
    //Songs for Artist 4
    char songsArtist4[MAX_SONGS][MAX_LENGTH];
    //The total number of artists (Note it can be less than 4)
    int numOfArtists =0;
    //The total number of songs for each artist (Note that less than 3 songs can be provided for each artist)
    int numSongsPerArtist[MAX_ARTISTS];

    //The total number of songs for each artist (Note that less than 3 songs can be provided for each artist)
    char shuffledSongs[MAX_ARTISTS * MAX_SONGS*2][MAX_LENGTH];

    //indexes
    int i, length, index;

    /*
    * Use here functions that you should implement to insert artists and songs from the standard input.
    * Note that you also need to track the number of artists and the number of songs for each artist.
    */

    //Insert the artist
    for(i=0; i< MAX_ARTISTS; i++){
        printf("Insert Artist %d: ", i+1);
        fgets(artists[i], MAX_LENGTH, stdin);

        //Makes sure at least one artist is inserted
        while(i== 0 && artists[i][0] == '\n'){
            printf("******At least 1 Artist should be inserted******\n\n");
            printf("Insert Artist %d: ", i+1);
            fgets(artists[i], MAX_LENGTH, stdin);
        }

        //If the return command is pressed it exits
        if(artists[i][0] == '\n')
            break;

        //Remove carriage return from artist
        length = strlen(artists[i]);
        artists[i][length -1] = '\0';

        switch(i){
            case 0: numSongsPerArtist[0] = insertSongs(artists[i],songsArtist1);
                    break;
            case 1: numSongsPerArtist[1] = insertSongs(artists[i],songsArtist2);
                    break;
            case 2: numSongsPerArtist[2] = insertSongs(artists[i],songsArtist3);
                    break;
            case 3: numSongsPerArtist[3] = insertSongs(artists[i],songsArtist4);
                    break;
        }
    }

    numOfArtists = i;

    //Remove the carriage return from the song



    /*
    * Use here the function sortArtists to sort the array of the artists and sortSongs to sort the songs of each artist
    * Print each artist (alphabetically) and for each of them print the list of songs sorted alphabetically
    */
    for(i=0; i< numOfArtists; i++)
        strcpy(sortedArtists[i], artists[i]);
    sortArtists(sortedArtists, numOfArtists);
    for(i=0; i< numOfArtists; i++){

         switch(i){
            case 0: sortSongs(songsArtist1, numSongsPerArtist[i]);
                    break;
            case 1: sortSongs(songsArtist2, numSongsPerArtist[i]);
                    break;
            case 2: sortSongs(songsArtist3, numSongsPerArtist[i]);
                    break;
            case 3: sortSongs(songsArtist4, numSongsPerArtist[i]);
                    break;
        }
    }

    //print sorted artists
    for(i=0; i< numOfArtists; i++){
        index = findArtist(artists,sortedArtists[i], numOfArtists);
        printf("\n%s", sortedArtists[i]);
        switch(index){
            case 0: printSongs(songsArtist1, numSongsPerArtist[index]);
                    break;
            case 1: printSongs(songsArtist2, numSongsPerArtist[index]);
                    break;
            case 2: printSongs(songsArtist3, numSongsPerArtist[index]);
                    break;
            case 3: printSongs(songsArtist4, numSongsPerArtist[index]);
                    break;
        }
    }

    /*
    * Use here the function shuffleSongs to shuffle all the songs
    * Print the list of shuffled songs
    */

   index = 0;
   //fill shuffledSongs
   //copy all the songs twice in the format <Artist Name> - <Song Name>
    for(i=0; i< numOfArtists*2; i++){
        int k = i%numOfArtists;
        switch(k){
            case 0: fillShuffledSongs(artists[k], songsArtist1, shuffledSongs, index, numSongsPerArtist[k]);
                    break;
            case 1: fillShuffledSongs(artists[k],songsArtist2, shuffledSongs, index, numSongsPerArtist[k]);
                    break;
            case 2: fillShuffledSongs(artists[k],songsArtist3, shuffledSongs, index, numSongsPerArtist[k]);
                    break;
            case 3: fillShuffledSongs(artists[k],songsArtist4, shuffledSongs, index, numSongsPerArtist[k]);
                    break;
        }
        index += numSongsPerArtist[k];
    }

    shuffleSongs(shuffledSongs, index);

    printSongs(shuffledSongs, index);

    return 0;

}
