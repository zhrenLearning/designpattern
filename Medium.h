#include <iostream>

using namespace std;

class Medium;

class Involvement
{
public:
	Involvement(Medium *pMedium) : m_pMedium(pMedium){}

	virtual void SayAnything(wchar_t *anything) = 0;

protected:
	Medium *m_pMedium;
};

class SmileInvolvement : public Involvement
{
public:
	SmileInvolvement(Medium *pMedium) : Involvement(pMedium) {}

	void SayAnything(wchar_t *anything);

	void Smile(wchar_t *anything)
	{
		cout << anything << endl;
	}
};


class CryInvolvement : public Involvement
{
public:
	CryInvolvement(Medium *pMedium) : Involvement(pMedium){}

	void SayAnything(wchar_t *anything);

	void Cry(wchar_t *anything)
	{
		cout << anything << endl;
	}
};

class Medium
{
public:
	virtual void Exchange(wchar_t *anything, Involvement *pInvolvement) = 0;

};

class MainMedium : public Medium
{
public:
	void Exchange(wchar_t *anything, Involvement *pInvolvement)
	{
		SmileInvolvement *pSmileInvolvement = dynamic_cast<SmileInvolvement *>(pInvolvement);
		if (pSmileInvolvement)
		{
			if (m_pCryInvolvement)
			{
				m_pCryInvolvement->Cry(anything);
			}
		}
		else
		{
			if (m_pSmileInvolvement)
			{
				m_pSmileInvolvement->Smile(anything);
			}
		}
	}

	void SmileCorrelation(Involvement *pInvolvement)
	{
		m_pSmileInvolvement = dynamic_cast<SmileInvolvement *>(pInvolvement);
	}

	void CryCorrelation(Involvement *pInvolvement)
	{
		m_pCryInvolvement = dynamic_cast<CryInvolvement *>(pInvolvement);
	}

private:
	SmileInvolvement *m_pSmileInvolvement;
	CryInvolvement *m_pCryInvolvement;
};

void SmileInvolvement::SayAnything(wchar_t *anything)
{
	m_pMedium->Exchange(anything, this);
}

void CryInvolvement::SayAnything(wchar_t *anything)
{
	m_pMedium->Exchange(anything, this);
}

int main()
{
	Medium *pMedium = new MainMedium();

	SmileInvolvement *pSmileInvolvement = new SmileInvolvement(pMedium);
	CryInvolvement *pCryInvolvement = new CryInvolvement(pMedium);

	MainMedium *pMainMedium = dynamic_cast<MainMedium *>(pMedium);
	pMainMedium->SmileCorrelation(pSmileInvolvement);
	pMainMedium->CryCorrelation(pCryInvolvement);

	wchar_t p[128] = L"My frist design pattern code test !";
	pSmileInvolvement->SayAnything(p);

	return 0;
}



