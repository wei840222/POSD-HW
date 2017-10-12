#ifndef UTSTRUCTURE_H
#define UTSTRUCTURE_H

#include "term.h"
#include "atom.h"
#include "number.h"
#include "variable.h"
#include "structure.h"

TEST(Structure, constructor)
{
    Atom a("a");
    Number x(5), y(10);
    Term vex[] = {a, x, y};
    Structure point(Atom("Point"), vex);
    EXPECT_EQ("Point", point.name().symbol());
    EXPECT_EQ("a", point.term()[0].symbol());
    EXPECT_EQ("5", point.term()[1].symbol());
    EXPECT_EQ("10", point.term()[2].symbol());
}

#endif