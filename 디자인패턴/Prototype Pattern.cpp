// Prototype Pattern.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

enum ITEM
{
	WEAPON,
	ARMOR,
};

#pragma region 아이템 상위 클래스
class Item abstract
{
protected:
	Item* m_item;
public:
	Item() {};
	~Item() {};
	virtual Item* CrateClone() = 0;
};
#pragma endregion

#pragma region 아이템 하위 클래스
class Weapon : public Item
{
public:
	Weapon()
	{
	};
	~Weapon()
	{
	};

	virtual Item* CrateClone() override
	{
		std::cout << "무기 생성" << std::endl;
		return m_item;
	};
};
class Armor : public Item
{
public:
	Armor()
	{
	};
	~Armor()
	{
	};

	virtual Item* CrateClone() override
	{
		std::cout << "방어구 생성" << std::endl;
		return m_item;
	};
};
#pragma endregion

#pragma region 팩토리 클래스
class Item;
class Weapon;
class Armor;
class PrototypeFactory
{
private:
	std::vector<Item*> ItemList;
public:
	PrototypeFactory()
	{
		ItemList.push_back(new Weapon);
		ItemList.push_back(new Armor);
	};
	~PrototypeFactory()
	{

	};

	Item * CreateItem(int number)
	{
		return ItemList[number]->CrateClone();
	};
};
#pragma endregion

// 프로토타입 팩토리 패턴(Prototype Pattern)은 어떤 객체의 유사객체를 생성할때 
// 기존의 것을 이용하여 편의를 돕는 것
// 팩토리 메소드 패턴 과 반대로 객체의 생성을 상위 클래스에서 처리함.

// 장점
// 조건문을 객체를 생성해 주기 위한 별도의 객체 생성 클래스가 불필요 하다는점과.
// 객체의 각 부분을 조합해서 생성되는 형태에도 적용 가능하다. 쓰는것이 좋다고 생각한다.

// 단점 
// 생성될 객체들의 자료형인 클래스들이 clone() 메서드를 구현해야 한다.


int main()
{
	PrototypeFactory F;

	F.CreateItem(ITEM::WEAPON);
	F.CreateItem(ITEM::ARMOR);
}

