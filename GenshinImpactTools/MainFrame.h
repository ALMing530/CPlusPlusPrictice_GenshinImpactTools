#pragma once
#include "wx/wx.h"
class MainFrame :public wxFrame
{
public:
	MainFrame();
	~MainFrame();
private:
	wxPanel* mainPanel;
	wxBoxSizer* mainSizer;
	wxBoxSizer* topSizer;
	wxBoxSizer* topLeftSizer;
	wxBoxSizer* topRightSizer;
	wxFlexGridSizer* leftContent;
	wxFlexGridSizer* rightContent;
	wxStaticText* planAText;
	wxStaticText* atkLabelA;
	wxTextCtrl* atkA;
	wxStaticText* crLabelA;
	wxTextCtrl* crA;
	wxStaticText* crdLabelA;
	wxTextCtrl* crdA;
	wxStaticText* profitLabelA;
	wxStaticText* profitA;
	wxStaticText* planBText;
	wxStaticText* atkLabelB;
	wxTextCtrl* atkB;
	wxStaticText* crLabelB;
	wxTextCtrl* crB;
	wxStaticText* crdLabelB;
	wxTextCtrl* crdB;
	wxStaticText* profitLabelB;
	wxStaticText* profitB;
	wxBoxSizer* buttomSizer;
	wxPanel* buttomLeft;
	wxPanel* buttomRight;
	wxButton* compute;
private:
	void OnCompute(wxCommandEvent& evt);
};

