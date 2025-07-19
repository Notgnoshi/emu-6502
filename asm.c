#include "config.h"

#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Global does actually make sense for a flag like this?
// NOLINTNEXTLINE(cppcoreguidelines-avoid-non-const-global-variables)
bool g_emu_verbose = false;

typedef struct emu_cli_args_t
{
    bool removeme;
} emu_cli_args_t;

void emu_print_usage_statement(void)
{
    printf("A MOS 6502 assembler\n");
    printf("Usage: asm [--help] [--version]\n");
    printf("\n");
    printf("Aguments:\n");
    printf("\n");
    printf("Options:\n");
    printf("  -h, --help        Print help\n");
    printf("  -V, --version     Print version\n");
    printf("  -v, --verbose     Log more detail\n");
}

emu_cli_args_t emu_parse_args(int argc, char* const* argv)
{
    emu_cli_args_t args = {0};

    struct option options[] = {
        {"help", no_argument, NULL, 'h'},
        {"version", no_argument, NULL, 'V'},
        {"verbose", no_argument, NULL, 'v'},
        {NULL, 0, NULL, 0},
    };

    while (true)
    {
        int option_index = 0;

        int retval = getopt_long(argc, argv, "hVv", options, &option_index);
        if (retval == -1)
        {
            break;
        }

        switch (retval)
        {
        case 'h':
            emu_print_usage_statement();
            exit(EXIT_SUCCESS);
            break;
        case 'V':
            printf(PACKAGE_STRING "\n");
            break;
        case 'v':
            g_emu_verbose = true;
            break;

        // Don't print the full usage statement if we fail to parse an argument
        case '?':
            exit(EXIT_FAILURE);
            break;
        default:
            fprintf(stderr, "Unhandled argument: '%s'\n", argv[optind - 1]);
            exit(EXIT_FAILURE);
            break;
        }
    }

    return args;
}

int main(int argc, char* const argv[])
{
    const emu_cli_args_t args = emu_parse_args(argc, argv);  // Exits on failure
    (void)args;

    return 0;
}
