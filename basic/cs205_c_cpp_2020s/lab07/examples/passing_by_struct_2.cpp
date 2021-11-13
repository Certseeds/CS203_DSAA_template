//
// Created by jyh on 2019/10/18.
//

#include <stdio.h>
#include <string.h>

struct student {
    int id;
    char name[20];
    float score;
};

void PrintStudent(struct student *record);

int main() {
    struct student record;

    record.id = 1;
    strcpy(record.name, "Raju");
    record.score = 86.5;

    PrintStudent(&record);
    return 0;
}

void PrintStudent(struct student *record) {
    printf(" Id is: %d \n", record->id);
    printf(" Name is: %s \n", record->name);
    printf(" Score is: %f \n", record->score);
}