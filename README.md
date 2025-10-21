# 42_CPPs

## CPP 00
### Ex01:
🧩 1. Error Management

“There is some error management to do in this program but the behaviors are not specified in the subject. Exiting the program properly or managing errors is ok. A segfault is not! :D”

✅ Your code passes this requirement.

You check for empty fields in addContact() and display an error instead of storing an invalid contact.

You prevent out-of-range and non-numeric input in searchContact() using std::cin.fail() and std::cin.clear().

You handle invalid commands gracefully in the loop (they’re simply ignored).

There’s no risk of segmentation fault anywhere.




🧩 2. EXIT Command

“Write down the EXIT command based on what is in the subject line.”

✅ Implemented correctly.

The loop continues until the user types EXIT.

break; exits cleanly, then returns 0.

No special cleanup is needed, so this behavior matches the subject.




🧩 3. Visibility

“Contact class attributes must be private. The class must expose the corresponding accessors. Also check that anything used only in one class (and not just the Contact class) is private and the rest public.”

✅ Implemented exactly as required.

All Contact fields are correctly private. ✅

PhoneBook has appropriate private and public sections. ✅

The subject expects you to provide accessors (getters) 
Instead of a classic getter/setter approach	(Public getFirstName() / setFirstName() functions that read/write private members)
-> I did an encapsulation through display functions. No getters, but you access fields only through displayShort() and displayFull() (which are public).
As long as no private member is accessed directly elsewhere it is correct.

That is “exposing accessors” in spirit, because it respects encapsulation and hides implementation details.



🧩 4. Contact and PhoneBook Classes

“The code must include a Contact class (or other name)... contain the requested attributes... must contain a Phonebook class with an array of Contacts inside.”

✅ Implemented exactly as required.

Contact has all required fields: first name, last name, nickname, phone number, darkest secret.

PhoneBook contains a fixed-size array of 8 contacts (no dynamic allocation).

Correct cycling replacement logic when adding the 9th contact.




🧩 5. Read/Eval Loop

“The program should offer a sort of read/eval loop: Read then process input, then wait for new input until receiving an EXIT command. The loop should be done in a C++ way (std::cin).”

✅ Fully correct.

The program reads user input via std::getline(std::cin, command) (C++-style input).

It loops until EXIT.

No infinite-loop issues, no manual flushing needed.




🧩 6. ADD Command

“Make a note of the ADD command based on what is in the subject line. Rate it from 0 (failed) through 5 (excellent).”

✅ Well implemented and clean.

Prompts for all required fields.

Checks validity (isValid()).

Prevents adding incomplete contacts.

Handles cyclic overwriting correctly.




🧩 7. SEARCH Command

“Write down the SEARCH command based on what is requested in the subject line. A slight deviation from the expected format is not important. This part is about using ‘iomanips’ in C++ and that’s what you need to focus on.”

✅ Excellent.

Uses std::setw(10) correctly for alignment.

Truncates strings longer than 10 chars and appends a dot (.).

Properly prints the table header and all contacts.

Handles input errors and out-of-range indexes.

Displays full contact details afterward.





## CPP 02
### Ex00:

1. OCF stands for Orthodox Canonical Form (also called Canonical Class Form in C++).
It’s a standard structure that every well-designed C++ class should follow when it manages resources or data that need proper copying or destruction.

It defines four special member functions that together ensure your class behaves correctly in all situations.

| Function                     | Purpose                                                         | When It’s Called                                                          |
| ---------------------------- | --------------------------------------------------------------- | ------------------------------------------------------------------------- |
| **Default Constructor**      | Initializes a new object with default values.                   | When you write `Fixed a;`                                                 |
| **Copy Constructor**         | Creates a new object as a copy of another one.                  | When you write `Fixed b(a);` or `Fixed b = a;`                            |
| **Copy Assignment Operator** | Replaces the contents of an existing object with another one’s. | When you write `c = b;`                                                   |
| **Destructor**               | Cleans up before the object is destroyed.                       | When the object goes out of scope (end of program, end of function, etc.) |


🧩 Step 1 — Fixed a;

🧱 Action: calls the default constructor
🧠 Meaning: we create the first box a, and it starts with _fixedPointValue = 0.

`   a: 0    `

(Default constructor called)

🧩 Step 2 — Fixed b(a);

🧱 Action: calls the copy constructor
🧠 Meaning: we make a new box b that copies the internal value from a.


`   a: 0    ` --> `   b: 0  `

(Copy constructor called)

🧩 Step 3 — Fixed c;

🧱 Action: another default constructor
🧠 Meaning: we make a third box c, starting empty (value 0).


`   a: 0    ` -->  `    b: 0    ` 

`   c: 0    `

(Default constructor called)

🧩 Step 4 — c = b;

🧱 Action: calls the copy assignment operator
🧠 Meaning: c already exists — we replace its contents with b’s.

Before: c = 0
Copy assignment: c becomes a copy of b (0)
After: c = 0


`   a: 0    ` -->  `    b: 0    ` --> `   c: 0    `

(Copy assignment operator called)

🧩 Step 5 — Exiting main()

🧱 Action: calls the destructor three times
🧠 Meaning: each object goes out of scope in reverse order of creation.

- Destroy c
- Destroy b
- Destroy a

- Destructor called
- Destructor called
- Destructor called


### Ex01:

🧩 what’s a fixed-point number?

We store numbers as integers, but interpret them as if they had a binary “decimal point” at a fixed place.

Here, we always reserve 8 bits for the fractional part (_fractionalBits = 8).

That means each stored integer actually represents a real number divided by 2⁸ = 256.

stored_value = real_value × 256
real_value   = stored_value ÷ 256


| Constructor Type | Formula               | Example (`_fractionalBits = 8`) |
| ---------------- | --------------------- | ------------------------------- |
| From `int`       | `value << 8`          | `10 → 2560`                     |
| From `float`     | `roundf(value * 256)` | `42.42 → 10860`                 |
| To `int`         | `value >> 8`          | `10860 → 42`                    |
| To `float`       | `value / 256.0`       | `10860 → 42.42`                 |


🧠 How C++ decides which constructor to call

C++ looks at how the object is created (the right-hand side of the initialization) and chooses the constructor that matches the type of what you’re passing in.

Here’s how it decides:

You write...	    What it means	                        Which function is called
Fixed a;	        Create a new Fixed, no arguments	👉 Fixed::Fixed() (default constructor)
Fixed b(10);	    Create from an integer	            👉 Fixed::Fixed(const int intValue)
Fixed c(42.42f);	Create from a float	                👉 Fixed::Fixed(const float floatValue)
Fixed d(b);	        Create from another Fixed	        👉 Fixed::Fixed(const Fixed &copy) (copy constructor)


🧩 Step 1 — Fixed a;

Function called: `Fixed::Fixed() (default constructor)`

What happens inside default constructor:

Fixed::Fixed() : _fixedPointValue(0) { /* prints "Default constructor called" */ }

Effect: _fixedPointValue becomes 0.


Math / meaning:

Stored integer = 0.

(Interpreted real value = 0 / 256.0 = 0.0) NOT HAPPENING THERE

Output line: "Default constructor called"


🧩 Step 2 — Fixed const b(10);

Function called: `Fixed::Fixed(const int intValue)`

What happens inside the int constructor:

Code executed (roughly):

Fixed::Fixed(const int intValue) {
    _fixedPointValue = intValue << _fractionalBits;
    // prints "Int constructor called"
}


intValue = 10.

_fractionalBits = 8, so intValue << 8 is bit-shift left by 8 bits.

Exact computation:

10 << 8 = 10 * 2^8 = 10 * 256 = 2560.

Store _fixedPointValue = 2560.

Interpretation:

Real value represented = 2560 / 256.0 = 10.0.

Why shift left: shifting left by 8 bits multiplies by 2^8. ** This places the integer 
in the top bits and reserves the lower 8 bits for fractional part (all zeros here). **

Output line: "Int constructor called"

🧩 Step 3 — Fixed const c(42.42f);

Function called: `Fixed::Fixed(const float floatValue)`

What happens inside the float constructor:

Code executed (roughly):

Fixed::Fixed(const float floatValue) {
    _fixedPointValue = roundf(floatValue * (1 << _fractionalBits));
    // prints "Float constructor called"
}


floatValue = 42.42f.

Compute multiplier 1 << 8 = 256.

Exact computation:

Multiply: 42.42 * 256 = 10859.52

Round: roundf(10859.52) = 10860 (round to nearest integer)

Store: _fixedPointValue = 10860

Interpretation:

Real represented = 10860 / 256.0 = 42.421875 (this is the closest representable value with 8 fractional bits).

Printed float via toFloat() later will show 42.4219 (formatted by stream).

Why multiply and round:

Multiplying by 256 shifts the decimal portion into integer bits; roundf avoids truncation error and gives the closest representable fixed value.

Output line: "Float constructor called"


🧩 Step 4 — Fixed const d(b);

Function called: `Fixed::Fixed(const Fixed &copy) (copy constructor)`

What happens inside copy constructor:

Code executed (roughly):

Fixed::Fixed(const Fixed &copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy; // calls assignment operator
}


That delegates to the assignment operator operator=(const Fixed &assignedCopy).

Inside operator=:

Fixed &Fixed::operator=(const Fixed &assignedCopy) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &assignedCopy)
        this->_fixedPointValue = assignedCopy.getRawBits();
    return *this;
}


assignedCopy.getRawBits() returns 2560 (value inside b).

So d._fixedPointValue = 2560.

Interpretation:

d now represents 2560 / 256.0 = 10.0 — exact copy of b.

Output lines:

"Copy constructor called"

"Copy assignment operator called" (because you used *this = copy inside copy ctor)


🧩 Step 5 — a = Fixed(1234.4321f);

This is a compound operation that involves temporary object creation, assignment, then temporary destruction.

5.1 Create temporary Fixed(1234.4321f)

Function called: `Fixed::Fixed(const float floatValue)` (float constructor for the temporary)

Exact computation inside constructor:

floatValue = 1234.4321f

Multiply: 1234.4321 * 256 = 316007.629...

Round: roundf(316007.629...) = 316008

Store temporary _fixedPointValue = 316008

Output "Float constructor called"

5.2 Assignment to a

Function called: Fixed::operator=(const Fixed &assignedCopy) where assignedCopy is the temporary

Inside operator=:

It checks if (this != &assignedCopy) — true because a and the temporary are different objects.

It fetches assignedCopy.getRawBits() which returns 316008.

Sets a._fixedPointValue = 316008.

Output "Copy assignment operator called"

Result:

a now represents 316008 / 256.0 = 1234.4296875

When printed the stream will format that as 1234.43.

5.3 Destroy the temporary

Function called: Fixed::~Fixed() (destructor) for the temporary

Output "Destructor called" for the temporary.

Why this order: temporaries are created for right-hand expressions and are destroyed after the full-expression (after the assignment completes).


🧩 Step 6 — std::cout << "a is " << a << std::endl;

This triggers the insertion operator you defined:

Function called:

operator<<(std::cout, a) — your overload:

std::ostream &operator<<(std::ostream &out, const Fixed &fixedNumber) {
    out << fixedNumber.toFloat();
    return out;
}


Fixed::toFloat() — called inside operator<<.

What toFloat() does:

float Fixed::toFloat(void) const {
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}


For a: _fixedPointValue = 316008.
316008 / 256.0f = 1234.4296875 → printed as 1234.43 by stream formatting.

For b: 2560 / 256 = 10.0 → prints 10

For c: 10860 / 256 = 42.421875 → prints 42.4219

For d: 2560 / 256 = 10.0

Key point: toFloat() divides the stored integer by 256.0 to restore the real value.

🧩 Step 7 — toInt() calls like a.toInt()

Function called: Fixed::toInt()

What it does:

int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}


For a (316008 >> 8): integer division by 256 truncated toward zero → 1234.

For c (10860 >> 8): 10860 / 256 = 42 (truncated), so integer part 42.

Why shift right: shifting right by 8 is integer division by 2^8 but implemented as a fast bit operation; this discards the fractional bits (no rounding — truncation).

🧩 Step 8 — Program end / destructors order

When main() returns, objects are destroyed in reverse order of creation:

Creation order and corresponding destructors:

a — created first → destroyed last

b — created second → destroyed second-last

c — third → destroyed third-last

d — fourth → destroyed first

So the destructor messages will appear in reverse creation order (depending exactly on how temporaries were created/destroyed earlier).

Each destructor call runs:

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}