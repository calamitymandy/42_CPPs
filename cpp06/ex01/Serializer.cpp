#include "Serializer.hpp"

// Orthodox Canonical Form
Serializer::Serializer() {}
Serializer::Serializer(const Serializer &copy) { (void)copy; }
Serializer &Serializer::operator=(const Serializer &copy) {
    (void)copy;
    return *this;
}
Serializer::~Serializer() {}

/* this is not real serialization. It only converts a pointer into an 
integer representation, not the object’s content.

Data is not copied, we just pass the address, same memory & same object.

reinterpret_cast is the only cast that allows converting a pointer 
to an integer type like uintptr_t and back.

It allows bit-level reinterpretation
Needed for:
pointer → integer
integer → pointer
*/
uintptr_t Serializer::serialize(Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}
Data *Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}