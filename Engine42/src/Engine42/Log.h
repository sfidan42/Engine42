#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
namespace Engine42
{
	class E42_API Log
	{
	private:
		static std::shared_ptr<spdlog::logger>	s_CoreLogger;
		static std::shared_ptr<spdlog::logger>	s_ClientLogger;
	public:
		static void Init(void);
		inline static std::shared_ptr<spdlog::logger>& getCoreLogger(void);
		inline static std::shared_ptr<spdlog::logger>& getClientLogger(void);
	};
}

# define ENGINE_TRACE(...) { Engine42::Log::getCoreLogger()->trace(__VA_ARGS__); }
# define ENGINE_INFO(...) { Engine42::Log::getCoreLogger()->info(__VA_ARGS__); }
# define ENGINE_WARN(...) { Engine42::Log::getCoreLogger()->warn(__VA_ARGS__); }
# define ENGINE_ERROR(...) { Engine42::Log::getCoreLogger()->error(__VA_ARGS__); }
# define ENGINE_FATAL(...) { Engine42::Log::getCoreLogger()->critical(__VA_ARGS__); }

# define APP_TRACE(...) { Engine42::Log::getClientLogger()->trace(__VA_ARGS__); }
# define APP_INFO(...) { Engine42::Log::getClientLogger()->info(__VA_ARGS__); }
# define APP_WARN(...) { Engine42::Log::getClientLogger()->warn(__VA_ARGS__); }
# define APP_ERROR(...) { Engine42::Log::getClientLogger()->error(__VA_ARGS__); }
# define APP_FATAL(...) { Engine42::Log::getClientLogger()->critical(__VA_ARGS__); }
