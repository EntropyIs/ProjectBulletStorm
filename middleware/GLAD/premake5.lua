project "GLAD"
	kind "StaticLib"
	language "C"

	targetdir("bin/" .. outputDir .. "/%{prj.name}")
	objdir("obj/" .. outputDir .. "/%{prj.name}")

	files
	{
		"include/glad/glad.h",
		"include/KHR/khrplatform.h",
		"src/glad.c"
	}

	includedirs
	{
		"include"
	}

	filter "system:windows"
	systemversion "latest"
	staticruntime "On"

	filter "configurations:Debug"
		runtime "Debug"
		buildoptions "/MDd"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		buildoptions "/MD"
		optimize "on"

	