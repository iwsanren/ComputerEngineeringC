#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARTISTS 4
#define MAX_SONGS_PER_ARTIST 3
#define MAX_NAME 128
#define MAX_SONGS_TOTAL (MAX_ARTISTS * MAX_SONGS_PER_ARTIST)

typedef struct {
    char name[MAX_NAME];
    int songCount;
    char songs[MAX_SONGS_PER_ARTIST][MAX_NAME];
} Artist;

typedef struct {
    char artist[MAX_NAME];
    char title[MAX_NAME];
} Song;

// ---------- utils ----------
static void trim_newline(char* s) {
    size_t n = strlen(s);
    while (n > 0 && (s[n - 1] == '\n' || s[n - 1] == '\r')) {
        s[n - 1] = '\0';
        n--;
    }
}

static int is_empty_line(const char* s) {
    return s[0] == '\0';
}

// ---------- input ----------
int read_artists(Artist artists[], int maxArtists) {
    int artistCount = 0;
    char buf[MAX_NAME];

    while (artistCount < maxArtists) {
        printf("Insert an artist/group name:\n");
        if (!fgets(buf, sizeof(buf), stdin)) break;
        trim_newline(buf);

        if (is_empty_line(buf)) break; // stop adding artists

        strcpy_s(artists[artistCount].name, sizeof(artists[artistCount].name), buf);
        artists[artistCount].songCount = 0;

        for (int s = 0; s < MAX_SONGS_PER_ARTIST; s++) {
            printf("Insert song %d for %s\n", s + 1, artists[artistCount].name);
            if (!fgets(buf, sizeof(buf), stdin)) break;
            trim_newline(buf);

            if (is_empty_line(buf)) break; // stop adding songs for this artist

            strcpy_s(artists[artistCount].songs[s], sizeof(artists[artistCount].songs[s]), buf);
            artists[artistCount].songCount++;
        }

        // requirement says at least 1 song per artist; if user enters none, we can discard this artist
        if (artists[artistCount].songCount == 0) {
            printf("No song added for this artist; ignoring.\n");
        }
        else {
            artistCount++;
        }
    }

    return artistCount;
}

// ---------- sorting (insertion sort) ----------
void sort_songs_of_artist(Artist* a) {
    for (int i = 1; i < a->songCount; i++) {
        char key[MAX_NAME];
        strcpy_s(key, sizeof(key), a->songs[i]);

        int j = i - 1;
        while (j >= 0 && strcmp(a->songs[j], key) > 0) {
            strcpy_s(a->songs[j + 1], sizeof(a->songs[j + 1]), a->songs[j]);
            j--;
        }
        strcpy_s(a->songs[j + 1], sizeof(a->songs[j + 1]), key);
    }
}

void sort_artists(Artist artists[], int n) {
    for (int i = 1; i < n; i++) {
        Artist key = artists[i];
        int j = i - 1;
        while (j >= 0 && strcmp(artists[j].name, key.name) > 0) {
            artists[j + 1] = artists[j];
            j--;
        }
        artists[j + 1] = key;
    }
}

void print_sorted(const Artist artists[], int n) {
    printf("\nSorted list of songs:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", artists[i].name);
        for (int s = 0; s < artists[i].songCount; s++) {
            printf("- %s\n", artists[i].songs[s]);
        }
    }
}

// ---------- flatten to Song[] ----------
int flatten_songs(const Artist artists[], int artistCount, Song outSongs[], int maxSongs) {
    int k = 0;
    for (int i = 0; i < artistCount; i++) {
        for (int s = 0; s < artists[i].songCount; s++) {
            if (k >= maxSongs) return k;
            strcpy_s(outSongs[k].artist, sizeof(outSongs[k].artist), artists[i].name);
            strcpy_s(outSongs[k].title, sizeof(outSongs[k].title), artists[i].songs[s]);
            k++;
        }
    }
    return k;
}

static int same_song(const Song* a, const Song* b) {
    return strcmp(a->artist, b->artist) == 0 && strcmp(a->title, b->title) == 0;
}

// ---------- shuffle with constraint: each song twice + not in last 5 ----------
int build_shuffled_playlist(const Song songs[], int n, Song playlistOut[], int outCap) {
    int total = 2 * n;
    if (outCap < total) return 0;

    // remaining copies for each unique song (2 copies each)
    int remaining[MAX_SONGS_TOTAL];
    for (int i = 0; i < n; i++) remaining[i] = 2;

    int len = 0;
    while (len < total) {
        int eligible[MAX_SONGS_TOTAL];
        int eCount = 0;

        for (int i = 0; i < n; i++) {
            if (remaining[i] <= 0) continue;

            // check last 5
            int ok = 1;
            int start = (len - 5 > 0) ? (len - 5) : 0;
            for (int j = start; j < len; j++) {
                if (same_song(&playlistOut[j], &songs[i])) { ok = 0; break; }
            }
            if (ok) eligible[eCount++] = i;
        }

        if (eCount == 0) {
            // failed to continue under constraint; signal failure so caller can retry
            return 0;
        }

        int pick = eligible[rand() % eCount];
        playlistOut[len++] = songs[pick];
        remaining[pick]--;
    }

    return total;
}

void print_playlist(const Song playlist[], int len) {
    printf("\nShuffled Playlist:\n");
    for (int i = 0; i < len; i++) {
        printf("%s - %s\n", playlist[i].artist, playlist[i].title);
    }
}

int main(void) {
    srand((unsigned)time(NULL));

    Artist artists[MAX_ARTISTS];
    int artistCount = read_artists(artists, MAX_ARTISTS);

    // sort
    for (int i = 0; i < artistCount; i++) sort_songs_of_artist(&artists[i]);
    sort_artists(artists, artistCount);
    print_sorted(artists, artistCount);

    // shuffle
    Song songs[MAX_SONGS_TOTAL];
    int songCount = flatten_songs(artists, artistCount, songs, MAX_SONGS_TOTAL);

    Song playlist[2 * MAX_SONGS_TOTAL];

    // retry a few times (small n, cheap)
    int ok = 0;
    for (int t = 0; t < 2000 && !ok; t++) {
        int len = build_shuffled_playlist(songs, songCount, playlist, (int)(sizeof(playlist) / sizeof(playlist[0])));
        if (len > 0) { print_playlist(playlist, len); ok = 1; }
    }

    if (!ok) {
        printf("\nCould not build a playlist satisfying the constraint. Try again.\n");
    }

    return 0;
}
