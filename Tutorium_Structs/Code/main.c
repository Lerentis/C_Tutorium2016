/*******************************************************
 * Written by Lerentis
 * 
 * This file is part of C Course 2016 - HS-Bochum.
 * 
 *******************************************************/

#include <stdio.h>
#include <string.h>

#define N 15

struct book
{
    char author[20];
    char title[40];
    char release_date[40];
    int pages;
};

void print_book(struct book x){

    printf("Author: \t %s \n"
           "Title: \t \t %s \n"
           "Release Date: \t %s \n"
           "Pages: \t \t %d \n \n",
           x.author,
           x.title,
           x.release_date,
           x.pages );

}


int main(int argc, char *argv[])
{

    struct book library[N];

    for (int var = 0; var < N; ++var)
    {
        strcpy(library[var].author, "Edgar Allan Poe");
        strcpy(library[var].release_date , "19.08.1843");
        strcpy(library[var].title, "The Black Cat");
        library[var].pages = 24;
    }

    for (int var = 0; var < N; ++var) {
        print_book(library[var]);
    }

    int n, result;

    printf("Wie viele buecher wollen Sie eingeben? \t");
    result = scanf("%d", &n);

    if(result != 1){
        printf("%d", result);
        printf("Falsche eingabe");
        return -99;
    }

    struct book library_2[n];

    for (int var = 0; var < n; ++var) {

        char author[20];
        char title[40];
        char release_date[40];
        int pages;

        printf("Name des Authors: \t");
        result = scanf("%s", &author[0]);
        printf("Name des Buches: \t");
        result = scanf("%s", &title[0]);
        printf("Erscheinungsdatum: \t");
        result = scanf("%s", &release_date[0]);
        printf("Anzahl der Seiten: \t");
        result = scanf("%d", &pages);

        strcpy(library_2[var].author, author);
        strcpy(library_2[var].release_date , release_date);
        strcpy(library_2[var].title, title);
        library_2[var].pages = pages;

        }

    for (int var = 0; var < n; ++var) {
        print_book(library_2[var]);
    }

    return 0;
}
