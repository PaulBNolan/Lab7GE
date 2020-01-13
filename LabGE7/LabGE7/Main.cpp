#include <iostream>
#include <thread>
#include <time.h>

int buf; 
int m_produced = 1; 
int m_consumed = 1; 
int m_limit = 10;

void producer()
{
	static int a = 0;

	std::cout << "Producer starting" << std::endl;

	while (m_produced < m_limit)
	{
		while (m_produced != m_consumed)
		{
			//	std::cout << "Short order cook spinning" << std::endl;
		}

		a = (int)rand() * 100;
		std::cout << "Making a burger: " << m_produced << std::endl;
		buf = a;
		m_produced = m_produced + 1;
	}
	std::cout << "Finished making burgers" << std::endl;
}

void consumer()
{
	static int b = 0;

	std::cout << "Consumer Starting" << std::endl;
	while (m_consumed < m_limit)
	{
		while (m_produced <= m_consumed)
		{
			//std::cout << "Starving waiting on a burger" + c << std::endl;
		}
		std::cout << "Eating Burger: " << m_consumed << std::endl;
		b = buf;
		m_consumed = m_consumed + 1;
	}
	std::cout << "Finished Eating Burgers" << std::endl;
}

int main()
{
	srand(time(NULL));

	std::thread m_producerThread(producer);
	std::thread m_consumerThread(consumer);

	m_producerThread.join();
	m_consumerThread.join();

	return 0;
}