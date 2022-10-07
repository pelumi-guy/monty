# Stacks, Queues - LIFO, FIFO

<p align="center"><img src="monty-pun.gif" /></p>

## Monty
An ALX Software Engineering Programme project. Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes file.  

### Requirements

- Ubuntu 14.04 LTS
- all `.c` files pass [`Betty`](https://github.com/holbertonschool/Betty) style: [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)
- maximum of one global variable
- no more than 5 functions per file
- prototypes of all functions are included in header file called `monty.h`
- all header files are include guarded
- allowed to use standard library

### Compilation

The files are to be compiled this way:

```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

### Example of usage

```
$ cat test.m
push 3
push 5
push 6
pall
add
pall
$ ./monty test.m
6
5
3
11
3
```

## Authors

* **Oluwapelumi Olalekan** - [pelumi-guy](https://github.com/pelumi-guy)
* **Stephanie (Empress) Moses** - [Urgirlempress](https://github.com/Urgirlempress)
