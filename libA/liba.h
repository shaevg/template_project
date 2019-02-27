#ifndef LIBA_H
#define LIBA_H

#include <map>

template<class T>
class BaseStateMachine
{
private:
	struct Phase
	{
		T(*transition_logic)(T);
		void (*action)(T);
		Phase(decltype(transition_logic) trans, decltype(action) act)
		{
			transition_logic = trans;
			action = act;
		}
	};

	bool _ready;

	T _state;
	std::map<T, Phase> _machine;

protected:
	void SetInitState(T state)
	{
		_state = state;
		_ready = true;
	}

	void AddState(T t,decltype(Phase::transition_logic) perehod,decltype (Phase::action) upravlenie)
	{
		_machine.insert(std::pair<T,Phase>(t, Phase(perehod, upravlenie)));
	}

public:
	BaseStateMachine() : _ready(false)
	{

	}

	void Tick()
	{
		if (_ready)
		{
			// Call transmition logic
			{
				auto current_phase = static_cast<const Phase&>(_machine.at(_state));
				_state = (*(current_phase.transition_logic))(_state);
			}

			// Call action
			{
				auto new_phase = static_cast<const Phase&>(_machine.at(_state));
				(*(new_phase.action))(_state);
			}
		}
	}
};

#endif // LIBA_H
