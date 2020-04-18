// State pattern.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#pragma region 상태 인터페이스 클래스
class State abstract
{
public:
	virtual void execute() = 0;
};
#pragma endregion

#pragma region 하위 클래스
class Attack : public State
{
public: 
	virtual void execute() override
	{
		std::cout << "공격" << std::endl;
	};
};
class Move : public State
{
public:
	virtual void execute() override
	{
		std::cout << "이동" << std::endl;
	};
};

#pragma endregion

#pragma region 몬스터 클래스
class Monster: public State
{
private:
	State* m_state;
public:
	Monster(State* state)
		:m_state(state) {};

	~Monster()
	{
		if (m_state != NULL)
			delete m_state;
	};

	void StateExecute(State* state)
	{
		m_state = state;
	};
	void execute()
	{
		m_state->execute();
	};
};
#pragma endregion


// 상태 패턴(Singleton Pattern)은 객체의 상태에 따라 
// 각각의 행위를 변경할 수 있게 캡슐화 한다.
// 동적으로 행동을 교체 할수 있다


// 장점
// 지저분한 조건문이 사라진다. 이해하기 좋은 코드 베이스와 클래스 구조 생성.

// 단점 
// 이용하다보면 디자인에 필요한 class 갯수가 늘어난다.


int main()
{
	Monster* monster = new Monster(new Attack());
	monster->execute();

	monster->StateExecute(new Move());
	monster->execute();

	delete monster;
    //std::cout << "Hello World!\n";
}

