// Singleton Pattern.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
#pragma region 싱글톤 클래스
//싱글톤이란 클래스를 전역변수와 비슷하게 만들어 주는것을 의미한다.
template <typename T>
class singleton
{
private:
	//클래스 내부 변수에 static을 사용하게 되면
	//클래스를 따로 만들지 않아도 변수가 먼저 만들어지게 된다.
	static T* p;
public:
	singleton() {};
	virtual ~singleton() {};

	//함수에 static을 사용하게 되면
	//클래스가 없어도 클래스이름만으로 함수를 사용할수 있게 된다
	static T* GetInstance()
	{
		if (!p)
			p = new T;
		return p;
	}
	static void ReleaseInstance()
	{
		if (p)
			delete p;
		p = nullptr;
	}
	
};
template <typename T>
T* singleton<T>::p = nullptr;
//스태틱 변수는 내부에선 초기화를 못하고, 클래스 외부에서 한번 초기화 해주어야 한다
#pragma endregion
#pragma region 싱글톤을 쓸 클래스
class Image : public singleton<Image>
{
public:
	Image()
	{

	};
	~Image() 
	{

	};

	void Render() { std::cout << "이미지 출력" << std::endl; };
};
#define IMAGE Image::GetInstance()
#pragma endregion


// 싱글톤 패턴(Singleton Pattern)은 이 싱클톤 클래스를 상속받게 되면,
// 그 클래스는 전역 변수와 비슷하게 사용할수 있다.

// 장점
// 전역변수처럼 사용할수 있어 이미지 관리나 사운드 관리등 매우 편리하게 관리할수있다.

// 단점 
// 일반 클래스에 비해 느리며 객체 지향을 무시하는 방법으로 꼭 필요하지 않으면 사용하지 않는것이 좋다.


int main()
{
	// 어느곳에서든 사용할수 있다. 
	IMAGE->Render();
	
	Image::ReleaseInstance();
}

