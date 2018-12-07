#include "spdlog/spdlog.h"
class Logger
{
	static std::shared_ptr<spdlog::logger> console;
public:
	static void init();

	static void trace(std::string s);
	static void info(std::string s);
	static void warn(std::string s);
	static void error(std::string s);
	static void critical(std::string s);
};