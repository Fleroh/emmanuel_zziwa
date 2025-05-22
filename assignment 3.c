#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[100];
    char author[100];
    float price;
};

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <title> <author> <price>\n", argv[0]);
        return 1;
    }

    struct Book b;
    strncpy(b.title, argv[1], sizeof(b.title));
    strncpy(b.author, argv[2], sizeof(b.author));
    b.price = atof(argv[3]);

    FILE *fptr = fopen("book3.txt", "w");
    if (!fptr) return 1;
    fprintf(fptr, "%s\n%s\n%.2f\n", b.title, b.author, b.price);
    fclose(fptr);

    struct Book rb;
    fptr = fopen("book3.txt", "r");
    fgets(rb.title, sizeof(rb.title), fptr);
    fgets(rb.author, sizeof(rb.author), fptr);
    fscanf(fptr, "%f", &rb.price);
    fclose(fptr);

    printf("\nTitle: %sAuthor: %sPrice: %.2f\n", rb.title, rb.author, rb.price);
    return 0;
}
