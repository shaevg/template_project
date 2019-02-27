#include <iostream>
#include <libA/liba.h>
#include <chrono>
#include <thread>

using namespace std;

enum class State
{
	INIT,
	SECOND,
	ONE_MORE
};

void Trace(const char* str)
{
	cout << str << endl;
}

void TraceState(State state)
{
	switch (state)
	{
		case State::INIT:		Trace("INIT");		break;
		case State::SECOND:		Trace("SECOND");	break;
		case State::ONE_MORE:	Trace("ONE_MORE");	break;
	}
}

class StateMachine : public BaseStateMachine<State>
{
public:
	StateMachine();
};

State INIT_Perehod(State s)
{
	static unsigned int T = 2;

	if (T)
	{
		--T;
		return s;
	}

	return State::SECOND;
}

State SECOND_Perehod(State s)
{
	(void)s;
	return State::ONE_MORE;
}

State ONE_MORE_Perehod(State s)
{
	static unsigned int T = 1;

	if (T)
	{
		--T;
		return s;
	}

	T = 1;
	return State::SECOND;
}

void Upravlenie(State s)
{
	TraceState(s);
}


StateMachine::StateMachine()
{
	SetInitState(State::INIT);
	AddState(State::INIT, &INIT_Perehod, &Upravlenie);
	AddState(State::SECOND, &SECOND_Perehod, &Upravlenie);
	AddState(State::ONE_MORE, &ONE_MORE_Perehod, &Upravlenie);
}

int main()
{
	StateMachine s;

	for (int i = 0; i < 10; ++i)
	{
		this_thread::sleep_for(chrono::milliseconds(700));
		s.Tick();
	}

	return 0;
}
