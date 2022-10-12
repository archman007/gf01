/***************************************************************
 * Name:      gf01Main.h
 * Purpose:   Defines Application Frame
 * Author:    Mr. Arch Brooks (arch@archbrooks.com)
 * Created:   2022-10-09
 * Copyright: Mr. Arch Brooks (https://archbrooks.us/b4)
 * License:
 **************************************************************/

#ifndef GF01MAIN_H
#define GF01MAIN_H

using namespace std;


//(*Headers(gf01Frame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class gf01Frame: public wxFrame
{
    public:

        gf01Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~gf01Frame();
        string rselProj;

    private:

        //(*Handlers(gf01Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnmenNewBlogPostSelected(wxCommandEvent& event);
        void OnmenSelectDlgSelected(wxCommandEvent& event);
        void OnmenListFilesSelected(wxCommandEvent& event);
        void OnmenFindAllFilesSelected(wxCommandEvent& event);
        //*)

        //(*Identifiers(gf01Frame)
        static const long ID_MENUITEM1;
        static const long ID_MENUITEM2;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(gf01Frame)
        wxMenuItem* menNewBlogPost;
        wxMenuItem* menSelectDlg;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // GF01MAIN_H
