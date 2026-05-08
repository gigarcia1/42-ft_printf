*This project has been created as part of the 42 curriculum by gigarcia.*

# ft_printf

## Description

`ft_printf` is a custom reimplementation of the standard C `printf()` function. In this project we recreate formatted output handling. We also learn important concepts such as:

- Variadic functions
- Low-level formatted output
- Memory and type management in C
- Parsing format strings
- Numeric base conversions
- 
The implementation handles formatted printf without the need to rely on `printf`, but we rely on `write()` instead.

## Supported Format Specifiers
| Specifier | Description |
|----------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address in hexadecimal |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints a signed decimal integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints a hexadecimal number in lowercase |
| `%X` | Prints a hexadecimal number in uppercase |
| `%%` | Prints a percent sign |

---

## Project Structure

```text
./
├── ft_printf.c
├── ft_printf.h
├── ft_printf_utils_nbr.c
├── ft_printf_utils_text.c
└── Makefile
```

## Technical Knowledge

The project heavily relies on the `<stdarg.h>` library:
- va_list ap;
- va_start(ap, fmt);
- va_arg(ap, int);
- va_end(ap);

## Technical Challenges
Some important technical difficulties I encountered during the project include:
• Correctly advancing va_list (I had to use a pointer for its return to avoid losing track of it and correctly advancing in the arguments)
• Managing edge cases (NULL, 0, negative numbers)
• Recursive number printing
• Preventing segmentation faults
• Handling pointer formatting
• Mimicking the exact behavior of the original printf
• Keeping track of the total printed length

# Instructions 

## Compilation
Compile the project using:
```make```
This generates the static library:
```libftprintf.a```
Cleaning Object Files:
```make clean```
Full Cleanup:
```Full Cleanup```
Recompile Everything:
```make re```

# Resources
## Official Documentation
• The Open Group printf specification
https://pubs.opengroup.org/onlinepubs/9699919799/functions/printf.html
• GNU libc documentation
https://www.gnu.org/software/libc/manual/
• C Variadic Functions (stdarg.h)
https://en.cppreference.com/w/c/variadic
• write() system call
https://man7.org/linux/man-pages/man2/write.2.html

## AI Usage
Artificial intelligence tools were used as learning assistance during the development of this project. And it was used for:

• Understanding variadic functions
• Clarifying undefined behavior cases
• Reviewing parsing logic
• Explaining architecture-dependent behavior of va_list
• Learning edge-case handling
• README structure and documentation formatting

AI was NOT used to fully generate the project implementation. The code logic, debugging, testing, and final implementation decisions were completed manually.
