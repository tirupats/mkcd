#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <getopt.h>
#include <ctype.h>

void print_usage(char *program_name) {
    fprintf(stderr, "Usage: %s [-p] [-m mode] [-v|--verbose] directory_path\n", program_name);
}

int is_valid_path(const char *path) {
    if (strlen(path) == 0) {
        return 0;
    }
    while (*path) {
        if (!isalnum(*path) && *path != '/' && *path != '-' && *path != '_' && *path != '.') {
            return 0;
        }
        path++;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    int result;
    mode_t mode = 0777;
    int make_parents = 0;
    int verbose = 0;

    int opt;
    while ((opt = getopt(argc, argv, "pm:v")) != -1) {
        switch (opt) {
            case 'p':
                make_parents = 1;
                break;
            case 'm':
                mode = strtol(optarg, NULL, 8);
                if (mode == 0 && errno != 0) {
                    perror("Invalid mode");
                    exit(EXIT_FAILURE);
                }
                break;
            case 'v':
                verbose = 1;
                break;
            default:
                print_usage(argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    argc -= optind;
    argv += optind;

    if (argc != 1) {
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *dir_path = argv[0];

    if (!is_valid_path(dir_path)) {
        fprintf(stderr, "Invalid directory path: '%s'\n", dir_path);
        exit(EXIT_FAILURE);
    }

    if (verbose) {
        printf("Creating directory: %s\n", dir_path);
        if (make_parents) {
            printf("Creating parent directories if needed.\n");
        }
        printf("Setting permissions: %o\n", mode);
    }

    result = mkdir(dir_path, mode);
    if (result != 0) {
        if (errno == EEXIST) {
            fprintf(stderr, "Directory '%s' already exists.\n", dir_path);
        } else {
            fprintf(stderr, "Failed to create directory '%s': %s\n", dir_path, strerror(errno));
        }
        exit(EXIT_FAILURE);
    }

    result = chdir(dir_path);
    if (result != 0) {
        fprintf(stderr, "Failed to change directory to '%s': %s\n", dir_path, strerror(errno));
        exit(EXIT_FAILURE);
    }

    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd");
        exit(EXIT_FAILURE);
    }

    if (verbose) {
        printf("Directory '%s' created and changed successfully.\n", dir_path);
        printf("Current directory: %s\n", cwd);
    } else {
        printf("Directory '%s' created and changed successfully.\n", dir_path);
    }

    return 0;
}
