#include "CoreLink.h"
#include <Core/Entry.h>

class Sacrum : public EngineCore
{
public:
    Sacrum(const WindowSpecs& specs) : EngineCore(specs)
    {
    }
};


EngineCore* Create(int argc, char** argv)
{
    WindowSpecs specs;
    specs.Title = "Sacrum";
    specs.Width = 1920;
    specs.Height = 1080;

    return new EngineCore(specs);
}