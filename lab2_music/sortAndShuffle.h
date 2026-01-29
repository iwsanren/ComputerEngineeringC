//max number of songs
#define MAX_SONGS 3
//max length of each song and artist
#define MAX_LENGTH 80
//max number of artists
#define MAX_ARTISTS 4


/*
 * This function sorts the songs of an artist alphabetically
 *
 * Inputs:
 *   char songs[][MAX_LENGHT]: The songs to be sorted
 *   int numOfSongs: the number of songs to be sorted
 *
 */
void sortSongs(char songs[MAX_ARTISTS][MAX_LENGTH], int numOfSongs);

/*
 * This function sorts the artists provided as input alphabetically
 *
 * Inputs:
 *   char sortedArtists[][MAX_LENGHT]: The artists to be sorted
 *   int numOfArtists: the number of artists to be sorted
 *
 */
void sortArtists(char sortedArtists[MAX_SONGS][MAX_LENGTH] , int numOfArtists);


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
void fillShuffledSongs(char artist[MAX_LENGTH], char songs[][MAX_LENGTH], char shuffledSongs[][MAX_LENGTH], int artistIndex, int numOfSongs);


/*
 * This function shuffles the songs provided as input
 *
 * Inputs:
 *   char char songsToBeShuffled[][MAX_LENGTH]: The songs to be shuffled
 *   int numOfSongs: the total number of songs to be shuffled
 *
 */
void shuffleSongs(char songsToBeShuffled[][MAX_LENGTH], int numOfSongs);

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
int check5Songs(char shuffledSongs[][MAX_LENGTH] , int numOfSongs);
