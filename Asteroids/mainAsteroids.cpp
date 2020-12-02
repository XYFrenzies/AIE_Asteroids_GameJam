
#include "Application.h"
int main(int argc, char* argv[])
{
    {
        Application app;
        app.Startup();
        app.Run();
    }
    return 0;
}