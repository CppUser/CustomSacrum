--VULKAN_SDK = os.getenv("VULKAN_SDK")

IncludeDir = {}
IncludeDir["stb_image"] = "%{wks.location}/Engine/tplib/stb_image"
IncludeDir["Box2D"] = "%{wks.location}/Engine/tplib/Box2D/include"
IncludeDir["GLFW"] = "%{wks.location}/Engine/tplib/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Engine/tplib/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Engine/tplib/ImGui"
IncludeDir["glm"] = "%{wks.location}/Engine/tplib/glm"
IncludeDir["entt"] = "%{wks.location}/Engine/tplib/entt/include"

LibraryDir = {}


Library = {}
