//
// Created by Влад on 19.12.2021.
//

#include "text.h"

int head_bin (FILE *myfile_bin) {
    fprintf(myfile_bin, "*************************************\n");
    fprintf(myfile_bin, "*\tN\t*\tX\t\t*\t\tF(X)\t*\n");
    fprintf(myfile_bin, "*************************************\n");
    fprintf(myfile_bin, "+-------+-----------+---------------+\n");
}

int head_txt (FILE *myfile_txt) {
    fprintf(myfile_txt, "**********\n");
    fprintf(myfile_txt, "*N*X*F(X)*\n");
    fprintf(myfile_txt, "**********\n");
    fprintf(myfile_txt, "+--------+\n");
}

int head()
{
    printf("*************************************\n");
    printf("*\tN\t*\tX\t\t*\tF(X)\t\t*\n");
    printf("*************************************\n");
    printf("+-------+-----------+---------------+\n");
}

void create () {
    FILE *myfile;
    clrscr();
    int i;
    double ar;
    myfile = fopen("../input.dat", "w");
    for (i=0; i < 6; i++) {
        printf("\nВведите число №%d\t", i);
        scanf("%lf", &ar);
        fprintf(myfile, "%.2lf\n", ar);
    }
    fclose(myfile);
    output();
}

void file_exist () {
    clrscr();
    unsigned int choice;
    printf("\nФайл cуществует. Пересоздать?");
    printf("\n1 - Да \t 2 - Нет\n");
    scanf("%u", &choice);
    switch (choice) {
        case 1:
            create();
            break;
        case 2:
            output();
            break;
    }
}
void file_not_exist () {
    clrscr();
    unsigned int choice;
    printf("\nФайл не найден. Создать?");
    printf("\n1 - Да \t 2 - Нет\n");
    scanf("%u", &choice);
    switch (choice) {
        case 1:
            create();
            break;
        case 2:
            printf("Выход");
            system("pause");
            break;
    }
}

void check () {
    FILE *myfile;
    myfile = fopen("../input.dat", "r");
    if (!myfile) {
        file_not_exist();
    }
    else {
        file_exist ();
    }
}
