#pragma once
#include "wx/wx.h"

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

	/*wxButton* m_btn1 = nullptr;
	wxTextCtrl* m_txt1 = nullptr;
	wxListBox* m_list1 = nullptr;*/
	int nFieldWidth = 10;
	int nFieldHeight = 10;
	wxButton** btn; //Array of pointers to buttons 

	void OnButtonClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};



