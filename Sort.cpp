#include "include/Sort.h"

void Sort::sortByIncreasingPerimeter(std::list<Shape *> *shapeList)
{
	shapeList->sort([](Shape* s1, Shape* s2)->bool
	{
		return s1->perimeter() < s2->perimeter();
	});
}

void Sort::sortByDecreasingPerimeter(std::list<Shape *> * shapeList)
{
	shapeList->sort([](Shape* s1, Shape* s2)->bool
	{
		return s1->perimeter() > s2->perimeter();
	});
}

void Sort::sortByIncreasingArea(std::list<Shape *> * shapeList)
{
	shapeList->sort([](Shape* s1, Shape* s2)->bool
	{
		return s1->area() < s2->area();
	});
}

void Sort::sortByDecreasingArea(std::list<Shape *> * shapeList)
{
	shapeList->sort([](Shape* s1, Shape* s2)->bool
	{
		return s1->area() > s2->area();
	});
}
  
void Sort::sortByIncreasingCompactness(std::list<Shape *> * shapeList)
{
	//Compactness: 4*PI*area/perimeter^2
	shapeList->sort([](Shape* s1, Shape* s2)->bool
	{
		return 4*M_PI*s1->area()/pow(s1->perimeter(), 2) < 4*M_PI*s2->area()/pow(s2->perimeter(), 2);
	});
}
