// FactoryMathod.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string.h>
#include <string>

#pragma region 상위 클래스
class Project abstract
{
public:
	Project()
	{
	}

	~Project()
	{
	}

	virtual void Init() = 0;
private:
};
#pragma endregion
#pragma region 하위 클래스
class CProject : public Project
{
public:
	virtual void Init()
	{
		std::cout << "C 언어 생성" << std::endl;
	};
};
class CPlusProject : public Project
{
public:
	virtual void Init()
	{
		std::cout << "C++ 언어 생성" << std::endl;
	};
};
#pragma endregion

#pragma region 팩토리 클래스
class Factory
{
private:

public:
	Factory() {};
	~Factory() {};
	Project* Proj = nullptr;
	Project* CreateProJect(std::string name)
	{
		if (name == "C")
		{
			Proj = new CProject();
		}
		else if(name == "C++")
		{
			Proj = new CPlusProject();
		}
		else
		{
			std::cout << "그런 언어로 만들 수 없습니다."<<  std::endl;
		}
		return Proj;
	};
};
#pragma endregion

// 팩토리 메서드(FactoryMathod)는 추상화 클래스가 정보를 받고
// 하위 클래스에게 정보에 따른 제품의 생산을 맡기는 것.

// 장점 객체의 자료형이 하위 클래스 의해서 결정됨.

// 단점 객체가 늘어날 때마다 하위 클래스 재정의로 인한 불필요한 많은 클래스 생성 가능성이 있다.

int main()
{
	Factory F;
	Project* proj = F.CreateProJect("C");
	proj->Init();

	delete proj;

	Project* Proj = F.CreateProJect("C++");
	Proj->Init();

	delete Proj;

 
}

