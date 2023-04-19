void check_str(char* a, char* b, int* ind_open_bracket, int* error);

void check_open_bracket(char* a, int l, int* ind_close_bracket);

void check_first_num(
        char* a, int* ind_open_bracket, int* error, int* ind_first_num_elm);

void check_second_num(
        char* a, int* ind_first_num_elm, int* ind_second_num_elm, int* error);

void check_last_num(
        char* a,
        int* ind_second_num_elm,
        int* ind_close_bracket,
        int* error,
        int* ind_last_num_elm);

void check_close_bracket(
        char* a,
        int l,
        int* ind_last_num_elm,
        int* error,
        int* ind_close_bracket);

void check_unexp_token(char* a, int l, int* ind_close_bracket, int* error);