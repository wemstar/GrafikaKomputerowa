#pragma once
#include "wx/wx.h"
#include "wx/sizer.h"
#include "wx/colordlg.h"
#include "BasicDrawPane.h"

enum
{
  ID_BUTTON_FILENAME = 10,
  ID_BUTTON_COLOR = 11,
  ID_CB_BANAN ,
  ID_TEXTCONTROL,
  ID_TYPE_CHOICE,
  ID_SLIDER_UP
};
class MyApp : public wxApp
{
    virtual bool OnInit();
    void CreateControls(wxBoxSizer * sizer)  ;
     wxFrame *frame;
     BasicDrawPane * drawPane;


     void  OnFilenameButtonClick(wxCommandEvent& event);
     void  OnColorChangeButtonClick(wxCommandEvent& event);
     void  OnBananStateChange(wxCommandEvent& event);
     void OnTextChange(wxCommandEvent& event);
     void OnChoiceChange(wxCommandEvent& event);
     void OnValueChange(wxCommandEvent& event);

     void ReactOnEvent()
     {
           wxMessageDialog dialog(NULL,wxT("Detected wxButton Click!"),wxT("wxButton Click"));
         dialog.ShowModal();
     }


      wxButton* buttonFilename;
      wxCheckBox* checkBoxBannan;
      wxGauge* gaugeProgres;
      wxSlider* sliderUp;
      wxButton* buttonColor;
      wxTextCtrl* textCtrlText;
      wxChoice* choiseDrawType;

     DECLARE_EVENT_TABLE()
};

