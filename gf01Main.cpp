/***************************************************************
 * Name:      gf01Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Mr. Arch Brooks (arch@archbrooks.com)
 * Created:   2022-10-09
 * Copyright: Mr. Arch Brooks (https://archbrooks.us/b4)
 * License:
 **************************************************************/

#include "gf01Main.h"
#include <wx/msgdlg.h>
#include <wx/clipbrd.h>
//#include <string>
#include <wx/string.h>
#include "dlgCppProj.h"
#include <wx/dir.h>

//(*InternalHeaders(gf01Frame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(gf01Frame)
const long gf01Frame::ID_MENUITEM1 = wxNewId();
const long gf01Frame::ID_MENUITEM2 = wxNewId();
const long gf01Frame::idMenuQuit = wxNewId();
const long gf01Frame::idMenuAbout = wxNewId();
const long gf01Frame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(gf01Frame,wxFrame)
    //(*EventTable(gf01Frame)
    //*)
END_EVENT_TABLE()

gf01Frame::gf01Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(gf01Frame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, _("Programmer\'s Workbench"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    menNewBlogPost = new wxMenuItem(Menu1, ID_MENUITEM1, _("New Blog Post"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(menNewBlogPost);
    menSelectDlg = new wxMenuItem(Menu1, ID_MENUITEM2, _("Select A C++ Project"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(menSelectDlg);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&gf01Frame::OnmenNewBlogPostSelected);
    Connect(ID_MENUITEM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&gf01Frame::OnmenSelectDlgSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&gf01Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&gf01Frame::OnAbout);
    //*)
}

gf01Frame::~gf01Frame()
{
    //(*Destroy(gf01Frame)
    //*)
}

void gf01Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void gf01Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void gf01Frame::OnmenNewBlogPostSelected(wxCommandEvent& event)
{
    const char * c;

    string tbuf;
    tbuf = "<img src=\"https://archbrooks.us/images/usa_3a.gif\" alt=\"\" />\n\n";
    tbuf = tbuf + "Mr. Arch Brooks, Software Engineer, Brooks Computing Systems, LLC authored this article.";
    if (wxTheClipboard->Open())
    {
        c = tbuf.c_str();
        wxTheClipboard->SetData(new wxTextDataObject(c));
        wxTheClipboard->Close();
//        wxTheClipboard->Flush();
    }

    system("/usr/bin/konqueror https://archbrooks.us/b4");

}

void gf01Frame::OnmenSelectDlgSelected(wxCommandEvent& event)
{
    string path, fna, xqt, buf, fn;
    dlgCppProj dlg(NULL, wxID_ANY);
    if (dlg.ShowModal() == wxID_OK)
    {
        gf01Frame::rselProj = dlg.selProj;
        fn = dlg.selProj;

    }
//    dlg.Destroy();

    int eop;
    eop = fn.find_last_of("/");
    path = fn.substr(0, eop);
    fna = fn.substr(eop+1);
    xqt = fna.substr(0, fna.find_last_of("."));
    int ret = 99;
    wxString prompt, caption;
    prompt = _T("Execute This Program?");
    caption = _T("Execute ?");
    ret = wxMessageBox(prompt, caption, wxYES_NO | wxCANCEL, NULL);
    if (ret == wxYES)
    {
        buf = path + "/bin/Release/" + xqt;
        system(buf.c_str());

    }
    prompt = _T("Compile This Program?");
    caption = _T("Compile ?");
    ret = 99;

    ret = wxMessageBox(prompt, caption, wxYES_NO | wxCANCEL, NULL);
    if (ret == wxYES)
    {
        buf = "/usr/bin/codeblocks ";
        buf = buf + dlg.selProj;
        system(buf.c_str());

    }

}

void gf01Frame::OnmenListFilesSelected(wxCommandEvent& event)
{
    int ret;
    wxString prompt, caption;
    prompt = _T("Execute This Program?");
    caption = _T("Execute ?");
    ret = wxMessageBox(prompt, caption, wxYES_NO, NULL);
    if (ret == wxYES)
    {

    }
}

void gf01Frame::OnmenFindAllFilesSelected(wxCommandEvent& event)
{
    wxDir dir;
    wxString myParentFolder = _T("/home/archman/workspace/cb/cpp/");
    wxArrayString *childFolders = new wxArrayString;

    unsigned int cnt = dir.GetAllFiles(myParentFolder, childFolders, _T("*.cbp"));

    string buf;
    unsigned int pos = 0;

    wxArrayString strings;
    unsigned int i;
    while (i < cnt)
    {
        buf = childFolders->Item(i).ToStdString();
        strings.Add(buf);
        i++;
    }


//    ListBox1->Set(strings);
    buf = buf;
//    ListBox1->Assign(childFolders);
}
