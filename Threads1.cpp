#include <iostream>
#include <thread>

constexpr int V_EIGHT		{8};
constexpr int V_FIVE		{5};
constexpr int V_FOUR		{4};
constexpr int V_ONE		{1};
constexpr int V_ONE_HUNDRED	{100};
constexpr int V_SIX		{6};
constexpr int V_TEN		{10};
constexpr int V_THIRTY		{30};
constexpr int V_THREE		{3};
constexpr int V_TWENTY		{20};
constexpr int V_TWO		{2};
constexpr int V_ZERO		{};

class Counter
{
	private:
		int m_id{};
		int m_counter{};
		int m_num_Iters{};

	public:
		Counter() = default;
		Counter(const int& id) : m_id{id} {}
		Counter(const int& id, const int& num_Iters) : m_id{id}, m_num_Iters{num_Iters} {}

		void operator()() const
		{
			for (int idx{}; idx < m_num_Iters; idx++)
				std::cout << std::endl << "+ [" << m_id << "] = {" << idx << "}." << std::endl;
		}

		int operator()(const int& c)
		{
			return (m_counter += c);
		}

		void process()
		{
			std::cout << std::endl << "* Processing query: [" << m_id << "]. *" << std::endl;
		}
};

int k{};
thread_local int n{};

void functionThread(const int& id)
{
	std::cout << std::endl << "- Thread: [" << id << "] = {k = [" << k++ << "], n = [" << n++ << "]}." << std::endl;
}

void pile_up(const int& id, const int& numIters)
{
	for (int idx{}; idx < numIters; idx++)
		std::cout << "+ [" << id << "]\t=\t{" << idx << "}." << std::endl;
}

int main()
{
	std::cout << "Parallel multiple processing." << std::endl;

	Counter cont1 {};
	Counter cont2 {};
	Counter cont3 {V_FOUR, V_SIX};
	Counter cont4 {V_FIVE, V_THREE};
	Counter cont5 {V_ONE_HUNDRED};

	std::thread th_1 { pile_up, V_ONE, V_SIX };
	std::thread th_2 { pile_up, V_TWO, V_FOUR };
	std::thread th_3 { Counter {V_THREE, V_EIGHT} };
	std::thread th_4 { cont3 };
	std::thread th_5 { std::ref(cont4) };

	int id {V_SIX};
	int num_Iters {V_FIVE};

	std::thread th_6
	{
		[&id, &num_Iters] ()
		{
			for (int idx {V_ZERO}; idx < num_Iters; idx++)
				std::cout << "[" << id << "] = {" << idx++ << "}." << std::endl;
		}
	};

	std::thread th_7 {&Counter::process, &cont5};
	std::thread th_8 {functionThread, V_ONE};
	std::thread th_9 {functionThread, V_TWO};

	std::cout << std::endl << "Principal Threads." << std::endl;
	std::cout << "{" << cont1(V_TEN) << "}." << std::endl;
	std::cout << "{" << cont1(V_TWENTY) << "}." << std::endl;
	std::cout << "{" << cont2(V_THIRTY) << "}." << std::endl;
	std::cout << "{" << cont1(V_THIRTY) << "}." << std::endl;
	std::cout << "{" << cont2(V_TWENTY) << "}." << std::endl << std::endl;

	std::jthread job
	{
		[](std::stop_token my_token)
		{
			int counting {V_ZERO};

			while (!my_token.stop_requested())
			{
				std::cout << "#: <" << counting++ << ">." << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(V_ONE));
			}
		}
	};

	std::this_thread::sleep_for(std::chrono::seconds(V_THREE));
	job.request_stop();

	std::jthread work
	{
		[] (std::stop_token my_token)
		{
			int counting{};

			while (!my_token.stop_requested() && counting < V_TEN)
			{
				std::cout << "#: (" << counting++ << ")." << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(V_ONE));
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

	return V_ZERO;
}
