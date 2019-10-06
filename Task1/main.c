#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 63
#define BUFF_SIZE 10

typedef struct {
    char title[SIZE + 1];
    char author[SIZE + 1];
    char singer[SIZE + 1];
    int duration;
} Single;

void print_single(const Single *single) {
    if (single == NULL) {
        return;
    }
    if (*single->title != '\0')
        printf("title: %s\n", single->title);
    else
        printf("title: unknown\n");
    if (*single->author != '\0')
            printf("author: %s\n", single->author);
    else
        printf("author: unknown\n");
    if (*single->singer != '\0')
            printf("singer: %s\n", single->singer);
    else
        printf("author: unknown");
    printf("duration: %i\n", single->duration);
}

int author_is_singer(const Single *single) {
    if (single != NULL) {
        if (!strncmp(single->author, single->singer, SIZE) && strncmp(single->title, "", 1)) {
            return 1;
        } else
            return 0;
    } else
        return 0;
}

#ifndef TESTING
int main() {
    char buffer[BUFF_SIZE] = "%";
    sprintf(buffer + 1, "%i", SIZE);
    strncat(buffer, "s", 2);
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        Single single;
        scanf(buffer, &single.title);
        scanf(buffer, &single.author);
        scanf(buffer, &single.singer);
        scanf("%u", &single.duration);
        if (author_is_singer(&single))
            print_single(&single);
    }
    return  0;
}
#endif