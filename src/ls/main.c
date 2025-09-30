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
#include <string.h>
#include <dirent.h>

int main(int argc, const char *argv[]) {
    struct dirent *entry;
    if(argc <= 1) {
        DIR *dir = opendir(".");
        if(!dir) return 1;
        while((entry = readdir(dir))) {
            if((strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)) continue;
            printf("%s\n", entry->d_name);
        }
    }
    else {
        for(int i = 0; i < argc; i++) {
            DIR *dir = opendir(argv[i]);
            if(!dir) continue;
            while((entry = readdir(dir))) {
                if((strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)) continue;
                printf("%s\n", entry->d_name);
            }
            closedir(dir);
        }
    }
    return 0;
}