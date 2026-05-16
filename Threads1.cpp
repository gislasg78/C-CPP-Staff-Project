#include <iostream>
#include <thread>

class Consultation
{
	private:
		int m_id{};

	public:
		Consultation(const int& id) : m_id{id} {}

		void process()
		{
			std::cout << "Processing query: [" << m_id << "]." << std::endl;
		}
};

class Count
{
	private:
		int m_id{};
		int m_num_Iters{};

	public:
		Count(const int& id, const int& num_Iters) : m_id{id}, m_num_Iters{num_Iters} {}

		void operator()() const
		{
			for (int idx{}; idx < m_num_Iters; idx++)
				std::cout << "[" << m_id << "] = {" << idx << "}." << std::endl;
		}
};

class Counter
{
	private:
		int m_counter{};

	public:
		int operator() (const int& c)
		{
			return (m_counter += c);
		}
};

void pile_up(const int& id, const int& numIters)
{
	for (int idx{}; idx < numIters; idx++)
		std::cout << "+ [" << id << "]\t=\t{" << idx << "}." << std::endl;
}

int k{};
thread_local int n{};

void functionThread(const int& id)
{
	std::cout << "Thread: [" << id << "] = {k = [" << k << "], n = [" << n << "]}." << std::endl;
	++k;
	++n;
}

int main()
{
	std::cout << "Parallel multiple processing." << std::endl;

	Counter cont1{};
	Counter cont2{};

	std::thread th_1 {pile_up, 1, 6};
	std::thread th_2 {pile_up, 2, 4};

	std::thread th_3 { Count {3, 8} };

	Count c1 {4, 6};
	std::thread th_4 {c1};

	Count c2 {5, 3};
	std::thread th_5 {std::ref(c2)};

	int id{6};
	int num_Iters{5};

	std::thread th_6
	{
		[&id, &num_Iters] ()
		{
			for (int idx{0}; idx < num_Iters; idx++)
				std::cout << "[" << id << "] = {" << idx++ << "}." << std::endl;
		}
	};

	Consultation cons{100};

	std::thread th_7 {&Consultation::process, &cons};

	std::thread th_8 {functionThread, 1};
	std::thread th_9 {functionThread, 2};

	std::cout << "{" << cont1(10) << "}." << std::endl;
	std::cout << "{" << cont1(20) << "}." << std::endl;
	std::cout << "{" << cont2(30) << "}." << std::endl;
	std::cout << "{" << cont1(30) << "}." << std::endl;
	std::cout << "{" << cont2(20) << "}." << std::endl;


	std::jthread job
	{
		[](std::stop_token my_token)
		{
			int counting{0};

			while (!my_token.stop_requested())
			{
				std::cout << "#: [" << counting++ << "]." << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
		}
	};

	std::this_thread::sleep_for(std::chrono::seconds(5));
	job.request_stop();


	std::jthread work
	{
		[] (std::stop_token my_token)
		{
			int counting{};

			while (!my_token.stop_requested() && counting < 10)
			{
				std::cout << "#: " << counting++ << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
		}
	};

	work.join();

	th_1.join();
	th_2.join();
	th_3.join();
	th_4.join();
	th_5.join();
	th_6.join();
	th_7.join();
	th_8.join();
	th_9.join();
	
	return 0;
}
