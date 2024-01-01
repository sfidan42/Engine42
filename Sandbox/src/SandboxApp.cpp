#include <Engine42.h>

class Sandbox : public Engine42::Application
{
public:
	Sandbox(void) {}
	~Sandbox(void) {}
};

Engine42::Application* Engine42::CreateApplication(void)
{
	return (new Sandbox());
}
