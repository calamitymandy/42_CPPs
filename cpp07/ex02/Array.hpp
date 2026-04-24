#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

/* We use new[] instead of malloc because new[] correctly calls constructors and destructors 
for each element, which is required for complex types like std::string.

If there is a negative index, it’s converted to unsigned, becoming a large value, 
which is caught by the index >= _size check

The assignment operator is safe because we allocate new memory first, 
then replace the old one, ensuring strong exception safety.
*/

template <typename T>
class Array {
    private:
        T *_data;
        unsigned int _size;
    
    public:
        // Default constructor
        Array() : _data(NULL), _size(0) {}

        //constructor with size
        Array(unsigned int num) : _size(num) {
            if (num == 0)
                _data = NULL;
            else
                _data = new T[num](); // value-initialized
        }

        // Copy constructor
        Array(const Array &copy) : _size(copy._size) {
            if (_size == 0) {
                _data = NULL;
                return;
            }
            _data = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
                _data[i] = copy._data[i];
        }

        // Assignment operator
        Array &operator=(const Array &copy) {
            if (this == &copy)
                return *this;

            // Create a new array for the copy 
            T *newData = NULL;

            if (copy._size > 0) {
                newData = new T[copy._size]; // Deep copy → No shared memory. Safe even if allocation fails
                for (unsigned int i = 0; i < copy._size; i++)
                    newData[i] = copy._data[i];
            }

            delete[] _data;
            _data = newData;
            _size = copy._size;

            return *this;
        }

        // Destructor
        ~Array() {
            delete[] _data;
        }

        // BOUNDARY CHECKING
        // Handles overflow index & negative index (via unsigned)

        // Subscript operator
        T &operator[](unsigned int index) {
            if (index >= _size) // Out-of-bounds checking
                throw std::exception();
            return _data[index];
        }

        // Subscript operator for const objects
        const T &operator[](unsigned int index) const {
            if (index >= _size) // Out-of-bounds checking
                throw std::exception();
            return _data[index];
        }

        // Size getter
        unsigned int size() const {
            return _size;
        }
};

#endif