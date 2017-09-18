#ifndef EXP_H
#define EXP_H
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
	
	ASSERT_EQ(Shps.front()->getShapeName(), "t1");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "r1");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "t2");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "c1");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "r2");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "r3");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "c2");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "c3");
	Shps.pop_front();
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
	
	ASSERT_EQ(Shps.front()->getShapeName(), "c3");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "c2");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "r3");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "r2");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "c1");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "t2");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "r1");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "t1");
	Shps.pop_front();
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
	
	ASSERT_EQ(Shps.front()->getShapeName(), "t1");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "r1");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "t2");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "c1");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "r2");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "r3");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "c2");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "c3");
	Shps.pop_front();
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
	
	ASSERT_EQ(Shps.front()->getShapeName(), "c3");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "c2");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "r3");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "r2");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "c1");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "r1");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "t2");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "t1");
	Shps.pop_front();
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

	/*
	for (std::list<Shape *>::iterator itr = Shps.begin(); itr != Shps.end(); itr++)
	{
		std::cout << (*itr)->getShapeName() << (*itr)->compactness() << std::endl;
	}
	*/
	
	ASSERT_EQ(Shps.front()->getShapeName(), "c1");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "c2");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "c3");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "r1");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "r2");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "r3");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "t1");
	Shps.pop_front();
	ASSERT_EQ(Shps.front()->getShapeName(), "t2");
	Shps.pop_front();
}

#endif
