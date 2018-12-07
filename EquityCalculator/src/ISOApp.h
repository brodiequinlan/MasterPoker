#pragma region HPP_FILE
#pragma once
// ISOApp.cpp
// Programmer: G. Santor
// Revised by: Ryker Munn
// Date of Last Revision: 2018-07-27
#include <cassert>
#include <string>
#include <deque>

class ISOApp {
	// TYPES 
public:
	using arg_list_type = std::deque<std::string>;

	// Attributes
private:
	arg_list_type args_;
	static ISOApp* singletonPtr_;

	// Operations	

private:
	friend int main(int argc, char* argv[]);
	static int main(int argc, char* argv[]);

protected:
	ISOApp();
	virtual ~ISOApp() {}
	arg_list_type const& args() const { return args_; }
	virtual int run() = 0;
};

#pragma endregion //HPP_FILE