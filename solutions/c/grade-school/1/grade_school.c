#include "grade_school.h"

int init_roster(roster_t *roster)
{
    roster->count = 0;
    for (size_t i = 0; i < MAX_STUDENTS; i++)
    {

        roster->students[i].grade = 0;
        roster->students[i].name[0] = '\0';
    }
    return 1;
}

int add_student(roster_t *roster, char name[], uint8_t grade)
{
    size_t iter;
    size_t is_error;

    iter = 0;
    is_error = 0;

    if (roster->count >= MAX_STUDENTS)
        is_error = 1;
    while ((iter < roster->count) && !is_error)
    {
        is_error = (strncmp(roster->students[iter].name, name, MAX_NAME_LENGTH) == 0) ? 1 : 0;
        iter++;
    }
    if (!is_error)
    {
        iter = 0;
        while ((iter < roster->count) &&(roster->students[iter].grade < grade))
            iter++;
        if (roster->students[iter].grade == grade)
            while (roster->students[iter].grade == grade && strcmp(roster->students[iter].name, name) < 0)
                iter++;
        for (size_t i = roster->count; i > iter; i--)
        {
            roster->students[i].grade = roster->students[i - 1].grade;
            strncpy(roster->students[i].name, roster->students[i - 1].name, MAX_NAME_LENGTH);
        }
        strncpy(roster->students[iter].name, name, MAX_NAME_LENGTH);
        roster->students[iter].grade = grade;
        roster->count++;

    }
    return !is_error;
}

roster_t get_grade(roster_t *roster, uint8_t grade)
{
    roster_t res;

    init_roster(&res);
    for (size_t i = 0; i < roster->count; i++)
    {
        if (roster->students[i].grade == grade)
            add_student(&res, roster->students[i].name,
                        roster->students[i].grade);
    }
    return res;
}
