#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 64
#define FORMAT_SIZE 10

typedef struct {
    char title[SIZE];
    char author[SIZE];
    char singer[SIZE];
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
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char c[2];
        fgets(c, 2, stdin);
        Single *single = (Single *)malloc(sizeof(Single));
        //Single single;
        fgets(single->title, SIZE, stdin);
        fgets(single->author, SIZE, stdin);
        fgets(single->singer, SIZE, stdin);
        scanf("%u", &single->duration);
        if (author_is_singer(single))
            print_single(single);
        free(single);
    }
    return  0;
}
#endif