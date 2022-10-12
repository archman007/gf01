/***************************************************************
 * Name:      gf01App.cpp
 * Purpose:   Code for Application Class
 * Author:    Mr. Arch Brooks (arch@archbrooks.com)
 * Created:   2022-10-09
 * Copyright: Mr. Arch Brooks (https://archbrooks.us/b4)
 * License:
 **************************************************************/

#include "gf01App.h"

//(*AppHeaders
#include "gf01Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(gf01App);

bool gf01App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	gf01Frame* Frame = new gf01Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
