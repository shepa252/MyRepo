#include <cstdio>
#include <cstring>
#include <clocale>
#include <Windows.h>
#include <iostream>

using namespace std;
const int n = 7;

struct disk {
    char title[50];
    char director[50];
    char genre[50];
    int duration;
    int year;
    char company[50];
    float imdb;
};

disk films[n];

void task_1();

void task_2();

void filling_struct() {
    FILE *fp;
    if ((fp = fopen("test.txt", "r")) == nullptr) {
        printf("Cannot open file.\n");
    }

    char line_break;

    for (int i = 0; i < n; i++) {
        fgets((films+i)->title, 50, fp);
        (films+i)->title[strlen((films+i)->title) - 1] = '\0';
        fgets((films+i)->director, 50, fp);
        (films+i)->director[strlen((films+i)->director) - 1] = '\0';
        fgets((films+i)->genre, 50, fp);
        (films+i)->genre[strlen((films+i)->genre) - 1] = '\0';
        fscanf(fp, "%d", &(films+i)->duration);
        fscanf(fp, "%d%c", &(films+i)->year, &line_break);
        fgets((films+i)->company, 50, fp);
        (films+i)->company[strlen((films+i)->company) - 1] = '\0';
        fscanf(fp, "%f%c", &(films+i)->imdb, &line_break);
    };

    fclose(fp);
}


void print() {
    printf("---7 best films---\n\n");

    for (int i = 0; i < n; i++) {
        cout <<"Film title: " << films[i].title << endl;
        cout <<"Director: " << films[i].director << endl;
        cout <<"Film genre: " << films[i].genre << endl;
        cout <<"Duration in min.: " << films[i].duration << endl;
        cout <<"Year of release: " << films[i].year << endl;
        cout <<"Film Company: " << films[i].company << endl;
        cout <<"Rating IMDB: " << films[i].imdb << endl;
        printf("--------------------\n");
    };
}
// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

void task_1() {
    char director[50], first_name[25], last_name[25];
    int max_year = 0, last_film_i;

    printf("Director: ");
    scanf("%s %s", first_name, last_name);

    strcat(first_name, " ");
    strcpy(director, strcat(first_name, last_name));//копирует строку в буфер обмена

    for (int i = 0; i < n; i++) {
        if (strcmp((films+i)->director, director) == 0)
            if ((films+i)->year > max_year) {
                max_year = (films + i)->year;
                last_film_i = i;
            }
    }

    printf("\nFilm title: %s\n", films[last_film_i].title);
    printf("Director: %s\n", films[last_film_i].director);
    printf("Film genre: %s\n", films[last_film_i].genre);
    printf("Duration in min.: %d\n", films[last_film_i].duration);
    printf("Year of release: %d\n", films[last_film_i].year);
    printf("Film Company: %s\n", films[last_film_i].company);
    printf("Rating IMDB: %.1f\n", films[last_film_i].imdb);
    printf("--------------------\n");
}


void task_2() {
    for (int i = 0; i < n; i++) {
        if (strcmp((films+i)->genre, "comedy") == 0 and (films+i)->imdb > 8) {
            printf("Film title: %s\n", films[i].title);
            printf("Director: %s\n", films[i].director);
            printf("Film genre: %s\n", films[i].genre);
            printf("Duration in min.: %d\n", films[i].duration);
            printf("Year of release: %d\n", films[i].year);
            printf("Film Company: %s\n", films[i].company);
            printf("Rating IMDB: %.1f\n", films[i].imdb);
            printf("--------------------\n");
        }
    }
}

bool loop = TRUE;
int main() {
    char task;

    filling_struct();
    print();

    while (loop) {
        puts("\nSelect a task: ");
        scanf("%s",  &task);
        switch (task) {
            case '1':
                task_1();
                break;
            case '2':
                task_2();
                break;
            default:
                loop = FALSE;
        }
    }

    return 0;
}
