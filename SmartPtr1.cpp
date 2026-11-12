#include <iostream>
#include <memory>

#define	V_TWO_H	200
#define	V_FORTY	40
#define V_ZERO  0

template <typename T, typename U>
struct Enemy
	{
		private:
			T attackPower {V_ZERO};
			U health {V_ZERO};

		protected:
			static std::size_t counter;

		public:
			Enemy()												{this->counter++;}
			Enemy(T _attackPower, U _health)  : attackPower(_attackPower), health(_health)			{Enemy::counter++;}
			Enemy(const Enemy<T, U>& _enemy)  : attackPower(_enemy.attackPower), health(_enemy.health)	{(*this).counter++;}
			Enemy(const Enemy<T, U>&& _enemy) : attackPower(_enemy.attackPower), health(_enemy.health)
				{this->counter++; _enemy.attackPower = V_ZERO; _enemy.health = V_ZERO;}

			Enemy<T, U>& operator=(const Enemy<T, U>& _enemy)
				{attackPower = _enemy.attackPower; health = _enemy.health;}
			Enemy<T, U>& operator=(const Enemy<T, U>&& _enemy)
				{attackPower = _enemy.attackPower; health = _enemy.health; _enemy.attackPower = V_ZERO; _enemy.health = V_ZERO;}

			const T& getAttackPower() const     {return attackPower;}
			T& getAttackPower()                 {return attackPower;}

			const size_t& getCounter() const    {return counter;}

			const U& getHealth() const          {return health;}
			U& getHealth()                      {return health;}

			void setAttackPower(const T& _attackPower = V_ZERO) {this->attackPower = _attackPower;}
			void setHealth(const U& _health = V_ZERO)           {(*this).health = _health;}

			virtual ~Enemy()                    {(*this).counter--;}
	};

template<typename T, typename U>
std::size_t Enemy<T, U>::counter {V_ZERO};

int main()
	{
		std::unique_ptr<Enemy<int, short>> boss {std::make_unique<Enemy<int, short>>(V_TWO_H, V_FORTY)};

		std::cout << "Use of Smart Pointers." << std::endl;

		std::cout << std::endl << "Counter: " << (*boss).getCounter() << std::endl;
		std::cout << "Pointer: " << boss.get() << std::endl;
		std::cout << "Boss Health: " << (*boss).getHealth() << std::endl;
		std::cout << "Boss Attack Power: " << (*boss).getAttackPower() << std::endl;

		boss->getAttackPower() = V_FORTY;
		boss->getHealth() = V_TWO_H;

		std::cout << std::endl << "Counter: " << (*boss).getCounter() << std::endl;
		std::cout << "Pointer: " << boss.get() << std::endl;
		std::cout << "Boss Health: " << (*boss).getHealth() << std::endl;
		std::cout << "Boss Attack Power: " << (*boss).getAttackPower() << std::endl;

		std::cout << std::endl << "Done!" << std::endl;
		std::cout << "This program has ended." << std::endl;

		return EXIT_SUCCESS;
	}
