
#include <iostream>
#include "assert.h"

//Template for singletn class
template <class T>
class SingleTon {
public:
	//function for creating an instance
	static T* CreateInstance() {
		assert(_instance == nullptr);
		if (_instance == nullptr)
			_instance = new T;
		return _instance;
	}
	//Return instance if is not null
	static T* GetInstace() {
		assert(_instance != nullptr);
		return _instance;
	}
	//Destroy instance
	static T* DestroyInstance() {
		delete _instance;
		_instance = nullptr;
	}
private:
	static T* _instance;
	//copy constructor unable to use
	SingleTon(SingleTon const&) = delete;
	//assingmnt operator unable to use 
	SingleTon& operator = (SingleTon const&) = delete;

protected:
	SingleTon() {}
	~SingleTon() {}

};

class Manager : public SingleTon<Manager> {
	friend class SingleTon<Manager>;
private:
	Manager() {};
};

Manager* SingleTon<Manager>::_instance = nullptr;

int main()
{
	//Creating it
	Manager *test = Manager::CreateInstance();
	
	//Getting Assert
	//Manager *test1 = Manager::GetInstace();

	//Can not create with pointer
	//Manager *a = new Manager();

	//Copy Opperator fo singleton
	//Manager test3 = test;

	//Copy constructor
	//Manager test4(test);

	//Instance using InputManager
	//Manager *test5 = Manager::CreateInstance();

	//Can not create instance using Manager
	//Manager test6;

	return 0;
}
