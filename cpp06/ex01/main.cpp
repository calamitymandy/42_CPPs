#include <iostream>
#include "Serializer.hpp"

int main() {
    Data data;

    data.id = 42;
    data.name = "something else";

    Data *oriPtr = &data;

    uintptr_t serializedValue = Serializer::serialize(oriPtr);
    Data *deserializedPtr = Serializer::deserialize(serializedValue);

    std::cout << "ORIGINAL Data content:\n";
    std::cout << "id: " << oriPtr->id << "\n";
    std::cout << "name: " << oriPtr->name << "\n\n";

    std::cout << "Original pointer: " << oriPtr << "\n";
    std::cout << "Serialized value: " << serializedValue << "\n";
    std::cout << "Deserialized pointer: " << deserializedPtr << "\n\n";

    if (oriPtr == deserializedPtr)
        std::cout << "✅ Pointers are equal\n\n";
    else
        std::cout << "❌ Pointers are NOT equal\n\n";
        
/* 🚨 Undefined behavior if the object is deleted 
    delete oriPtr;
    delete deserializedPtr;
*/
    std::cout << "DESERIALIZED Data content:\n";
    std::cout << "id: " << deserializedPtr->id << "\n";
    std::cout << "name: " << deserializedPtr->name << "\n";

    return 0;
}