#ifndef DLGCPPPROJ_H
#define DLGCPPPROJ_H

//(*Headers(dlgCppProj)
#include <wx/dialog.h>
#include <wx/listbox.h>
//*)

using namespace std;

class dlgCppProj: public wxDialog
{
public:

    dlgCppProj(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~dlgCppProj();

    string selProj;

    //(*Declarations(dlgCppProj)
    wxListBox* lbxProj;
    //*)

protected:

    //(*Identifiers(dlgCppProj)
    static const long ID_LISTBOX1;
    //*)

private:

    //(*Handlers(dlgCppProj)
    void OnListBox1Select(wxCommandEvent& event);
    void OnlbxProjDClick(wxCommandEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
