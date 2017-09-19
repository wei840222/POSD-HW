#ifndef UTSORT_H
#define UTSORT_H
#include "include/Shapes.h"
#include "include/Media.h"
#include "include/Sort.h"


TEST (Sort, sortByIncreasingPerimeter)
{
	Rectangle r1(0, 0, 1, 1,"r1"), r2(0, 0, 2, 2,"r2"), r3(0, 0, 2, 3,"r3");
	Circle c1(0, 0, 1, "c1"), c2(0, 0, 2, "c2"), c3(0, 0, 3, "c3");
	vertex v1, v2, v3, v4;
	v1.x = 0; v1.y = 0; v2.x = 0; v2.y = 1; v3.x = 1; v3.y = 0; v4.x = 2; v4.y = 0;
	Triangle t1(v1, v2, v3, "t1"), t2(v1, v2, v4, "t2");
	
	std::list<Shape *> Shps;
	Shps.push_back(&r1); Shps.push_back(&r2); Shps.push_back(&r3);
	Shps.push_back(&c1); Shps.push_back(&c2); Shps.push_back(&c3);
	Shps.push_back(&t1); Shps.push_back(&t2);

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
	Rectangle r1(0, 0, 1, 1,"r1"), r2(0, 0, 2, 2,"r2"), r3(0, 0, 2, 3,"r3");
	Circle c1(0, 0, 1, "c1"), c2(0, 0, 2, "c2"), c3(0, 0, 3, "c3");
	vertex v1, v2, v3, v4;
	v1.x = 0; v1.y = 0; v2.x = 0; v2.y = 1; v3.x = 1; v3.y = 0; v4.x = 2; v4.y = 0;
	Triangle t1(v1, v2, v3, "t1"), t2(v1, v2, v4, "t2");	
	
	std::list<Shape *> Shps;
	Shps.push_back(&r1); Shps.push_back(&r2); Shps.push_back(&r3);
	Shps.push_back(&c1); Shps.push_back(&c2); Shps.push_back(&c3);
	Shps.push_back(&t1); Shps.push_back(&t2);
	
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
	Rectangle r1(0, 0, 1, 1,"r1"), r2(0, 0, 2, 2,"r2"), r3(0, 0, 2, 3,"r3");
	Circle c1(0, 0, 1, "c1"), c2(0, 0, 2, "c2"), c3(0, 0, 3, "c3");
	vertex v1, v2, v3, v4;
	v1.x = 0; v1.y = 0; v2.x = 0; v2.y = 1; v3.x = 1; v3.y = 0; v4.x = 2; v4.y = 0;
	Triangle t1(v1, v2, v3, "t1"), t2(v1, v2, v4, "t2");	
	
	std::list<Shape *> Shps;
	Shps.push_back(&r1); Shps.push_back(&r2); Shps.push_back(&r3);
	Shps.push_back(&c1); Shps.push_back(&c2); Shps.push_back(&c3);
	Shps.push_back(&t1); Shps.push_back(&t2);
	
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
	Rectangle r1(0, 0, 1, 1,"r1"), r2(0, 0, 2, 2,"r2"), r3(0, 0, 2, 3,"r3");
	Circle c1(0, 0, 1, "c1"), c2(0, 0, 2, "c2"), c3(0, 0, 3, "c3");
	vertex v1, v2, v3, v4;
	v1.x = 0; v1.y = 0; v2.x = 0; v2.y = 1; v3.x = 1; v3.y = 0; v4.x = 2; v4.y = 0;
	Triangle t1(v1, v2, v3, "t1"), t2(v1, v2, v4, "t2");	
	
	std::list<Shape *> Shps;
	Shps.push_back(&r1); Shps.push_back(&r2); Shps.push_back(&r3);
	Shps.push_back(&c1); Shps.push_back(&c2); Shps.push_back(&c3);
	Shps.push_back(&t1); Shps.push_back(&t2);
	
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
	Rectangle r1(0, 0, 1, 1,"r1"), r2(0, 0, 2, 2,"r2"), r3(0, 0, 2, 3,"r3");
	Circle c1(0, 0, 1, "c1"), c2(0, 0, 2, "c2"), c3(0, 0, 3, "c3");
	vertex v1, v2, v3, v4;
	v1.x = 0; v1.y = 0; v2.x = 0; v2.y = 1; v3.x = 1; v3.y = 0; v4.x = 2; v4.y = 0;
	Triangle t1(v1, v2, v3, "t1"), t2(v1, v2, v4, "t2");	
	
	std::list<Shape *> Shps;
	Shps.push_back(&r1); Shps.push_back(&r2); Shps.push_back(&r3);
	Shps.push_back(&c1); Shps.push_back(&c2); Shps.push_back(&c3);
	Shps.push_back(&t1); Shps.push_back(&t2);
	
	Sort::sortByIncreasingCompactness(&Shps);

	
	std::stringstream sorted;
	for (std::list<Shape *>::iterator itr = Shps.begin(); itr != Shps.end(); itr++)
	{
		sorted << (*itr)->getShapeName() << " ";
	}

	ASSERT_EQ(sorted.str(), "c3 c2 r3 r2 c1 r1 t2 t1 ");
}

#endif
