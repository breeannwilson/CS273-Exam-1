#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

namespace Exam1 // NAMESPACE
{
	class Wheel
	{
	private:
		int _radius;
	public:
		//no-arg constructor
		Wheel() {
			_radius = 0;
		}

		Wheel(int radius) { _radius = radius; }

		int getRadius() {
			return _radius;
		}
	
	};

	// STEP 1: Complete the implementation of the Vehicle base class 
	// as described in the UML diagram
	class Vehicle
	{
	protected:
		string _color;
		int _topspeed;
		//class Vehicle has a vector of type Wheel
		vector<Wheel> wheels;

	public:
	
		//no-arg constructor
		Vehicle() {
			_color = "";
		}

		Vehicle(string color) {
			_color = color;
		}

		virtual void Description() = 0;
	};

	// STEP 2:  Define the RaceCar, Sedan, and Pickup classes as described
	// in the UML diagram.   For this test, you do not need to separate
	// the class implementation into a cpp file.
	class RaceCar : public Vehicle {
	public:
		//RaceCar inherits constructor from Vehicle so don't need any "stuff" inside here
		RaceCar(string color) : Vehicle(color) {
		}
	
		void Description() {
			//setting the topspeed constant for all racecars
			_topspeed = 250;
			cout << "I am a " << _color << " race car that can race " << _topspeed << "mph. Vroom!";
			//creating an object of class Wheel that sets wheel size for all race cars to 305
			Wheel w(305);
			cout << " And my wheel radius is " << w.getRadius() << "mm." << endl;
		}
		//Top speed: 250mph
		//Wheel radius: 305mm
	};

		class Sedan : public Vehicle {
		private:
			int number_of_seats;
		public:
			//no-arg constructor
			Sedan() {
				number_of_seats = 0;
			}
			//inherits directly from Vehicle for color, but seats is only inside Sedan
			Sedan(string color, int seats) : Vehicle(color) {
				number_of_seats = seats;
			}
			 
			int getSeats() {
				return number_of_seats;
			}
			void setSeats(int seats) {
				seats = number_of_seats;
			}

			void Description() {
				//setting the _topspeed constant for all sedans
				_topspeed = 95;
				cout << "I am a " << _color << " sedan that can carry " << getSeats() <<
					" people at " << _topspeed << "mph. Yea!";
				//creating an object of Wheel class, "w", that sets the wheel size for sedans to 381
				Wheel w(381);
				cout << " And my wheel radius is " << w.getRadius() << "mm." << endl;
			}
			//Top speed: 95mph
			//Wheel radius: 381mm

		};
	

		class Pickup : public Vehicle {
		private:
			int hauling_capacity;
		public:
			//no-arg constructor
			Pickup() {
				hauling_capacity = 0;
			}
			//inherits directly from Vehicle for color, but capacity is only for Pickup class
			Pickup(string color, int capacity) : Vehicle(color) {
				hauling_capacity = capacity;
			}

			int getCapacity() {
				return hauling_capacity;
			}
			void setCapacity(int capacity) {
				capacity = hauling_capacity;
			}

			void Description() {
				//setting the topspeed constant for all pickups
				_topspeed = 85;
				cout << "I am a " << _color << " pickup that can haul " << getCapacity() << "sq. feet at "
					<< _topspeed << "mph.";
				//create an object of class Wheel, "w", that sets the wheel size for pickups to 432
				Wheel w(432);
				cout << " And my wheel radius is " << w.getRadius() << "mm." << endl;
			}
			//Top speed: 85mph
			//Wheel radius: 432mm

		};



}
int main()
{
	Exam1::Vehicle * Garage[3];

	// STEP 3: Assign ONE RaceCar, ONE Sedan, AND ONE Pickup object to each of the elements 
	// in the Garage array.  Remember the classes are defined in the namespace Exam1.
	Garage[0] = new Exam1::RaceCar("red");
	Garage[1] = new Exam1::Sedan("brown", 5);
	Garage[2] = new Exam1::Pickup("black", 600);

	for (int i = 0; i < 3; ++i)
	{
		// The method Description() should display an output like 
		// "I am a red sedan (or racecar/pickup) and I can go 95 (or 250 or 85) mph"
		Garage[i]->Description();
	}
	system("pause");
}

