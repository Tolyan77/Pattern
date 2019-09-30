#include <iostream>
using namespace std;

class Car  {
public:
	virtual void Show() {
		cout << "Shipping Car\n";
	}
};
class Lada2104 :public Car {
public:
	virtual void Show() {
		cout << "Shipping Car : Lada 2104\n";
	}
};
class BMWx8 :public Car {
public:
	virtual void Show() {
		cout << "Shipping Car : BMW x8\n";
	}
};

class Minivan  {
public:
	virtual void Show() {
		cout << "Shipping Minivan \n";
	}
};
class FordTransit350 : public Minivan {
public:
	virtual void Show() {
		cout << "Shipping Minivan : Ford Transit 350\n";
	}
};
class KiaSedona : public Minivan {
public:
	virtual void Show() {
		cout << "Shipping Minivan : Kia Sedona\n";
	}
};

class Bus  {
public:
	virtual void Show() {
		cout << "Shipping Bus \n";
	}
};
class Hungary : public Bus {
public:
	virtual void Show() {
		cout << "Shipping Bus : Hungary\n";
	}
};
class Belarus : public Bus {
public:
	virtual void Show() {
		cout << "Shipping Bus : Belarus\n";
	}
};

class Truck  {
public:
	virtual void Show() {
		cout << "Shipping Truck\n";
	}
};
class VolkswagenConstellation : public Truck {
public:
	virtual void Show() {
		cout << "Shipping Truck : Volkswagen Constellation\n";
	}
};
class ScaniaG460 : public Truck {
public:
	virtual void Show() {
		cout << "Shipping Truck : Scania G460\n";
	}
};

class Plane  {
public:
	virtual void Show() {
		cout << "Shipping Plane\n";
	}
};
class BoeingBusinessJets :public Plane {
public:
	virtual void Show() {
		cout << "Shipping Plane : Boeing Business Jets\n";
	}
};
class AirbusCorporateJets :public Plane {
public:
	virtual void Show() {
		cout << "Shipping Plane : Airbus Corporate Jets\n";
	}
};

class FactoryTransport 
{
public:
	virtual Car* GetCar() = 0;
	virtual Minivan* GetMinivan() = 0;
	virtual Bus* GetBus() = 0;
	virtual Truck* GetTruck() = 0;
	virtual Plane* GetPlane() = 0;
};

class SuitableTransport : public FactoryTransport 
{
public:
	void choise() {
		
		virtual Car* GetCar()
		{

		}
		virtual Minivan* GetMinivan()
		{

		}
		virtual Bus* GetBus()
		{

		}
		virtual Truck* GetTruck()
		{

		}
		virtual Plane* GetPlane()
		{

		}
	}
};

class Transport {
public:
	Car* car;
	Minivan* mini;
	Bus* bus;
	Truck* trc;
	Plane* pl;

	void Show() {
		car->Show();
		mini->Show();
		bus->Show();
		trc->Show();
		pl->Show();
	}
};

class ConfigTransport {
	FactoryTransport* factory;
public:
	ConfigTransport(FactoryTransport* f) {
		factory = f;
	}

	Transport CreateTransport() {
		Transport tr = Transport();
		tr.car = factory->GetCar();
		tr.mini = factory->GetMinivan();
		tr.bus = factory->GetBus();
		tr.trc = factory->GetTruck();
		tr.pl = factory->GetPlane();
		return tr;
	}
};

void main()
{
	int Lada = 4, BMW = 4, Ford = 4, Kia = 4, Hungary = 3, Belarus = 3, Volkswagen = 2, Scania = 2, Boeing = 1, Airbus = 1;
	
	ConfigTransport configPc2 = ConfigTransport(new SuitableTransport());
	Transport tr = configPc2.CreateTransport();
	tr.Show();

	float Term = 0, Volume = 0;
	cout << "Enter Term (days) :"; cin >> Term;
	cout << "Enter Volume (max:200) :"; cin >> Volume;



}

