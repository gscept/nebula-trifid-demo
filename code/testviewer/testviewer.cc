//------------------------------------------------------------------------------
//  testviewer.cc
//  (C) 2006 Radon Labs GmbH
//  (C) 2013-2014 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "testviewer/testviewerapplication.h"

ImplementNebulaApplication()

using namespace Tools;
using namespace Util;

//------------------------------------------------------------------------------
/**
*/
void
NebulaMain(const CommandLineArgs& args)
{
    TestViewerApplication app;
    app.SetCompanyName("gscept");
    app.SetAppTitle("Test Viewer");
    app.SetCmdLineArgs(args);
    if (app.Open())
    {
        app.Run();
        app.Close();
    }
    app.Exit();
}