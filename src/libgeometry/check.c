#include "check.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_str(char* a, char* b, int* ind_open_bracket, int* error)
{
    for (int i = 0; i < 7; i++) {
        if (a[i] != b[i] && i < 6) {
            printf("Error at column %d: expected 'circle'\n", i);
            *error = 1;
            break;
            ;
        }
        *ind_open_bracket = i;
    }
}

void check_open_bracket(char* a, int l, int* ind_close_bracket)
{
    for (int i = 0; i < l; i++) {
        if (a[i] == ')') {
            *ind_close_bracket = i;
        } else {
            *ind_close_bracket = l - 1;
        }
    }
}

void check_first_num(
        char* a, int* ind_open_bracket, int* error, int* ind_first_num_elm)
{
    for (int i = *ind_open_bracket + 1; a[i] != ' '; i++) {
        if (*error == 0) {
            if (a[i] == ',') {
                *error = 1;
                printf("Error at column %d: expected '<space>' and "
                       "'<double>'\n",
                       i);
                break;
            }
            if (isdigit(a[i]) == 0 && a[i] != '.') {
                *error = 1;
                printf("Error at column %d: expected '<double>'\n", i);
                break;
            }
            *ind_first_num_elm = i;
        } else {
            break;
        }
    }
}

void check_second_num(
        char* a, int* ind_first_num_elm, int* ind_second_num_elm, int* error)
{
    for (int i = *ind_first_num_elm + 2; a[i] != ','; i++) {
        if (*error == 0) {
            if (a[i] == ')') {
                *error = 1;
                printf("Error at column %d: expected ',' and '<double>'\n", i);
                break;
            }
            if (isdigit(a[i]) == 0 && a[i] != '.') {
                *error = 1;
                printf("Error at column %d: expected '<double>'\n", i);
                break;
            }
            *ind_second_num_elm = i;
        } else {
            break;
        }
    }
}

void check_last_num(
        char* a,
        int* ind_second_num_elm,
        int* ind_close_bracket,
        int* error,
        int* ind_last_num_elm)
{
    for (int i = *ind_second_num_elm + 3; i < *ind_close_bracket; i++) {
        if (*error == 0) {
            if ((isdigit(a[i]) == 0 && a[i] != '.') || a[i] == '0') {
                if (a[i] == ')' || a[i] == '(' || a[i] == ' ') {
                    break;
                }
                *error = 1;
                printf("Error at column %d: expected '<double>'\n", i);
                break;
            }
            *ind_last_num_elm = i;
        } else {
            break;
        }
    }
}

void check_close_bracket(
        char* a,
        int l,
        int* ind_last_num_elm,
        int* error,
        int* ind_close_bracket)
{
    for (int i = *ind_last_num_elm + 1; i < l; i++) {
        if (*error == 0) {
            if (a[i] != ')') {
                *error = 1;
                printf("Error at column %d: expected ')'\n", i);
                break;
            } else {
                *ind_close_bracket = i;
                break;
            }
        } else {
            break;
        }
    }
}

void check_unexp_token(char* a, int l, int* ind_close_bracket, int* error)
{
    for (int i = *ind_close_bracket + 1; i < l; i++) {
        if (*error == 0) {
            if (a[i] == '\n') {
                break;
            }

            if (a[i] != ' ') {
                *error = 1;
                printf("Error at column %d: unexpected token\n", i);
                break;
            }
        } else {
            break;
        }
    }
}