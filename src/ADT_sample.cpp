
#include <iostream>

#define DEFAULT_FARE 1000

class CPerson
{
public:
	CPerson() { }
	virtual ~CPerson()
	{
		std::cout << "virtual ~CPerson()" << std::endl;
	}

	virtual void CalcFare() = 0;

	virtual unsigned int GetFare() { return m_nFare; }

protected:
	unsigned int m_nFare;
};

class CBaby : public CPerson
{
public:
	virtual void CalcFare()
	{
		m_nFare = 0;
	}
};

class CChild : public CPerson
{
public:
	virtual void CalcFare()
	{
		m_nFare = DEFAULT_FARE * 50 / 100;;
	}
};

class CTeen : public CPerson
{
public:
	virtual void CalcFare()
	{
		m_nFare = DEFAULT_FARE * 75 / 100;;
	}
};

class CAdult : public CPerson
{
public:
	virtual void CalcFare()
	{
		m_nFare = DEFAULT_FARE;
	}
};

int	main(void)
{
	CPerson	*arList[3] = { 0 };
	int nAge = 0;

	for (int i = 0; i < 3; ++i)
	{
		std::cout << "> Age: ";
		std::cin >> nAge;
		if (nAge < 8)
			arList[i] = new CBaby;
		else if (nAge < 14)
			arList[i] = new CChild;
		else if (nAge < 20)
			arList[i] = new CTeen;
		else
			arList[i] = new CAdult;

		arList[i]->CalcFare();
	}

	for (int i = 0; i < 3; ++i)
		std::cout << arList[i]->GetFare() << "$" << std::endl;

	for (int i = 0; i < 3; ++i)
		delete arList[i];

	return 0;
}

