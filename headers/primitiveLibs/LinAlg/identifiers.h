#ifndef IDENTIFIERS_H
#define IDENTIFIERS_H

namespace Identifiers{

struct from{
    from(unsigned interval) : interval(interval) {};

    unsigned interval;
};

struct to{
    to(unsigned interval) : interval(interval) {};

    unsigned interval;
};

unsigned* operator, (from from_interval, to to_interval);
}

#endif // IDENTIFIERS_H
