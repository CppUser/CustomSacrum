include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

workspace "Sacrum"
	architecture "x86_64"
	startproject "Sacrum"

	configurations
	{
		"Debug",
		"Release",
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "vendor/premake"
	include "Engine/tplib/Box2D"
	include "Engine/tplib/GLFW"
	include "Engine/tplib/Glad"
	include "Engine/tplib/imgui"
group ""

include "Engine"
include "Sacrum"
