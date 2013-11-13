#include "BasicDrawPane.h"
#include <iostream>
using namespace std;
BasicDrawPane::BasicDrawPane(wxFrame* parent) :
wxPanel(parent)
{

    isBanan=false;
    slider=0;
    starColor=* wxCYAN;
    text=wxT("Kolor Gwiazdki");
}

void BasicDrawPane::paintEvent(wxPaintEvent & evt)
{
    wxPaintDC dc(this);
    render(dc);
}
void BasicDrawPane::paintNow()
{
    wxClientDC dc(this);
    render(dc);
}
void BasicDrawPane::render(wxDC&  dc)
{
    dc.Clear();
    drawMen(dc);
    drawStar(dc);
    drawBanana(dc);
    drawText(dc);


}
void BasicDrawPane::drawMen(wxDC& dc)
{
    int y= dc.GetSize().GetHeight()/2;
    int x= dc.GetSize().GetWidth()/2 ;
    int dy=isBanan?-1:1;
    dc.DrawCircle(x,y-100,50);
    dc.DrawCircle(x-25,y-110,10);
    dc.DrawCircle(x+25,y-110,10);

    dc.DrawLine(x,y-50,x,y+100);
    dc.DrawLine(x,y,x-75,y+dy*30+slider);
    dc.DrawLine(x,y,x+75,y+dy*30);
    dc.DrawLine(x,y+100,x-75,y+175);
    dc.DrawLine(x,y+100,x+75,y+175);

    dc.DrawEllipticArc(x-25,y-100,50,40,0,dy*180);

    dc.DrawText(text,10,y+175);
    dc.SetFont(*wxITALIC_FONT);
    dc.DrawRotatedText(text,2*x-50,y+175,90);
    if(isBanan)
    {

        wxBitmap image;
        image.LoadFile(wxString(wxT("banan.png")),wxBITMAP_TYPE_PNG );
        dc.DrawBitmap(image,x-125,y+dy*30+slider);
    }
}
void BasicDrawPane::drawStar(wxDC& dc)
{   if(choice==0){
        wxPoint points[]={wxPoint(10,20),wxPoint(60,20),wxPoint(10,50),wxPoint(30,0),wxPoint(60,40),wxPoint(30,30),wxPoint(30,60),} ;

        dc.SetBrush(wxBrush(starColor));
        dc.DrawPolygon(7,points) ;
    }
    if(choice ==2)
    {
       dc.SetBrush(wxBrush(*wxRED));
       dc.DrawCircle(30,30,20);
    }
    if(choice ==1)
    {
       dc.SetBrush(wxBrush(*wxBLACK));
       dc.DrawCircle(30,30,20);
       dc.SetBrush(wxBrush(*wxWHITE));
       dc.SetPen(wxPen(*wxWHITE));
       dc.DrawCircle(15,30,20);
    }
}
void BasicDrawPane::drawBanana(wxDC& dc){}
void BasicDrawPane::drawText(wxDC& dc){  }
void BasicDrawPane::saveAsImage()
{

    wxMemoryDC memDC;
    wxBitmap image =wxBitmap( 800,640);
    memDC.SelectObject(image);

    render(memDC);
     memDC.SelectObject( wxNullBitmap );




            image.SaveFile(filename,wxBITMAP_TYPE_PNG );


}

BEGIN_EVENT_TABLE(BasicDrawPane,wxPanel)
 EVT_PAINT(BasicDrawPane::paintEvent)
END_EVENT_TABLE()

