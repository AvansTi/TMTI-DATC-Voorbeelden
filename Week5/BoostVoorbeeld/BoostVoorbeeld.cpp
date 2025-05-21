#include <iostream>
#include <boost/units/systems/si.hpp>
#include <boost/units/io.hpp>
#include <boost/units/quantity.hpp>

namespace si = boost::units::si;
using namespace boost::units;

int main() 
{
    std::cout << "Using boost version: " << BOOST_VERSION << std::endl;
    
    // Define a typedef for a quantity of length using SI units
    typedef quantity<si::length> Length;
    typedef quantity<si::mass> Mass;
    typedef quantity<si::time> Time;
    typedef quantity<si::velocity> Velocity;
    typedef quantity<si::force> Force;
    typedef quantity<si::acceleration> Acceleration;
    typedef decltype(std::declval<Mass>()* std::declval<Velocity>()) Momentum;

    // Maak instanties van eenheden
    Length length(5.0 * si::meters);
    Mass mass(2.0 * si::kilograms);
    Time time(3.0 * si::seconds);
    Acceleration acc = (2.0 * si::meters_per_second_squared);
    Velocity v = (3.0 * si::meters_per_second);
    
    // Berekeningen met eenheden
    Velocity velocity = length / time;
    Force force = mass * acc;
    Momentum momentum = mass * v;

    // Uitvoer van resultaten
    std::cout << "Length: " << length << std::endl;
    std::cout << "Mass: " << mass << std::endl;
    std::cout << "Time: " << time << std::endl;
    std::cout << "Velocity: " << velocity << std::endl;
    std::cout << "Force: " << force << std::endl;
    std::cout << "Momentum: " << momentum << std::endl;

    return 0;
}
