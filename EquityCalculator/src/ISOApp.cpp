#pragma region CPP_FILE
#include <Master.h>
#include "ISOApp.h"
#include <cassert>
#include <iostream>
#pragma region ISOApp_utility

int main(int argc, char* argv[]) try
{
	return ISOApp::main(argc, argv);
}
catch (std::exception& e)
{
	Logger::error(e.what());
	return EXIT_FAILURE;
}
catch (std::string e)
{
	Logger::warn(e);
}
catch (...)
{
	Logger::critical("Unknown error");
	return EXIT_FAILURE;
}

#pragma endregion

#pragma region ISOApp_class

ISOApp* ISOApp::singletonPtr_ = nullptr;

ISOApp::ISOApp() {
	assert(singletonPtr_ == nullptr && "ISOApp::singletonPtr_ has already been initialized.");
	singletonPtr_ = this;
}

int ISOApp::main(int argc, char* argv[]) {
	assert(singletonPtr_ && "ISOApp::singletonPtr_ not initialized.");
	singletonPtr_->args_.clear();
	for (int i = 1; i < argc; ++i) {
		singletonPtr_->args_.push_back(argv[i]);
	}

	return singletonPtr_->run();
}

#pragma endregion
#pragma endregion // CPP_FILE