*This project has been created as part of the 42 curriculum by ayel-mac.*

# ft_printf

## Description

`ft_printf` is a recreation of the standard C `printf()` function.

The goal of this project is to understand how formatted output works in C, while learning how to handle variadic functions and manipulate different data types.

This project introduces several important concepts:

- Variadic functions.
- `va_list`, `va_start`, `va_arg`, and `va_end`.
- Format string parsing.
- Type conversions.
- Modular programming and code organization.
- Writing and managing a static library.

The program analyzes a format string and prints the corresponding output while handling the required conversion specifiers.

---

## Instructions

### Compilation

Clone the repository and enter its directory:

```bash
git clone REPOSITORY_URL
cd ft_printf
```

Compile the library using:

```bash
make
```

This generates the static library:

```text
libftprintf.a
```

### Available Makefile rules

| Rule | Description |
|---|---|
| `make` | Compile the project and create the static library |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and the library |
| `make re` | Recompile the project from scratch |

### Usage

Include the header in your source file:

```c
#include "ft_printf.h"
```

Compile your program together with the library:

```bash
cc main.c libftprintf.a
```

Example:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "world");
    ft_printf("Number: %d\n", 42);
    ft_printf("Character: %c\n", 'A');
    return (0);
}
```

---

## Supported Conversions

The project handles the conversion specifiers required by the subject, including:

| Specifier | Description |
|---|---|
| `%c` | Prints a character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address |
| `%d` | Prints a decimal integer |
| `%i` | Prints an integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints a number in lowercase hexadecimal |
| `%X` | Prints a number in uppercase hexadecimal |
| `%%` | Prints a literal percent sign |

---

## Algorithm

The algorithm processes the format string from left to right.

1. Initialize the variadic argument list using `va_start`.
2. Iterate through the format string character by character.
3. If the current character is not `%`, print it directly.
4. If `%` is encountered, examine the following character to identify the conversion specifier.
5. Retrieve the corresponding argument using `va_arg`, with the appropriate type.
6. Call the relevant helper function to handle the conversion and print the result.
7. Keep track of the number of characters printed.
8. Finish processing the arguments using `va_end`.
9. Return the total number of characters printed.

This approach allows the format string to be processed in a single pass, making the algorithm straightforward and efficient.

### Algorithm justification

A single-pass parsing algorithm was chosen because the format string can be analyzed sequentially without needing to revisit previously processed characters.

The time complexity is approximately **O(n)**, where `n` is the length of the format string, excluding additional work required to convert and print individual arguments.

Separating the conversion logic into helper functions makes the code easier to read, maintain, debug, and extend.

---

## Data Structures

The project mainly relies on the following data structures and variables:

### `va_list`

`va_list` is used to manage and access the variable arguments passed to `ft_printf`.

It works together with:

- `va_start` — initializes the argument list.
- `va_arg` — retrieves the next argument of the requested type.
- `va_end` — ends the argument list processing.

This mechanism allows the function to handle a variable number of arguments without knowing their number in advance.

### Format string

The format string is a character array containing ordinary characters and conversion specifiers.

It is traversed using an index or pointer to determine which characters should be printed directly and which arguments should be processed.

### Character counter

A counter is used to keep track of the number of characters printed.

Depending on the implementation, this counter may be passed to helper functions through a pointer, allowing each function to update the total number of characters printed.

### Data structure justification

No complex data structures are required for this project.

A sequential parser, a `va_list`, and a character counter are sufficient to handle the required conversions. This keeps the implementation lightweight and avoids unnecessary memory allocation or data structure complexity.

---

## Resources

### AI Usage

AI was used as a learning and assistance tool during the development of this project.

It was used for:

- Understanding variadic functions and the `stdarg.h` macros.
- Learning how `va_list`, `va_start`, `va_arg`, and `va_end` work.
- Understanding the relationship between variadic arguments, CPU registers, the stack, and the calling convention.
- Clarifying C concepts and understanding potential errors.
- Getting explanations and guidance while debugging and learning the project.

AI was primarily used to explain concepts and support the learning process. The implementation and final decisions were made and reviewed by the student.
