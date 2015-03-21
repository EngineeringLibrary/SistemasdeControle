#include "SistemasdeControle/headers/primitiveLibs/LinAlg/identifiers.h"

unsigned* Identifiers::operator, (from from_interval, to to_interval)
{
    unsigned* ret = new unsigned[2];

    ret[0] = from_interval.interval;
    ret[1] = to_interval.interval;

    return ret;
}
