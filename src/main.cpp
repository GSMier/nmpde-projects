
#include <deal.II/base/point.h>
#include <deal.II/lac/vector.h>
#include <iostream>

int main()
{
    dealii::Point<2> p(3.0, 4.0);
    dealii::Vector<double> v(10);

    std::cout << p.norm() << '\n';
    std::cout << v.size() << '\n';

    return 0;

}
