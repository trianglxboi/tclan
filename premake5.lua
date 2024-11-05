workspace "tclan"
	architecture "x64"
	configurations {
		"devel",
		"dist"
	}
	startproject "tclan"

project "tclan"
	location "."
	language "c++"
	cppdialect "c++17"
	kind "consoleapp"

	targetdir "bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	objdir    "bin-obj/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	pchheader "clanpch.hh"
	pchsource "src/clanpch.cc"

	files {
		"src/**.hh",
		"src/**.cc"
	}

	includedirs {
		"src"
	}

	filter "system:windows"
		systemversion "latest" -- WinSDK version
		defines {
			"TC_PLATFORM_WINDOWS"
		}
		
	filter "system:linux"
		defines {
			"TC_PLATFORM_LINUX"
		}

	filter "configurations:devel"
		runtime "debug"
		symbols "on"
		defines {
			"TC_DEVEL"
		}

	filter "configurations:dist"
		runtime "release"
		optimize "speed"
		defines {
			"TC_DIST"
		}
