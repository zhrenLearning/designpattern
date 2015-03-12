#include <iostream>
using namespace std;

class SingletonOne
{
public:
	static SingletonOne * GetInstance()
	{
		if (m_Instance == NULL)
			//Lock Thread
			m_Instance = new SingletonOne();
		//UnLock Thread
		return m_Instance;
	}

	static void DistoryInstance()
	{
		if (m_Instance != NULL)
		{
			delete m_Instance;
			m_Instance = NULL;
		}
	}

	void * GetResult()
	{
		return (void *)(m_Instance);
	}

private:
	SingletonOne() {};
	static SingletonOne *m_Instance;
};

//Before using, initialization static variant
SingletonOne * SingletonOne::m_Instance = NULL;


class SingletonTwo
{
public:
	static SingletonTwo * GetInstance()
	{
		return const_cast<SingletonTwo *>(m_Instance);
	}

	static void DistoryInstance()
	{
		if (m_Instance == NULL)
		{
			delete m_Instance;
			m_Instance = NULL;
		}
	}

	void * GetResult()
	{
		return (void *)(m_Instance);
	}

private:
	SingletonTwo() {}
	static const SingletonTwo *m_Instance;
};

//before using initialization static variant
const SingletonTwo *SingletonTwo::m_Instance = new SingletonTwo();

class SingletonThree
{
public:
	static SingletonThree *GetInstance()
	{
		static SingletonThree m_Instance;
		return &m_Instance;
	}

	void * GetResult()
	{
		return (void *)(m_Instance);
	}

private:
	SingletonThree(){}
	static SingletonFour *m_Instance;
};

class SingletonFour
{
public:
	static SingletonFour * GetInstance()
	{
		return m_Instance;
	}

	void * GetResult()
	{
		return (void *)(m_Instance);
	}

private:
	SingletonFour(){}
	static SingletonFour *m_Instance;

	class Clean
	{
	public:
		~Clean()
		{
			if (m_Instance != NULL)
			{
				delete m_Instance;
				m_Instance = NULL;
			}
		}
	};

	static Clean clean;
};

//before using initialization variant
SingletonFour * SingletonFour::m_Instance = new SingletonFour();
SingletonFour::Clean SingletonFour::clean;
