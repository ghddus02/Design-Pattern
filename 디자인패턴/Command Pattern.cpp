
#include <iostream>
#include <Windows.h>
#pragma region 전역 함수 

void RightMove()
{
	std::cout << "오른쪽 이동" << std::endl;
}

void LeftMove()
{
	std::cout << "왼쪽 이동" << std::endl;
}
#pragma endregion
//공통 상위 클래스 
#pragma region 공통 상위 클래스
class Command abstract
{
public:

	virtual void execute() = 0;

};
#pragma endregion
//인터페이스에 반환 값이 없는 메서드 하나밖에 없다면 명령 패턴일 가능성이 높다.
// 이제 각 행동별로 하위 클래스를 만든다. 오른쪽,왼쪽
#pragma region 각 행동별 하위 클래스
class RightCommand : public Command
{
public:
	virtual void execute() override { RightMove(); }
};
class LeftCommand : public Command
{
public:
	virtual void execute() override { LeftMove(); };
};

#pragma endregion

class Input
{
private:
	//인자
	Command* Right_Button;
	Command* left_Button;
public:
	// 동적할당 부분
	Input()
	{
		Right_Button = new RightCommand();
		left_Button = new LeftCommand();
	};
	// 해제 부분 
	~Input()
	{
		delete Right_Button;
		delete left_Button;
	};
	void Update()
	{
		if (GetAsyncKeyState(VK_RIGHT)) Right_Button->execute();
		if (GetAsyncKeyState(VK_LEFT)) left_Button->execute();
	};

};


// 커맨드 패턴(Command Pattern)은  요청을 객체의 형태로 캡슐화 하여 
// 사용자가 보낸 요청을 나중에 이용할 수 있도록 매서드 이름,매개변수 등
// 요청에 필요한 정보를 저장 또는 로깅,취소할 수 있게 하는 패턴이다.

// 장점
// 코드가 객체화 되어 수정하기 수월하다.

// 단점 
// 많은 클래스 작성,관리,복잡도,가 커진다는 단점이 있다.

int main()
{
	Input m_Input;

	while (!GetAsyncKeyState(VK_ESCAPE))
	{
		m_Input.Update();
	}

	return false;
}