#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	//EVT_BUTTON(10001, OnButtonClicked)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "MainFrame", wxPoint(560, 240), wxSize(800, 600))
{
	/*m_btn1 = new wxButton(this, 10001, "ADD TEXT", wxPoint(10, 10), wxSize(150, 50));
	m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 70), wxSize(300, 30));
	m_list1 = new wxListBox(this, wxID_ANY, wxPoint(10, 110), wxSize(300, 300));*/

	btn = new wxButton * [nFieldWidth * nFieldHeight];
	wxGridSizer* grid = new wxGridSizer(nFieldWidth, nFieldHeight, 0, 0);

	for (int x = 0; x < nFieldWidth; x++)
	{
		for (int y = 0; y < nFieldHeight; y++)
		{
			btn[y * nFieldWidth + x] = new wxButton(this, 10000 + (y * nFieldWidth + x));
			grid->Add(btn[y * nFieldWidth + x], 1, wxEXPAND | wxALL);

			btn[y * nFieldWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OnButtonClicked, this);
		}
	}
	this->SetSizer(grid);
	grid->Layout();

}

cMain::~cMain()
{
	//WX Widgets handels the deletion of it's objects
	delete[] btn;
}

void cMain::OnButtonClicked(wxCommandEvent& evt)
{
	//Get Cord. of button in the field
	int x = (evt.GetId() - 10000) % nFieldWidth;
	int y = (evt.GetId() - 10000) / nFieldWidth;

	/*m_list1->AppendString(m_txt1->GetValue());*/
	evt.Skip(); //You don't need to check parents.
}
