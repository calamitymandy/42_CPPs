#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Incorrect input... try: ./convert <value>\n";
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}

/* TESTING:
✅ ./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

✔ 0 → ASCII = non-printable → Non displayable

✅ ./convert 42
char: '*'
int: 42
float: 42.0f
double: 42.0

✔ 42 → '*' in ASCII

✅ ./convert a
char: 'a'
int: 97
float: 97.0f
double: 97.0

✔ 'a' → ASCII = 97

✅ ./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0

✔ float → converted cleanly

✅ ./convert 42.0
char: '*'
int: 42
float: 42.0f
double: 42.0

✔ double → same result

⚠️ ./convert nan
char: impossible
int: impossible
float: nanf
double: nan

✔ NaN cannot be:

char ❌
int ❌

✔ but valid float/double

⚠️ ./convert nanf
char: impossible
int: impossible
float: nanf
double: nan

✔ same logic as above

⚠️ ./convert +inf
char: impossible
int: impossible
float: +inff
double: +inf

✔ infinity:

no char/int
valid float/double
⚠️ ./convert -inff
char: impossible
int: impossible
float: -inff
double: -inf

✔ same logic

🚨 ./convert 999999999999999999999
char: impossible
int: impossible
float: 1e+21f
double: 1e+21
⚠️ Important explanation:
Too large for:
char ❌
int ❌ (overflow)
double:
✔ still valid → scientific notation
float:
✔ overflows → becomes +inff

Small values
./convert 1
char: Non displayable
int: 1
float: 1.0f
double: 1.0
🔹 Printable char boundary
./convert 32
char: ' '
int: 32
float: 32.0f
double: 32.0
🔹 Non displayable boundary
./convert 31
char: Non displayable
...
🔹 Max char
./convert 127
char: Non displayable
🔹 Negative int
./convert -42
char: impossible
int: -42
float: -42.0f
double: -42.0
🔹 Float without decimals (invalid)
./convert 42f
char: impossible
int: impossible
float: impossible
double: impossible

✔ MUST be rejected

🔹 Double without decimals (invalid)
./convert 42.

⚠️ Depends on your parser
→ Usually considered valid double

🔹 Leading sign
./convert +42

✔ valid int

🔹 Zero float
./convert 0.0f

✔ valid

❌ Invalid inputs (VERY IMPORTANT)
🔹 Random string
./convert hello
char: impossible
int: impossible
float: impossible
double: impossible
🔹 Multiple dots
./convert 4.2.1

→ invalid

🔹 Empty input (won’t happen normally)
🔹 Only sign
./convert +

→ invalid

🔹 Mixed garbage
./convert 42abc

→ invalid
*/