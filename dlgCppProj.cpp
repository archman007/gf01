#include "dlgCppProj.h"
#include <wx/dir.h>

using namespace std;


//(*InternalHeaders(dlgCppProj)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(dlgCppProj)
const long dlgCppProj::ID_LISTBOX1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(dlgCppProj,wxDialog)
    //(*EventTable(dlgCppProj)
    //*)
END_EVENT_TABLE()

dlgCppProj::dlgCppProj(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(dlgCppProj)
    Create(parent, id, _("Select A Project"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxSYSTEM_MENU|wxRESIZE_BORDER, _T("id"));
    SetClientSize(wxSize(-1,-1));
    Move(wxDefaultPosition);
    SetMinSize(wxSize(-1,-1));
    lbxProj = new wxListBox(this, ID_LISTBOX1, wxPoint(120,184), wxDefaultSize, 0, 0, wxLB_SORT, wxDefaultValidator, _T("ID_LISTBOX1"));
    Center();

    Connect(ID_LISTBOX1,wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,(wxObjectEventFunction)&dlgCppProj::OnlbxProjDClick);
    //*)

    wxDir dir;
    wxString myParentFolder = _T("/home/archman/workspace/cb/cpp/");
    wxArrayString *childFolders = new wxArrayString;

    unsigned int cnt = dir.GetAllFiles(myParentFolder, childFolders, _T("*.cbp"));

    string buf;

    wxArrayString strings;
    unsigned int i = 0;
    while (i < cnt)
    {
        buf = childFolders->Item(i).ToStdString();
        strings.Add(buf);
        i++;
    }

    lbxProj->Set(strings);
    buf = buf;

}

dlgCppProj::~dlgCppProj()
{
    //(*Destroy(dlgCppProj)
    //*)
}


void dlgCppProj::OnListBox1Select(wxCommandEvent& event)
{
}

void dlgCppProj::OnlbxProjDClick(wxCommandEvent& event)
{

    selProj = lbxProj->GetString(lbxProj->GetSelection());
//    selProj = selProj;

//    dlgCppProj::SetModalResult = wxID_OK;
    dlgCppProj::EndModal(wxID_OK);

}
