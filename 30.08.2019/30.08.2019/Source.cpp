#include <iostream>
using namespace std;

//Processor 
class Processor
{
public:
	virtual void Show()
	{
		cout << "Proccessor\n";
	}
};

class IntelPr : public Processor
{
	virtual void Show()
	{
		cout << "Intel Proccessor\n";
	}
};

class AMDPr : public Processor
{
	virtual void Show()
	{
		cout << "AMD Proccessor\n";
	}
};

//MainBoard 
class MainBoard {
public:
	virtual void Show()
	{
		cout << "MainBoard\n";
	}
};

class ASUS : public MainBoard
{
	virtual void Show()
	{
		cout << "ASUS MainBoard\n";
	}
};

class GIGABYTE : public MainBoard
{
	virtual void Show()
	{
		cout << "GIGABYTE MainBoard\n";
	}
};

//Box
class Box {
public:
	virtual void Show()
	{
		cout << "Box\n";
	}
};

class Black : public Box
{
	virtual void Show()
	{
		cout << "Black Box\n";
	}
};

class Silver : public Box
{
	virtual void Show()
	{
		cout << "Silver Box\n";
	}
};

//Hdd
class Hdd {
public:
	virtual void Show()
	{
		cout << "Hdd\n";
	}
};

class Samsung : public Hdd
{
	virtual void Show()
	{
		cout << "Samsung Hdd\n";
	}
};

class LG : public Hdd
{
	virtual void Show()
	{
		cout << "LG Hdd\n";
	}
};

//Memory
class Memory {
public:
	virtual void Show()
	{
		cout << "Memory\n";
	}
};

class Ddr2 : public Memory
{
	virtual void Show()
	{
		cout << "Ddr2 Memory\n";
	}
};

class Ddr : public Memory
{
	virtual void Show()
	{
		cout << "Ddr Memory\n";
	}
};

//
class FactoryPC
{
public:
	virtual Processor* GetProcessor() = 0;
	virtual MainBoard* GetMainBoard() = 0;
	virtual Box* GetBox() = 0;
	virtual Hdd* GetHdd() = 0;
	virtual Memory* GetMemory() = 0;
};

class HomeFactory : public FactoryPC
{
public:
	virtual Processor* GetProcessor()
	{
		return new IntelPr();
	}
	virtual MainBoard* GetMainBoard()
	{
		return new ASUS();
	}
	virtual Box* GetBox()
	{
		return new Black();
	}
	virtual Hdd* GetHdd()
	{
		return new LG();
	}
	virtual Memory* GetMemory()
	{
		return new Ddr2;
	}
};

class OfficeFactory : public FactoryPC
{
public:
	virtual Processor* GetProcessor()
	{
		return new AMDPr();
	}
	virtual MainBoard* GetMainBoard()
	{
		return new GIGABYTE();
	}
	virtual Box* GetBox()
	{
		return new Silver();
	}
	virtual Hdd* GetHdd()
	{
		return new Samsung();
	}
	virtual Memory* GetMemory()
	{
		return new Ddr;
	}
};


class PC
{
public:
	Processor* pr;
	MainBoard* mb;
	Box* box;
	Hdd* hdd;
	Memory* mmr;
	// memory

	void Show()
	{
		pr->Show();
		mb->Show();
		box->Show();
		hdd->Show();
		mmr->Show();
	}
};

class ConfigPC
{

	FactoryPC* factory;

public:
	ConfigPC(FactoryPC* f)
	{
		factory = f;
	}

	PC CreatePC()
	{
		PC pc = PC();
		pc.pr = factory->GetProcessor();
		pc.mb = factory->GetMainBoard();
		pc.box = factory->GetBox();
		pc.hdd = factory->GetHdd();
		pc.mmr = factory->GetMemory();
		// memory
		return pc;
	}
};

void main()
{

	ConfigPC configPc = ConfigPC(new HomeFactory());
	
	PC pc = configPc.CreatePC();
	cout << "\n\t\t\tHome PC Factory" << endl;
	pc.Show();
	
	ConfigPC configPc2 = ConfigPC(new OfficeFactory());

	PC pc2 = configPc2.CreatePC();
	cout << "\n\t\t\tOffice PC Factory" << endl;
	pc2.Show();

	system("pause");

}