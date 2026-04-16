#ifndef WHATEVER_HPP
# define WHATEVER_HPP

/* We pass by reference:
swap must use `T &` Otherwise it won’t modify original variables 
`T` const &a` Avoids unnecessary copies 

Subject says: if equal → return second parameter
if a == b, condition is false → returns b (same for min & max)*/

template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(T const &a, T const &b) {
    if (a < b)
        return a;
    else
        return b;
}

template <typename T>
T max(T const &a, T const &b) {
    if (a > b)
        return a;
    else
        return b;
}

#endif