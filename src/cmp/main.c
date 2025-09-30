//
// Copyright (C) 2025 —͟͞͞★ ɪᴋ𝘂ᵞο ᴋ𝖎𝘵𝕒 ★ <ayumi.aiko@outlook.com>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
#include <stdio.h>
#include <getopt.h>
#include <stdbool.h>
#include <libgen.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// let's store differing bytes in a str array!
int arr[] = {0};

// program name:
char *programName = NULL;

// never used struct that much, but here i'm using this 
// "class" kinda thing.
struct option longOptions[] = {
    {"help", no_argument, 0, 'h'},
    {"version", no_argument, 0, 'v'},
    {"print-bytes", required_argument, 0, 'b'},
    {0,0,0,0}
};

int stringByteCompare(const char *needle, const char *haystack) {
    size_t endStrIndexOfNeedle = strcspn(needle, "\0");
    size_t endStrIndexOfHaystack = strcspn(haystack, "\0");
    for(int i = 0; i < endStrIndexOfHaystack; i++) if(needle[i] != haystack[i]) return i;
    return -1;
}

int stringByteCompareAndStoreDiffering(const char *needle, const char *haystack, int *byteCount) {
    size_t lenNeedle = strlen(needle);
    size_t lenHaystack = strlen(haystack);
    size_t minLen = (lenNeedle < lenHaystack) ? lenNeedle : lenHaystack;
    for(size_t i = 0; i < minLen; i++) {
        (*byteCount)++;
        if((unsigned char)needle[i] != (unsigned char)haystack[i]) {
            arr[0] = (unsigned char)needle[i];
            arr[1] = (unsigned char)haystack[i];
            return i;
        }
    }
    if(lenNeedle != lenHaystack) {
        (*byteCount)++;
        arr[0] = (lenNeedle > lenHaystack) ? (unsigned char)needle[minLen] : 0;
        arr[1] = (lenHaystack > lenNeedle) ? (unsigned char)haystack[minLen] : 0;
        return (int)minLen;
    }
    return -1;
}

void printHelp(void) {
    printf("Usage: %s [OPTION]... [FILE1] [FILE2]\n", programName);
    printf("Compare two files byte by byte.\n\n");
    printf("  -b, --print-bytes Print differing bytes\n");
    printf("  -h, --help        Display this help and exit\n");
    printf("  -v, --version     Output version information and exit\n");
}

int main(int argc, char *argv[]) {
    int byteCount = 0;
    int diffIndex;
    int opt;
    int longindex = 0;
    bool printBytes = false;
    programName = basename((char *)argv[0]);
    char contentOfOne[1024];
    char contentOfTwo[1024];
    while((opt = getopt_long(argc, argv, "hvb", longOptions, &longindex)) != -1) {
        switch(opt) {
            case 'h':
                printHelp();
                return 0;
            case 'v':
                printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⠓⠶⣤⠀⠀⠀⠀⣠⠶⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠇⠀⢠⡏⠀⠀⢀⡔⠉⠀⢈⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠩⠤⣄⣼⠁⠀⣠⠟⠀⠀⣠⠏⠀⠀⢀⣀⠀⠀⠀⠀⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢀⣀⣀⣀⣀⣀⣀⣀⠀⠀⠀⠁⠀⠀⠣⣤⣀⡼⠃⠀⢀⡴⠋⠈⠳⡄⠀⠀⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣶⣿⡿⠿⠿⠟⠛⠛⠛⠛⠿⠿⣿⣿⣶⣤⣄⠀⠀⠀⠉⠀⢀⡴⠋⠀⠀⣠⠞⠁⠀⠀⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣾⣿⠿⠋⠉⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠻⢿⣿⣶⣄⠀⠀⠳⣄⠀⣠⠞⢁⡠⢶⡄⠀⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⠿⠋⠀⠀⢀⣴⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⢤⡈⠛⢿⣿⣦⡀⠈⠛⢡⠚⠃⠀⠀⢹⡆⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣿⠟⠁⠀⠀⠀⢀⣾⠃⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡆⠀⠀⢻⣦⠀⠙⢿⣿⣦⡀⠈⢶⣀⡴⠞⠋⠀⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⠀⠀⠀⣠⣿⡿⠃⠀⠀⠀⠀⢀⣾⡇⢀⡄⠀⢸⡇⠀⠀⠀⠀⠀⠀⣀⠀⢸⣷⡀⠀⠀⠹⣷⡀⠀⠙⢿⣷⡀⠀⠉⠀⠀⠀⠀⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⠀⠀⣰⣿⡟⠀⠀⠀⠀⠀⠀⣾⣿⠃⣼⡇⠀⢸⡇⠀⠀⠀⠀⠀⠀⣿⠀⢸⣿⣷⡀⠀⢀⣾⣿⡤⠐⠊⢻⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⠀⢠⣿⣿⣼⡇⠀⠀⠀⠀⢠⣿⠉⢠⣿⠧⠀⣸⣇⣠⡄⠀⠀⠀⠀⣿⠠⢸⡟⠹⣿⡍⠉⣿⣿⣧⠀⠀⠀⠻⣿⣶⣄⠀⠀⠀⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⠀⢸⣿⣿⡟⠀⠀⠀⠀⠀⣼⡏⢠⡿⣿⣦⣤⣿⡿⣿⡇⠀⠀⠀⢸⡿⠻⣿⣧⣤⣼⣿⡄⢸⡿⣿⡇⠀⠀⢠⣌⠛⢿⣿⣶⣤⣤⣄⡀\n");
                printf("⠀⠀⠀⣀⣤⣿⣿⠟⣀⠀⠀⠀⠀⠀⣿⢃⣿⠇⢿⣯⣿⣿⣇⣿⠁⠀⠀⠀⣾⡇⢸⣿⠃⠉⠁⠸⣿⣼⡇⢻⡇⠀⠀⠀⢿⣷⣶⣬⣭⣿⣿⣿⠇\n");
                printf("⣾⣿⣿⣿⣿⣻⣥⣾⡇⠀⠀⠀⠀⠀⣿⣿⠇⠀⠘⠿⠋⠻⠿⠿⠶⠶⠾⠿⠿⠍⢛⣧⣰⠶⢀⣀⣼⣿⣴⡸⣿⠀⠀⠀⠸⣿⣿⣿⠉⠛⠉⠀⠀\n");
                printf("⠘⠛⠿⠿⢿⣿⠉⣿⠁⠀⠀⠀⠀⢀⣿⡿⣶⣶⣶⣤⣤⣤⣀⣀⠀⠀⠀⠀⠀⠀⢀⣭⣶⣿⡿⠟⠋⠉⠀⠀⣿⠀⡀⡀⠀⣿⣿⣿⡆⠀⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⣼⣿⠀⣿⠀⠀⠸⠀⠀⠸⣿⠇⠀⠀⣈⣩⣭⣿⡿⠟⠃⠀⠀⠀⠀⠀⠙⠛⠛⠛⠛⠻⠿⠷⠆⠀⣯⠀⠇⡇⠀⣿⡏⣿⣧⠀⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⢿⣿⡀⣿⡆⠀⠀⠀⠀⠀⣿⠰⠿⠿⠛⠋⠉⠀⠀⢀⣴⣶⣶⣶⣶⣶⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣧⠀⠀⠀⣿⡇⣿⣿⠀⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⢸⣿⡇⢻⣇⠀⠘⣰⡀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⢸⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣿⠀⠀⠀⣿⣧⣿⡿⠀⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⠈⣿⣧⢸⣿⡀⠀⡿⣧⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⣿⡄⠀⠀⠀⣼⡇⠀⠀⠀⠀⠀⠀⢀⣤⣾⡟⢡⣶⠀⢠⣿⣿⣿⠃⠀⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⠀⠹⣿⣿⣿⣷⠀⠇⢹⣷⡸⣿⣶⣦⣄⣀⡀⠀⠀⠀⣿⡇⠀⠀⢠⣿⠁⣀⣀⣠⣤⣶⣾⡿⢿⣿⡇⣼⣿⢀⣿⣿⠿⠏⠀⠀⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⠀⠀⠈⠛⠛⣿⣷⣴⠀⢹⣿⣿⣿⡟⠿⠿⣿⣿⣿⣿⣾⣷⣶⣿⣿⣿⣿⡿⠿⠟⠛⠋⠉⠀⢸⣿⣿⣿⣿⣾⣿⠃⠀⠀⠀⠀⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣿⣦⣘⣿⡿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠛⠛⠻⠿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠻⣿⣿⣿⠈⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\n");
                printf("                       kawaiiiii~\n");
                printf("%s 1.0\n", basename((char *)argv[0]));
                printf("Copyright (C) 2025 ぼっち\n");
                printf("License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\n");
                printf("This is free software: you are free to change and redistribute it.\n");
                printf("There is NO WARRANTY, to the extent permitted by law.\n\n");
                printf("Written by —͟͞͞★ ɪᴋ𝘂ᵞο ᴋ𝖎𝘵𝕒 ★\n");
                return 0;
            case 'b':
                printBytes = true;
            break;
            default:
                return 1;
        }
    }
    if(optind <= 2) {
        printHelp();
        return 1;
    }
    FILE *firstFile = fopen(argv[optind], "r");
    FILE *secondFile = fopen(argv[optind + 1], "r");
    if(!firstFile) {
        printf("Failed to open %s: No such file or directory\n", argv[optind]);
        return -1;
    }
    if(!secondFile) {
        fclose(firstFile);
        printf("Failed to open %s: No such file or directory\n", argv[optind + 1]);
        return -1;
    }
    contentOfOne[fread(contentOfOne, 1, sizeof(contentOfOne)-1, firstFile)] = '\0';
    contentOfTwo[fread(contentOfTwo, 1, sizeof(contentOfTwo)-1, secondFile)] = '\0';
    fclose(firstFile);
    fclose(secondFile);
    // adding 1 to diffIndex gives output that is equal to actual cmp.
    if(printBytes) {
        diffIndex = stringByteCompareAndStoreDiffering(contentOfOne, contentOfTwo, &byteCount) + 1;
        if(diffIndex == 0) return 0;
        int lineNum = 1;
        for(int i = 0; i < diffIndex - 1; i++) if(contentOfOne[i] == '\n') lineNum++;
        char buf0[5], buf1[5];
        if((unsigned char)arr[0] >= 32 && (unsigned char)arr[0] <= 126) snprintf(buf0, sizeof(buf0), "%c", arr[0]);
        else snprintf(buf0, sizeof(buf0), "%03o", (unsigned char)arr[0]);
        if((unsigned char)arr[1] >= 32 && (unsigned char)arr[1] <= 126) snprintf(buf1, sizeof(buf1), "%c", arr[1]);
        else snprintf(buf1, sizeof(buf1), "%03o", (unsigned char)arr[1]);
        printf("%s %s differ: byte %d, line %d is %s %s\n", argv[optind], argv[optind + 1], diffIndex, lineNum, buf0, buf1);
    }
    else {
        diffIndex = stringByteCompare(contentOfOne, contentOfTwo) + 1;
        if(diffIndex == -1) return 0;
        printf("%s %s differ: byte %d\n", argv[optind], argv[optind + 1], diffIndex);
    }
    return 1;
}