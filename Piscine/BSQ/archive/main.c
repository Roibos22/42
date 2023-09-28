
int main(void)
{
    char *complete_map = read_file_to_memory("example_file");
    char *just_map = read_file_to_memory("example_file");
    int no_rows = count_lines(just_map + 5);
    int no_columns = count_col(just_map + 5);
    //printf("%s", just_map + 5);
    printf("%i\n", no_columns);
    printf("%i\n", no_rows);

    char **map_array = (char **) malloc((no_columns * no_rows * sizeof(char)) + 1);

    char delimiter = '\n';
    char** result = split_string(just_map + 5, delimiter);

    printf("%s\n\n", result[2]);

    for (int i = 0; result[i] != NULL; i++) {
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);

    char *complete_map = read_file_to_memory("example_file");
    char *just_map = read_file_to_memory("example_file");
    int no_rows = count_lines(just_map + 5);
    int no_columns = count_col(just_map + 5);
    //printf("%s", just_map + 5);
    printf("%i\n", no_columns);
    printf("%i\n", no_rows);

    char **map_array = (char **) malloc((no_columns * no_rows * sizeof(char)) + 1);

    char delimiter = '\n';
    char** result = split_string(just_map + 5, delimiter);

    printf("%s\n\n", result[2]);

    for (int i = 0; result[i] != NULL; i++) {
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);

}
