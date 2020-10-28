#include "MainFrame.h"
#include "iostream"
using namespace std;
MainFrame::MainFrame() :wxFrame(nullptr, wxID_ANY, "GenshinImpactTools", wxPoint(500, 250), wxSize(800, 350))
{
	mainPanel = new wxPanel(this);
	mainSizer = new wxBoxSizer(wxVERTICAL);
	mainPanel->SetSizer(mainSizer);
	wxStaticText* slogan = new wxStaticText(mainPanel, -1, "小艾咪世界第一可爱，这是谁人也无法质疑的事情≥△≤");
	slogan->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	topSizer = new wxBoxSizer(wxHORIZONTAL);

	wxPanel* leftBlank = new wxPanel(mainPanel);
	wxPanel* middleBlank = new wxPanel(mainPanel);
	wxPanel* rightBlank = new wxPanel(mainPanel);
	topLeftSizer = new wxBoxSizer(wxVERTICAL);
	topRightSizer = new wxBoxSizer(wxVERTICAL);
	topSizer->Add(leftBlank, 1, wxEXPAND);
	topSizer->Add(topLeftSizer, 6, wxCENTER);
	topSizer->Add(middleBlank, 1, wxEXPAND);
	topSizer->Add(topRightSizer, 6, wxCENTER);
	topSizer->Add(rightBlank, 1, wxEXPAND);

	leftContent = new wxFlexGridSizer(4, 2, 0, 0);
	rightContent = new wxFlexGridSizer(4, 2, 0, 0);


	planAText = new wxStaticText(mainPanel, -1, "方案A属性");
	planAText->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	atkLabelA = new wxStaticText(mainPanel, -1, "攻击力：");
	atkA = new wxTextCtrl(mainPanel, -1);
	crLabelA = new wxStaticText(mainPanel, -1, "暴击率：");
	crA = new wxTextCtrl(mainPanel, -1);
	crdLabelA = new wxStaticText(mainPanel, -1, "爆伤：");
	crdA = new wxTextCtrl(mainPanel, -1);
	profitLabelA = new wxStaticText(mainPanel, -1, "平均收益：");
	profitA = new wxStaticText(mainPanel, -1, "");

	planBText = new wxStaticText(mainPanel, -1, "方案B属性");
	planBText->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	atkLabelB = new wxStaticText(mainPanel, -1, "攻击力：");
	atkB = new wxTextCtrl(mainPanel, -1);
	crLabelB = new wxStaticText(mainPanel, -1, "暴击率：");
	crB = new wxTextCtrl(mainPanel, -1);
	crdLabelB = new wxStaticText(mainPanel, -1, "爆伤：");
	crdB = new wxTextCtrl(mainPanel, -1);
	profitLabelB = new wxStaticText(mainPanel, -1, "平均收益：");
	profitB = new wxStaticText(mainPanel, -1, "");

	leftContent->Add(atkLabelA, 0, wxEXPAND);
	leftContent->Add(atkA, 0, wxEXPAND);
	leftContent->Add(crLabelA, 0, wxEXPAND);
	leftContent->Add(crA, 0, wxEXPAND);
	leftContent->Add(crdLabelA, 0, wxEXPAND);
	leftContent->Add(crdA, 0, wxEXPAND);
	leftContent->Add(profitLabelA, 0, wxEXPAND);
	leftContent->Add(profitA, 0, wxEXPAND);
	leftContent->SetVGap(7);
	leftContent->AddGrowableCol(1);
	leftContent->AddGrowableRow(3);

	rightContent->Add(atkLabelB, 0, wxEXPAND);
	rightContent->Add(atkB, 0, wxEXPAND);
	rightContent->Add(crLabelB, 0, wxEXPAND);
	rightContent->Add(crB, 0, wxEXPAND);
	rightContent->Add(crdLabelB, 0, wxEXPAND);
	rightContent->Add(crdB, 0, wxEXPAND);
	rightContent->Add(profitLabelB, 0, wxEXPAND);
	rightContent->Add(profitB, 0, wxEXPAND);
	rightContent->SetVGap(7);
	rightContent->AddGrowableCol(1);
	rightContent->AddGrowableRow(3);

	topLeftSizer->Add(planAText, 1, wxCENTER);
	topLeftSizer->Add(leftContent, 3, wxEXPAND);

	topRightSizer->Add(planBText, 1, wxCENTER);
	topRightSizer->Add(rightContent, 3, wxEXPAND);
	buttomSizer = new wxBoxSizer(wxHORIZONTAL);
	mainSizer->Add(slogan, 1, wxCENTER);
	mainSizer->Add(topSizer, 4, wxEXPAND);
	mainSizer->Add(buttomSizer, 1, wxEXPAND);
	buttomLeft = new wxPanel(mainPanel);
	buttomRight = new wxPanel(mainPanel);
	buttomSizer->Add(buttomLeft, 4, wxEXPAND);
	buttomSizer->Add(buttomRight, 1, wxCENTER);
	compute = new wxButton(buttomRight, -1, "计算");
	compute->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &MainFrame::OnCompute, this);
	//SetSizer(mainSizer);
}

MainFrame::~MainFrame()
{
}

void MainFrame::OnCompute(wxCommandEvent& evt)
{

	wxString atkAValue = atkA->GetValue();
	double tempatkA;
	atkAValue.ToDouble(&tempatkA);
	cout << tempatkA;
	wxString crAValue = crA->GetValue();
	double tempcrA;
	crAValue.ToDouble(&tempcrA);
	wxString crdAValue = crdA->GetValue();
	double tempcrdA;
	crdAValue.ToDouble(&tempcrdA);
	if (atkAValue == "" || crAValue == "" || crdAValue == "") {
		wxMessageBox("A方案含空值");
		return;
	}
	double avgProfitA = (tempatkA * (1 - tempcrA / 100)) + ((tempatkA * (1 + tempcrdA / 100)) * (tempcrA / 100));
	profitA->SetLabelText(wxString::Format(_T("%f"), avgProfitA));

	wxString atkBValue = atkB->GetValue();
	double tempatkB;
	atkBValue.ToDouble(&tempatkB);
	cout << tempatkB;
	wxString crBValue = crB->GetValue();
	double tempcrB;
	crBValue.ToDouble(&tempcrB);
	wxString crdBValue = crdB->GetValue();
	double tempcrdB;
	crdBValue.ToDouble(&tempcrdB);
	if (atkBValue == "" || crBValue == "" || crdBValue == "") {
		wxMessageBox("B方案含空值");
		return;
	}
	double avgProfitB = (tempatkB * (1 - tempcrB / 100)) + ((tempatkB * (1 + tempcrdB / 100)) * (tempcrB / 100));
	profitB->SetLabelText(wxString::Format(_T("%f"), avgProfitB));
	if (avgProfitA > avgProfitB)
	{
		wxMessageBox("推荐选择方案A");
	}
	else
	{
		wxMessageBox("推荐选择方案B");
	}
}
