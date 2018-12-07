#include "mppch.h"

void Logger::init()
{
	spdlog::set_pattern("%n: %v%$");
	console = spdlog::stdout_color_mt("MASTER");
	console->set_level(spdlog::level::trace);
}
std::shared_ptr<spdlog::logger> Logger::console = nullptr;
void Logger::trace(std::string s)
{
	console->trace(s);
}
void Logger::info(std::string s)
{
	console->info(s);
}
void Logger::warn(std::string s)
{
	console->warn(s);
}
void Logger::error(std::string s)
{
	console->error(s);
}
void Logger::critical(std::string s)
{
	console->critical(s);
}