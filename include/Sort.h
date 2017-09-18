#include <list>
#include "Shapes.h"

class Sort {
public:
	static void sortByIncreasingPerimeter(std::list<Shape *> * shapeList);
	static void sortByDecreasingPerimeter(std::list<Shape *> * shapeList);
	static void sortByIncreasingArea(std::list<Shape *> * shapeList);
	static void sortByDecreasingArea(std::list<Shape *> * shapeList);
	static void sortByIncreasingCompactness(std::list<Shape *> * shapeList);
};
