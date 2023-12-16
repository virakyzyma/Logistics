#include <iostream>
#include <string>
using namespace std;

class Transport abstract
{
protected:
	string MaxDistance = "";
	string FuelConsumption = "";
	string MaxCapacity = "";
	string Price = "";
public:
	virtual void SetPrice() = 0;
	virtual void SetMaxCapacity() = 0;
	virtual void SetFuelConsumption() = 0;
	virtual void SetMaxDistance() = 0;
	void ShowTransport()
	{
		cout << "Price: " + Price + "\nMaxCapacity: " + MaxCapacity + "\nFuel Consumption: " + FuelConsumption + "\nMaximum Distance" + MaxDistance;
	}
};

class TruckTransport : public Transport
{
public:
	void SetPrice()override
	{
		Price = "1$/100 km";
	}
	void SetMaxCapacity()override
	{
		MaxCapacity = "180 kg";
	}
	void SetFuelConsumption()override
	{
		FuelConsumption = "10 litres/100 km";
	}
	void SetMaxDistance()override
	{
		MaxDistance = "900 km";
	}
};

class AirplaneTransport : public Transport
{
public:
	void SetPrice()override
	{
		Price = "10$/100 km";
	}
	void SetMaxCapacity()override
	{
		MaxCapacity = "400 kg";
	}
	void SetFuelConsumption()override
	{
		FuelConsumption = "6000 litres/100 km";
	}
	void SetMaxDistance()override
	{
		MaxDistance = "1500 km";
	}
};

class Creator abstract
{
public:
	virtual Transport* FactoryMethod() = 0;
};

class CreatorTruckTransport : public Creator
{
public:
	Transport* FactoryMethod()override
	{
		Transport* transport = new TruckTransport();
		transport->SetPrice();
		transport->SetMaxCapacity();
		transport->SetFuelConsumption();
		transport->SetMaxDistance();
		return transport;
	}
};

class CreatorAirplaneTransport : public Creator
{
public:
	Transport* FactoryMethod()override
	{
		Transport* transport = new AirplaneTransport();
		transport->SetPrice();
		transport->SetMaxCapacity();
		transport->SetFuelConsumption();
		transport->SetMaxDistance();
		return transport;
	}
};


void Factory(Creator** creators, int size)
{
	for (int i = 0; i < size; i++)
	{
		Transport* transport = creators[i]->FactoryMethod();
		transport->ShowTransport();
	}
}

void main()
{
	Creator* creators[2];
	creators[0] = new CreatorTruckTransport();
	creators[1] = new CreatorAirplaneTransport();
	Factory(creators, 2);

	system("pause");
}