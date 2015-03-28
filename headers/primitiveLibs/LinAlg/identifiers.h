#ifndef IDENTIFIERS_H
#define IDENTIFIERS_H

namespace Identifiers{

struct From{
    From(unsigned interval) : interval(interval) {};

    From operator= (const unsigned& value){this->interval = value; return *this;}

    From& operator--(int){return *this;}
    unsigned interval;
};

struct To{
    To(unsigned interval) : interval(interval) {};

    void operator= (const unsigned& value){this->interval = value;}

    To& operator--(int){return *this;}
    unsigned interval;
};

//unsigned* operator, (from from_interval, to to_interval);
}

#endif // IDENTIFIERS_H
