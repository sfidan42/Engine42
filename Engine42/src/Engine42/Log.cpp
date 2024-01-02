#include "Log.h"

namespace Engine42
{
	std::shared_ptr<spdlog::logger>	Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger>	Log::s_ClientLogger;

	void Log::Init(void)
	{
		s_CoreLogger = spdlog::stdout_color_mt("ENGINE42");
		s_ClientLogger = spdlog::stdout_color_mt("SANDBOX");
		s_CoreLogger->set_pattern("[%n]> %H:%M:%S %z [%^%l%$]:\t%v");
		s_ClientLogger->set_pattern("[:%n]> %H:%M:%S %z [%^%l%$]:\t%v");
		s_CoreLogger->set_level(spdlog::level::trace);
		s_ClientLogger->set_level(spdlog::level::trace);
	}

	std::shared_ptr<spdlog::logger>& Log::getCoreLogger(void) { return (s_CoreLogger); }
	std::shared_ptr<spdlog::logger>& Log::getClientLogger(void)	{ return (s_ClientLogger); }
}
