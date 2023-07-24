#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <vlc/vlc.h>

typedef struct
{
    libvlc_instance_t *instance;
    libvlc_media_player_t *mediaPlayer;
    libvlc_media_t *media;
} MusicPlayer;

MusicPlayer *NewMusicPlayer(int argc, const char *const *argv, int song)
{
    const char *music[3] = {"file:///../music/1.mp3",
                            "file:///../music/2.mp3",
                            "file:///../music/3.mp3"};
    MusicPlayer *player = (MusicPlayer *) malloc(sizeof(MusicPlayer));

    player->instance = libvlc_new(argc, argv);
    player->mediaPlayer = libvlc_media_player_new(player->instance);
    player->media = libvlc_media_new_location(player->instance, music[song]);

    return player;
}

void *playMusic(void *data)
{
    MusicPlayer *R = (MusicPlayer *) data;
    libvlc_media_player_set_media(R->mediaPlayer, R->media);
    //    libvlc_media_parse_with_options(R->media, 0, 0);
    libvlc_media_player_play(R->mediaPlayer);
    while (1) {
    }
    return NULL;
}

void MusicPlayerFree(MusicPlayer *R)
{
    libvlc_media_release(R->media);
    R->media = NULL;
    libvlc_media_player_release(R->mediaPlayer);
    R->mediaPlayer = NULL;
    libvlc_release(R->instance);
    R->instance = NULL;
    free(R);
    R = NULL;
}

void *mainMenu(void *data)
{
    MusicPlayer *R = (MusicPlayer *) data;
    char answer = 'n';
    while (answer == 'n') {
        setbuf(stdin, NULL);
        printf("Do you want to quit? [y/n] ");
        scanf("%c", &answer);
        if (answer == 'y') {
            MusicPlayerFree(R);
            exit(EXIT_SUCCESS);
        }
    }

    return NULL;
}

int main(int argc, const char *const *argv)
{
    int song = 0;
    printf("Choose music:\n");
    printf("1. 1.mp3:\n");
    printf("2. 2.mp3:\n");
    printf("3. 3.mp3:\n");
    printf("-> ");
    scanf("%d", &song);
    MusicPlayer *R = NewMusicPlayer(argc, argv, song - 1);
    pthread_t thread1;
    pthread_t thread2;
    pthread_create(&thread1, NULL, &playMusic, R);
    pthread_create(&thread2, NULL, &mainMenu, R);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return EXIT_SUCCESS;
}
