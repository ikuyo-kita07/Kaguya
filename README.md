![kaguya-banner](https://github.com/ikuyo-kita07/banners/blob/main/kaguya.banner.png?raw=true)

# Kaguya
A small repository which aims to write the CLI utilities using C. 

## Overview

**Kaguya** is a small project that tries to write essential UNIX utilities, starting with [cat](https://www.gnu.org/software/coreutils/cat).
The goal is to:

* Practice low-level C programming more
* Learn about file descriptors, standard I/O, and system calls
* Recreate the behavior of GNU tools from scratch
* Small reminder, some utilities don't have some feature because i'm either lazy to implement or just can't implement it because i lack the skill.

---

## To Build:

Clone the repo:

```bash
git clone https://github.com/ikuyo-kita07/Kaguya.git
cd Kaguya
```

Build with **make**:

```bash
make <target>
```

Available targets:

* `cat` → builds the `cat` utility
* `echo` → builds the `echo` utility
* `cmp` → builds the `cmp` utility
* `ls` → builds the `ls` utility

## Roadmap
* [x] Implemented `cat`, `echo`, `cmp` and `ls`
* [ ] Add more utilities (`head`, `tail`, …)

## Contributors
- [Homura](https://github.com/HomuHomu833)
##### Thanks to everyone who helped me on this project.