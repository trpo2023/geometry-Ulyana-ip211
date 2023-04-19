#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libgeometry/check.h>

int main()
{
    FILE* file1;
    FILE* file;

    file1 = fopen("test.txt", "r");
    if (file1 != 0)
        printf("Error: can't open file, check name of file \n");

    int ind_open_bracket = 0, ind_close_bracket = 0, ind_last_num_elm = 0,
        ind_first_num_elm = 0, ind_second_num_elm = 0;
    int l = 0, c = 0, e = 0, error = 0;

    while (1) {
        e = fgetc(file1);
        if (e == EOF) {
            if (feof(file1) != 0) {
                break;
            }
        }
        c++;
    }
    l = c;
    fclose(file1);

    char a[l], b[6] = "circle";
    file = fopen("test.txt", "r");
    if (file != 0)
        printf("Error: can't open file, check name of file \n");

    while (fgets(a, l + 1, file)) {
        printf("%s", a);

        check_str(a, b, &ind_open_bracket, &error);

        check_open_bracket(a, l, &ind_close_bracket);

        check_first_num(a, &ind_open_bracket, &error, &ind_first_num_elm);

        check_second_num(a, &ind_first_num_elm, &ind_second_num_elm, &error);

        check_last_num(
                a,
                &ind_second_num_elm,
                &ind_close_bracket,
                &error,
                &ind_last_num_elm);

        check_close_bracket(
                a, l, &ind_last_num_elm, &error, &ind_close_bracket);

        check_unexp_token(a, l, &ind_close_bracket, &error);

        if (error == 0) {
            printf("No Errors\n");
        }

        error = 0;
    }
    return 0;
}
