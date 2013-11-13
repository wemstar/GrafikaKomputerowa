#include "MyApp.h"
#include "MyFrame.h"

bool MyApp::OnInit()
{

   wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);

      frame = new wxFrame((wxFrame *)NULL, -1,  wxT("Lab 3"), wxPoint(50,50), wxSize(800,600));

      drawPane = new BasicDrawPane( (wxFrame*) frame );




      sizer->Add(drawPane, 1,wxEXPAND);
      CreateControls(sizer);
      frame->SetSizer(sizer);
      frame->SetAutoLayout(true);
      wxInitAllImageHandlers ();
      frame->Show();
      return true;
}
void MyApp::CreateControls(wxBoxSizer * sizer)
{
    wxBoxSizer* controlers = new wxBoxSizer(wxVERTICAL);

    buttonFilename=new wxButton(frame,ID_BUTTON_FILENAME,wxT("Zapis do pliku"));
    checkBoxBannan=new wxCheckBox(frame,ID_CB_BANAN,wxT("Banan"));
    gaugeProgres=new wxGauge(frame,wxID_ANY,100);
     gaugeProgres->SetValue(50);
    buttonColor=new wxButton(frame,ID_BUTTON_COLOR,wxT("Kolor Gwiazdki"));
    textCtrlText=new wxTextCtrl(frame,ID_TEXTCONTROL,wxT("Kolor Gwiazdki"));

    wxString choices[]={wxT("Gwiazda"),wxT("Księżyc"),wxT("Słońce")};
    choiseDrawType=new wxChoice(frame,ID_TYPE_CHOICE,wxDefaultPosition,wxDefaultSize,3,choices);
    sliderUp=new wxSlider(frame,ID_SLIDER_UP,0,-50,50,wxDefaultPosition,wxSize(140, -1)) ;




    controlers->Add(buttonFilename,0,wxALIGN_CENTER| wxALL,10);
    controlers->Add(checkBoxBannan,0,wxALIGN_CENTER| wxALL,10);
    controlers->Add(sliderUp,0,wxALIGN_CENTER| wxALL,10) ;
    controlers->Add(gaugeProgres,0,wxALIGN_CENTER| wxALL,10) ;
    controlers->Add(buttonColor,0,wxALIGN_CENTER| wxALL,10);
    controlers->Add(textCtrlText,0,wxALIGN_CENTER| wxALL,10);
    controlers->Add(choiseDrawType,0,wxALIGN_CENTER| wxALL,10);
    sizer->Add(controlers, 1, wxEXPAND| wxALL,10);

}
void  MyApp::OnFilenameButtonClick(wxCommandEvent& event)
{
     wxFileDialog filenameDialog(frame, wxT("Save PNG file"), wxT(""),wxT( ""),wxT("PNG files (*.png)|*.png"), wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
      if (filenameDialog.ShowModal() == wxID_OK)
      {
          drawPane->filename=filenameDialog.GetPath();
          drawPane->saveAsImage() ;

      }

}
void  MyApp::OnColorChangeButtonClick(wxCommandEvent& event)
{
    drawPane->starColor=wxGetColourFromUser(frame, drawPane->starColor) ;
     frame->Update();
     frame->Refresh();
}
void  MyApp::OnBananStateChange(wxCommandEvent& event)
{
    drawPane->isBanan=checkBoxBannan->IsChecked ();
    frame->Update();
    frame->Refresh();
}
void MyApp::OnTextChange(wxCommandEvent& event)
{
   drawPane->text=textCtrlText->GetValue();
    frame->Update();
       frame->Refresh();
}
void MyApp::OnChoiceChange(wxCommandEvent& event)
{
     drawPane->choice=choiseDrawType->GetCurrentSelection ();
     frame->Update();
     frame->Refresh();

}
void MyApp::OnValueChange(wxCommandEvent& event)
{
    drawPane->slider=sliderUp->GetValue();
    gaugeProgres->SetValue(drawPane->slider+50);
    frame->Update();
    frame->Refresh();
}

BEGIN_EVENT_TABLE(MyApp,wxApp)
  EVT_BUTTON(ID_BUTTON_FILENAME,MyApp::OnFilenameButtonClick)
  EVT_BUTTON(ID_BUTTON_COLOR,MyApp::OnColorChangeButtonClick)
  EVT_CHECKBOX(ID_CB_BANAN,MyApp::OnBananStateChange)
  EVT_TEXT(ID_TEXTCONTROL,MyApp::OnTextChange)
  EVT_CHOICE(ID_TYPE_CHOICE, MyApp::OnChoiceChange)
  EVT_SLIDER(ID_SLIDER_UP, MyApp::OnValueChange)
  EVT_CHOICE(ID_TYPE_CHOICE, MyApp::OnChoiceChange)
END_EVENT_TABLE()

