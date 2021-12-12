#include "Objects.h"

Objects::Objects(const Objects& other)
{
    serialNumber = other.serialNumber;
    color = other.color;
    direction = other.direction;
}
