#pragma once

#include "wx/wx.h"
#include "wx/sizer.h"







class BasicDrawPane:public wxPanel
{
public:

    BasicDrawPane(wxFrame *parent);
    void paintEvent(wxPaintEvent & evt);
    void render(wxDC&  dc);
    void paintNow();
    void drawMen(wxDC& dc);
    void drawStar(wxDC& dc);
    void drawBanana(wxDC& dc);
    void drawText(wxDC& dc);


    public:
         wxString filename;
         bool isBanan;
         bool isSave;
         int slider;
         wxColour starColor;
         wxString text;
         int choice;
         void saveAsImage() ;

   DECLARE_EVENT_TABLE()
}  ;
