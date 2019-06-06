#pragma once

class BaseClass {
public:
	BaseClass() {
		data = new int[100];
	}

	~BaseClass() {
		if (data != nullptr) {
			delete[] data; data = nullptr;
		}
	}

	BaseClass(const BaseClass&) {
		if (data != nullptr) {
			
		}
	}

	virtual void DoSomething() = 0;

private:
	int* data;
};

class ClassB : public BaseClass {
public:
	ClassB() : BaseClass() {

	}

private:
	void DoWork();
};

class C {
public:


	C() {
		
	}
};
