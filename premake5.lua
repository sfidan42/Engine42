workspace "Engine42"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
	startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


project "Engine42"
	location "Engine42"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
			 "E42_PLATFORM_WINDOWS",
			 "E42_BUILD_DLL"
		}

	filter "configurations:Debug"
		defines "E42_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "E42_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "E42_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
		
	}

	includedirs
	{
		"Engine42/vendor/spdlog/include",
		"Engine42/src"
	}

	links
	{
		"Engine42"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
			 "E42_PLATFORM_WINDOWS",
		}

	prebuildcommands
	{
		("{COPY} ../bin/" .. outputdir .. "/Engine42/Engine42.dll ../bin/" .. outputdir .. "/Sandbox")
	}

	filter "configurations:Debug"
		defines "E42_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "E42_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "E42_DIST"
		optimize "On"
