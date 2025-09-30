#
# Copyright (C) 2025 —͟͞͞★ ɪᴋ𝘂ᵞο ᴋ𝖎𝘵𝕒 ★ <ayumi.aiko@outlook.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

# common vars:
CC = clang
CFLAGS = -O3 -static
COMPILER_OUTPUT = ./local_build/compiler-output

# cat target vars:
CAT_MAIN = ./src/cat/main.c
CAT_OUTPUT = ./local_build/binaries/cat

# echo target vars:
ECHO_MAIN = ./src/echo/main.c
ECHO_OUTPUT = ./local_build/binaries/echo

# cmp target vars:
CMP_MAIN = ./src/cmp/main.c
CMP_OUTPUT = ./local_build/binaries/cmp

# dynamic targets, builds everything.
all: cat echo cmp

# targets:
cat:
	@echo "\e[0;33mmake: Info: Building cat..\e[0;37m"
	@$(CC) $(CFLAGS) $(CAT_MAIN) -o $(CAT_OUTPUT) >$(COMPILER_OUTPUT) 2>&1 && \
	echo "\e[0;33mmake: Info: Build finished successfully\e[0;37m" || echo "\e[0;31mmake: Error: Compilation failed. Check $(COMPILER_OUTPUT) for details.\e[0;37m";

echo:
	@echo "\e[0;33mmake: Info: Building echo..\e[0;37m"
	@$(CC) $(CFLAGS) $(ECHO_MAIN) -o $(ECHO_OUTPUT) >$(COMPILER_OUTPUT) 2>&1 && \
	echo "\e[0;33mmake: Info: Build finished successfully\e[0;37m" || echo "\e[0;31mmake: Error: Compilation failed. Check $(COMPILER_OUTPUT) for details.\e[0;37m";

cmp:
	@echo "\e[0;33mmake: Info: Building cmp..\e[0;37m"
	@$(CC) $(CFLAGS) $(CMP_MAIN) -o $(CMP_OUTPUT) >$(COMPILER_OUTPUT) 2>&1 && \
	echo "\e[0;33mmake: Info: Build finished successfully\e[0;37m" || echo "\e[0;31mmake: Error: Compilation failed. Check $(COMPILER_OUTPUT) for details.\e[0;37m";

clean:
	@rm -f $(CAT_OUTPUT) $(ECHO_OUTPUT) $(COMPILER_OUTPUT) $(CMP_OUTPUT)

.PHONY: all cat clean echo cmp