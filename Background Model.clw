; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=Number_of_Images
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Background Model.h"
LastPage=0

ClassCount=6
Class1=CBackgroundModelApp
Class2=CBackgroundModelDoc
Class3=CBackgroundModelView
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Class5=CAboutDlg
Resource2=IDR_MAINFRAME
Class6=Number_of_Images
Resource3=IDD_NUMBER_OF_IMAGES

[CLS:CBackgroundModelApp]
Type=0
HeaderFile=Background Model.h
ImplementationFile=Background Model.cpp
Filter=N

[CLS:CBackgroundModelDoc]
Type=0
HeaderFile=Background ModelDoc.h
ImplementationFile=Background ModelDoc.cpp
Filter=N

[CLS:CBackgroundModelView]
Type=0
HeaderFile=Background ModelView.h
ImplementationFile=Background ModelView.cpp
Filter=C
BaseClass=CScrollView
VirtualFilter=VWC
LastObject=CBackgroundModelView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=Background Model.cpp
ImplementationFile=Background Model.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=ID_INITIALIZATION
Command18=ID_FOREGROUND_DETECTION
CommandCount=18

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_NUMBER_OF_IMAGES]
Type=1
Class=Number_of_Images
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_NUMBER_OF_IMAGES,edit,1350631552

[CLS:Number_of_Images]
Type=0
HeaderFile=Number_of_Images.h
ImplementationFile=Number_of_Images.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_APP_ABOUT
VirtualFilter=dWC

