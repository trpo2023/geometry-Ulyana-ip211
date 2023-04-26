void check_str(char* a, char* b, int* open_bracket, int* error);

void checkcheck_find_close_bracket(char* a, int l, int* close_bracket);

void check_first_num(
        char* a, int* open_bracket, int* error, int* first_num_elm);

void check_second_num(
        char* a, int* first_num_elm, int* second_num_elm, int* error);

void check_last_num(
        char* a,
        int* second_num_elm,
        int* close_bracket,
        int* error,
        int* last_num_elm);

void check_close_bracket(
        char* a, int l, int* last_num_elm, int* error, int* close_bracket);

void check_unexp_token(char* a, int l, int* close_bracket, int* error);