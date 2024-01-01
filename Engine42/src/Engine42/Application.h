#pragma once
#include "Core.h"

namespace Engine42
{
	class E42_API Application
	{
	public:
		Application(void);
		~Application(void);
		void	Run(void);
	};
	
	Application* CreateApplication(void);
};

