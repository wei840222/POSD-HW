#ifndef UTSORT_H
#define UTSORT_H
#include "include/Shapes.h"
#include "include/Media.h"
#include "include/Sort.h"

//Data for test
Rectangle r1(0, 0, 1, 1,"r1"), r2(0, 0, 2, 2,"r2"), r3(0, 0, 2, 3,"r3");
Circle c1(0, 0, 1, "c1"), c2(0, 0, 2, "c2"), c3(0, 0, 3, "c3");
Triangle t1({0, 0}, {0, 1}, {1, 0}, "t1"), t2({0, 0}, {0, 1}, {2, 0}, "t2");

void setupTestData(std::list<Shape *> *Shps)
{
	Shps->push_back(&r1); Shps->push_back(&r2); Shps->push_back(&r3);
	Shps->push_back(&c1); Shps->push_back(&c2); Shps->push_back(&c3);
	Shps->push_back(&t1); Shps->push_back(&t2);
}

TEST (Sort, sortByIncreasingPerimeter)
{
	std::list<Shape *> Shps;
	setupTestData(&Shps);

	Sort::sortByIncreasingPerimeter(&Shps);

	std::stringstream sorted;
	for (std::list<Shape *>::iterator itr = Shps.begin(); itr != Shps.end(); itr++)
	{
		sorted << (*itr)->getShapeName() << " ";
	}

	ASSERT_EQ(sorted.str(), "t1 r1 t2 c1 r2 r3 c2 c3 ");
}

TEST (Sort, sortByDecreasingPerimeter)
{
	std::list<Shape *> Shps;
	setupTestData(&Shps);
	
	Sort::sortByDecreasingPerimeter(&Shps);

	std::stringstream sorted;
	for (std::list<Shape *>::iterator itr = Shps.begin(); itr != Shps.end(); itr++)
	{
		sorted << (*itr)->getShapeName() << " ";
	}

	ASSERT_EQ(sorted.str(), "c3 c2 r3 r2 c1 t2 r1 t1 ");
}

TEST (Sort, sortByIncreasingArea)
{
	std::list<Shape *> Shps;
	setupTestData(&Shps);
	
	Sort::sortByIncreasingArea(&Shps);

	std::stringstream sorted;
	for (std::list<Shape *>::iterator itr = Shps.begin(); itr != Shps.end(); itr++)
	{
		sorted << (*itr)->getShapeName() << " ";
	}

	ASSERT_EQ(sorted.str(), "t1 r1 t2 c1 r2 r3 c2 c3 ");
}

TEST (Sort, sortByDecreasingArea)
{
	std::list<Shape *> Shps;
	setupTestData(&Shps);
	
	Sort::sortByDecreasingArea(&Shps);
	
	std::stringstream sorted;
	for (std::list<Shape *>::iterator itr = Shps.begin(); itr != Shps.end(); itr++)
	{
		sorted << (*itr)->getShapeName() << " ";
	}

	ASSERT_EQ(sorted.str(), "c3 c2 r3 r2 c1 r1 t2 t1 ");
}

TEST (Sort, sortByIncreasingCompactness)
{
	std::list<Shape *> Shps;
	setupTestData(&Shps);
	
	Sort::sortByIncreasingCompactness(&Shps);

	
	std::stringstream sorted;
	for (std::list<Shape *>::iterator itr = Shps.begin(); itr != Shps.end(); itr++)
	{
		sorted << (*itr)->getShapeName() << " ";
	}

	ASSERT_EQ(sorted.str(), "t1 t2 r1 r2 c1 r3 c2 c3 ");
}

#endif
