# 42_CPPs

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

`a: 0`
(Default constructor called)

🧩 Step 2 — Fixed b(a);

🧱 Action: calls the copy constructor
🧠 Meaning: we make a new box b that copies the internal value from a.

+-----------+     +-----------+
|  a: 0     | --> |  b: 0     |
+-----------+     +-----------+
(Copy constructor called)

🧩 Step 3 — Fixed c;

🧱 Action: another default constructor
🧠 Meaning: we make a third box c, starting empty (value 0).

+-----------+     +-----------+     +-----------+
|  a: 0     | --> |  b: 0     |     |  c: 0     |
+-----------+     +-----------+     +-----------+
(Default constructor called)

🧩 Step 4 — c = b;

🧱 Action: calls the copy assignment operator
🧠 Meaning: c already exists — we replace its contents with b’s.

Before: c = 0
Copy assignment: c becomes a copy of b (0)
After: c = 0

+-----------+     +-----------+     +-----------+
|  a: 0     | --> |  b: 0     | --> |  c: 0     |
+-----------+     +-----------+     +-----------+
(Copy assignment operator called)

🧩 Step 5 — Exiting main()

🧱 Action: calls the destructor three times
🧠 Meaning: each object goes out of scope in reverse order of creation.

Destroy c
Destroy b
Destroy a

Destructor called
Destructor called
Destructor called
