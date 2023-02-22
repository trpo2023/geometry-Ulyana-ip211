#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* file;
    FILE* file1;
    int i, j, l = 0, s, n, g = 200;

    file1 = fopen("C:/Users/79617/Documents/test.txt", "r");

    while (1) {
        s = fgetc(file1);
        if (s == EOF) {
            if (feof(file1) != 0)
                break;
        }
        l++;
    }
    n = l;

    fclose(file1);

    char q[] = "circle";
    char a[n];

    file = fopen("C:/Users/79617/Documents/test.txt", "r");

    fgets(a, n + 1, file);

    for (i = 0; i < 6; i++) {
        if ((a[i] != q[i])) {
            printf("Error at column 0: expected 'circle'\n");
            return 0;
        }
        j = i + 1;
    }

    int k = 0;
    for (i = j + 1; i < n - 1; i++) {
        if (isdigit(a[i]) == 0 && a[i] != '.' && a[i] != ' ' && a[i] != ',') {
            if (a[i] == ',' || a[i] == ' '
                || (a[i] != ',' && a[i + 1] != ' ')) {
                k++;
            }
            printf("Error at column %d: expected '<double>'\n", i);
            return 0;
        }
    }

    for (i = 12; i < n; i++) {
        if (a[i] == '(') {
            printf("Error at column %d: expected ')'\n", i);
            return 0;
        }
        if ((a[i] == ')') && (i != (n - 1))) {
            printf("Error at column %d: unexpected token\n", i);
            return 0;
        }
    }

    for (i = 0; i < l; i++)
        printf("%c", a[i]);

    fclose(file);

    return 0;
}
