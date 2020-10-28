#pragma once
#include "wx/wx.h"
#include "MainFrame.h"
class App :public wxApp
{
public:
	App();
	~App();
private:
	MainFrame* mainFrame;
public:
	virtual bool OnInit();
};

