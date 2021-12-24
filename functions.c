//
// Created by Влад on 19.12.2021.
//

#include "functions.h"

void clrscr()
{
    system("cls||clear");
}

double funct(float x)
{
    return cos(pow(x, 3)-4*pow(x, 2));
}

void save_txt(double group, double brigade, double start, double end, double dots, double step) {
    FILE *myfile_txt;
    int i;
    double delta;
    char name_txt[] = ("../result.txt");
    myfile_txt = fopen(name_txt, "w");
    if (dots > 0) {
        fprintf(myfile_txt, "Группа РС-п%.0lf\n", group);
        fprintf(myfile_txt, "Варіант №%.0lf\n", brigade);
        fprintf(myfile_txt, "x1=%.0lf  x2=%.0lf количество строк=%.0f\n", start, end, dots);
        head_txt(myfile_txt);
        while (start < end && i <= dots) {
            delta = (end - start) / (dots - 1);
            fprintf(myfile_txt, "|");
            fprintf(myfile_txt, "%d", i);
            fprintf(myfile_txt, "|");
            fprintf(myfile_txt, "%.2lf", start);
            start += delta;
            start++;
            fprintf(myfile_txt, "|");
            fprintf(myfile_txt, "%lf", funct(start));
            fprintf(myfile_txt, "|\n");
            i++;
        }
        fprintf(myfile_txt,"+---------+---------+---------+\n");
    }
    else {
        fprintf(myfile_txt, "Группа РС-п%.0lf\n", group);
        fprintf(myfile_txt, "Варіант №%.0lf\n", brigade);
        fprintf(myfile_txt, "x1=%.0lf  x2=%.0lf Дельта=%.2lf\n", start, end, step);
        head_txt(myfile_txt);
        while (start <= end) {
            fprintf(myfile_txt, "|");
            fprintf(myfile_txt, "%d", i);
            fprintf(myfile_txt, "|");
            fprintf(myfile_txt, "%.2lf", start);
            start += step;
            start++;
            fprintf(myfile_txt, "|");
            fprintf(myfile_txt, "%f", funct(start));
            fprintf(myfile_txt, "|\n");
            i++;
        }
        fprintf(myfile_txt,"+---------+---------+---------+\n");
        fclose(myfile_txt);
    }
}

void save_bin(double group, double brigade, double start, double end, double dots, double step) {
    int i;
    double delta;
    FILE *myfile_bin;
    char name_bin[] = ("../result.bin");
    if (dots > 0) {
        myfile_bin = fopen(name_bin, "w");
        printf("Группа РС-п%.0lf\n", group);
        printf("Варіант №%.0lf\n", brigade);
        fprintf(myfile_bin, "x1=%.0lf  x2=%.0lf количество строк=%.0f\n", start, end, dots);
        head_bin(myfile_bin);
        while (start < end && i <= dots) {
            delta = (end - start) / (dots - 1);
            fprintf(myfile_bin, "|");
            fprintf(myfile_bin, "\t%d\t", i);
            fprintf(myfile_bin, "|");
            fprintf(myfile_bin, "\t%.2lf\t", start);
            start += delta;
            start++;
            fprintf(myfile_bin, "|");
            fprintf(myfile_bin, "\t%lf\t", funct(start));
            fprintf(myfile_bin, "|\n");
            i++;
        }
        fprintf(myfile_bin, "+-------+-----------+---------------+\n");
        fclose(myfile_bin);
    }
    else {
        myfile_bin = fopen(name_bin, "w");
        fprintf(myfile_bin, "Группа РС-п%.0lf\n", group);
        fprintf(myfile_bin, "Варіант №%.0lf\n", brigade);
        fprintf(myfile_bin, "x1=%.0lf  x2=%.0lf Дельта=%.2lf\n", start, end, step);
        head_bin(myfile_bin);
        while (start <= end) {
            fprintf(myfile_bin, "|");
            fprintf(myfile_bin, "\t%d\t", i);
            fprintf(myfile_bin, "|");
            fprintf(myfile_bin, "\t%.2lf\t", start);
            start += step;
            start++;
            fprintf(myfile_bin, "|");
            fprintf(myfile_bin, "\t%f\t", funct(start));
            fprintf(myfile_bin, "|\n");
            i++;
        }
        fprintf(myfile_bin, "+-------+-----------+---------------+\n");
        fclose(myfile_bin);
    }
}

void output () {
    FILE *myfile;
    int i;
    double group, brigade, start, end, dots, step, delta;
    char massive[6];

    myfile = fopen("../input.dat", "r");
    fscanf(myfile, "%lf%lf%lf%lf%lf%lf", &group, &brigade, &start, &end, &dots, &step);
    char *estr = fgets(massive, sizeof(massive), myfile);

    // Запись bin и TXT файла
        save_bin(group, brigade, start, end, dots, step);
        save_txt(group, brigade, start, end, dots, step);
    fclose(myfile);
    if (dots > 0) {
        printf("x1=%.0lf  x2=%.0lf количество строк=%.0lf\n", start, end, dots);
        head();
        while (start < end && i <= dots) {
            delta = (end - start) / (dots - 1);
            printf("|");
            printf("\t%d\t", i);
            printf("|");
            printf("\t%.2lf2\t", start);
            start += delta;
            start++;
            printf("|");
            printf("\t%f\t", funct(start));
            printf("|\n");
            i++;
        }
        printf("+-------+-----------+---------------+\n");
    }
    else {
        printf("\n");
        printf("Группа РС-п%.0lf\n", group);
        printf("Варіант №%.0lf\n", brigade);
        printf("x1=%.0lf  x2=%.0lf Дельта=%.2lf\n", start, end, step);
        head();
        while (start <= end) {
            printf("|");
            printf("\t%d\t", i);
            printf("|");
            printf("\t%.2lf2"
                   "\t", start);
            start += step;
            start++;
            printf("|");
            printf("\t%f\t", funct(start));
            printf("|\n");
            i++;
        }
        printf("+-------+-----------+---------------+\n");
    }
}