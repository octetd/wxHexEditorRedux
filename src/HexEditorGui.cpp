///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 16 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "HexEditorGui.h"

///////////////////////////////////////////////////////////////////////////

HexEditorGui::HexEditorGui( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	mbar = new wxMenuBar( 0 );
	fileMenu = new wxMenu();
	wxMenuItem* menuFileNew;
	menuFileNew = new wxMenuItem( fileMenu, wxID_NEW, wxString( _("&New") ) + wxT('\t') + _("CTRL+N"), _("Creates a new file"), wxITEM_NORMAL );
	fileMenu->Append( menuFileNew );
	
	wxMenuItem* menuFileOpen;
	menuFileOpen = new wxMenuItem( fileMenu, wxID_OPEN, wxString( _("&Open") ) + wxT('\t') + _("CTRL+O"), _("Open a file"), wxITEM_NORMAL );
	fileMenu->Append( menuFileOpen );
	
	menuFileOpenRecent = new wxMenu();
	wxMenuItem* menuFileOpenRecentItem = new wxMenuItem( fileMenu, wxID_ANY, _("Open &Recent"), wxEmptyString, wxITEM_NORMAL, menuFileOpenRecent );
	wxMenuItem* menuFileOpenRecentDummy;
	menuFileOpenRecentDummy = new wxMenuItem( menuFileOpenRecent, wxID_ANY, wxString( _("No Recent File") ) , wxEmptyString, wxITEM_NORMAL );
	menuFileOpenRecent->Append( menuFileOpenRecentDummy );
	menuFileOpenRecentDummy->Enable( false );
	
	fileMenu->Append( menuFileOpenRecentItem );
	
	wxMenuItem* menuFileSave;
	menuFileSave = new wxMenuItem( fileMenu, wxID_SAVE, wxString( _("&Save") ) + wxT('\t') + _("CTRL+S"), _("Save modifications"), wxITEM_NORMAL );
	fileMenu->Append( menuFileSave );
	menuFileSave->Enable( false );
	
	wxMenuItem* menuFileSaveAs;
	menuFileSaveAs = new wxMenuItem( fileMenu, wxID_SAVEAS, wxString( _("Save &As") ) + wxT('\t') + _("SHIFT+CTRL+S"), _("Save current file as..."), wxITEM_NORMAL );
	fileMenu->Append( menuFileSaveAs );
	menuFileSaveAs->Enable( false );
	
	wxMenuItem* menuFileClose;
	menuFileClose = new wxMenuItem( fileMenu, idClose, wxString( _("&Close") ) + wxT('\t') + _("CTRL+W"), _("Close current file"), wxITEM_NORMAL );
	fileMenu->Append( menuFileClose );
	menuFileClose->Enable( false );
	
	fileMenu->AppendSeparator();
	
	wxMenuItem* menuFileImportTAG;
	menuFileImportTAG = new wxMenuItem( fileMenu, idImportTAGs, wxString( _("Import TAGs") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( menuFileImportTAG );
	
	wxMenuItem* menuFileExportTAG;
	menuFileExportTAG = new wxMenuItem( fileMenu, idExportTAGs, wxString( _("Export TAGs") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( menuFileExportTAG );
	
	fileMenu->AppendSeparator();
	
	wxMenuItem* menuFileQuit;
	menuFileQuit = new wxMenuItem( fileMenu, wxID_QUIT, wxString( _("&Quit") ) + wxT('\t') + _("CTRL+Q"), _("Quit the application"), wxITEM_NORMAL );
	fileMenu->Append( menuFileQuit );
	
	mbar->Append( fileMenu, _("&File") ); 
	
	editMenu = new wxMenu();
	wxMenuItem* menuEditUndo;
	menuEditUndo = new wxMenuItem( editMenu, wxID_UNDO, wxString( _("&Undo") ) + wxT('\t') + _("CTRL+Z"), _("Undo last operation"), wxITEM_NORMAL );
	editMenu->Append( menuEditUndo );
	menuEditUndo->Enable( false );
	
	wxMenuItem* menuEditRedo;
	menuEditRedo = new wxMenuItem( editMenu, wxID_REDO, wxString( _("&Redo") ) + wxT('\t') + _("CTRL+Y"), _("Reverts last undo"), wxITEM_NORMAL );
	editMenu->Append( menuEditRedo );
	menuEditRedo->Enable( false );
	
	editMenu->AppendSeparator();
	
	wxMenuItem* menuEditCopy;
	menuEditCopy = new wxMenuItem( editMenu, wxID_COPY, wxString( _("Copy") ) + wxT('\t') + _("CTRL+C"), _("Copies selection"), wxITEM_NORMAL );
	editMenu->Append( menuEditCopy );
	menuEditCopy->Enable( false );
	
	wxMenuItem* menuEditCopyAs;
	menuEditCopyAs = new wxMenuItem( editMenu, idCopyAs, wxString( _("Copy As") ) + wxT('\t') + _("CTRL+SHIFT+C"), _("Copies selection in special format"), wxITEM_NORMAL );
	editMenu->Append( menuEditCopyAs );
	menuEditCopyAs->Enable( false );
	
	wxMenuItem* menuEditSaveAsDump;
	menuEditSaveAsDump = new wxMenuItem( editMenu, idSaveAsDump, wxString( _("Save As Dump") ) + wxT('\t') + _("CTRL+ALT+S"), _("Save selections as a file"), wxITEM_NORMAL );
	editMenu->Append( menuEditSaveAsDump );
	menuEditSaveAsDump->Enable( false );
	
	wxMenuItem* menuEditCut;
	menuEditCut = new wxMenuItem( editMenu, wxID_CUT, wxString( _("Cut") ) + wxT('\t') + _("CTRL+X"), _("Cuts a selection"), wxITEM_NORMAL );
	editMenu->Append( menuEditCut );
	menuEditCut->Enable( false );
	
	wxMenuItem* menuEditPaste;
	menuEditPaste = new wxMenuItem( editMenu, wxID_PASTE, wxString( _("Paste") ) + wxT('\t') + _("CTRL+V"), _("Paste clipboard to cursor location"), wxITEM_NORMAL );
	editMenu->Append( menuEditPaste );
	menuEditPaste->Enable( false );
	
	wxMenuItem* menuEditFill;
	menuEditFill = new wxMenuItem( editMenu, idFillSelection, wxString( _("Fill Selection") ) , _("Fill selection blocks"), wxITEM_NORMAL );
	editMenu->Append( menuEditFill );
	menuEditFill->Enable( false );
	
	wxMenuItem* menuEditDelete;
	menuEditDelete = new wxMenuItem( editMenu, wxID_DELETE, wxString( _("Delete") ) , _("Deletes selection"), wxITEM_NORMAL );
	editMenu->Append( menuEditDelete );
	menuEditDelete->Enable( false );
	
	wxMenuItem* menuEditInsert;
	menuEditInsert = new wxMenuItem( editMenu, idInsert, wxString( _("Insert") ) , _("Inserts new bytes to cursor location"), wxITEM_NORMAL );
	editMenu->Append( menuEditInsert );
	menuEditInsert->Enable( false );
	
	editMenu->AppendSeparator();
	
	wxMenuItem* menuEditFind;
	menuEditFind = new wxMenuItem( editMenu, wxID_FIND, wxString( _("Find") ) + wxT('\t') + _("CTRL+F"), wxEmptyString, wxITEM_NORMAL );
	editMenu->Append( menuEditFind );
	menuEditFind->Enable( false );
	
	wxMenuItem* menuEditReplace;
	menuEditReplace = new wxMenuItem( editMenu, wxID_REPLACE, wxString( _("Replace") ) + wxT('\t') + _("CTRL+R"), wxEmptyString, wxITEM_NORMAL );
	editMenu->Append( menuEditReplace );
	menuEditReplace->Enable( false );
	
	wxMenuItem* menuEditGotooffset;
	menuEditGotooffset = new wxMenuItem( editMenu, idGotoOffset, wxString( _("Go to Offset") ) + wxT('\t') + _("CTRL+G"), _("Branches the given location"), wxITEM_NORMAL );
	editMenu->Append( menuEditGotooffset );
	menuEditGotooffset->Enable( false );
	
	mbar->Append( editMenu, _("&Edit") ); 
	
	viewMenu = new wxMenu();
	wxMenuItem* menuViewInterprater;
	menuViewInterprater = new wxMenuItem( viewMenu, idInterpreter, wxString( _("Data Interpreter") ) , wxEmptyString, wxITEM_CHECK );
	viewMenu->Append( menuViewInterprater );
	
	wxMenuItem* menuViewToolbar;
	menuViewToolbar = new wxMenuItem( viewMenu, idToolbar, wxString( _("Toolbar") ) , wxEmptyString, wxITEM_CHECK );
	viewMenu->Append( menuViewToolbar );
	
	wxMenuItem* menuViewInfopanel;
	menuViewInfopanel = new wxMenuItem( viewMenu, idInfoPanel, wxString( _("InfoPanel") ) , wxEmptyString, wxITEM_CHECK );
	viewMenu->Append( menuViewInfopanel );
	
	wxMenuItem* menuViewTagPanel;
	menuViewTagPanel = new wxMenuItem( viewMenu, idTagPanel, wxString( _("TAG Panel") ) , wxEmptyString, wxITEM_CHECK );
	viewMenu->Append( menuViewTagPanel );
	
	wxMenuItem* menuViewDisassemblerPanel;
	menuViewDisassemblerPanel = new wxMenuItem( viewMenu, idDisassemblerPanel, wxString( _("Disassembler Panel") ) , wxEmptyString, wxITEM_CHECK );
	viewMenu->Append( menuViewDisassemblerPanel );
	
	wxMenuItem* menuViewSearchPanel;
	menuViewSearchPanel = new wxMenuItem( viewMenu, idSearchPanel, wxString( _("Search Panel") ) , wxEmptyString, wxITEM_CHECK );
	viewMenu->Append( menuViewSearchPanel );
	
	wxMenuItem* menuViewComparisonPanel;
	menuViewComparisonPanel = new wxMenuItem( viewMenu, idComparePanel, wxString( _("Comparison Panel") ) , wxEmptyString, wxITEM_CHECK );
	viewMenu->Append( menuViewComparisonPanel );
	
	viewMenu->AppendSeparator();
	
	wxMenuItem* menuViewZebra;
	menuViewZebra = new wxMenuItem( viewMenu, idZebraStriping, wxString( _("Zebra Striping") ) , wxEmptyString, wxITEM_CHECK );
	viewMenu->Append( menuViewZebra );
	
	viewMenu->AppendSeparator();
	
	wxMenuItem* menuViewOffset;
	menuViewOffset = new wxMenuItem( viewMenu, idShowOffset, wxString( _("Offset Control") ) , wxEmptyString, wxITEM_CHECK );
	viewMenu->Append( menuViewOffset );
	menuViewOffset->Check( true );
	
	wxMenuItem* menuViewHex;
	menuViewHex = new wxMenuItem( viewMenu, idShowHex, wxString( _("Hex Control") ) , wxEmptyString, wxITEM_CHECK );
	viewMenu->Append( menuViewHex );
	menuViewHex->Check( true );
	
	wxMenuItem* menuViewText;
	menuViewText = new wxMenuItem( viewMenu, idShowText, wxString( _("Text Control") ) , wxEmptyString, wxITEM_CHECK );
	viewMenu->Append( menuViewText );
	menuViewText->Check( true );
	
	mbar->Append( viewMenu, _("&View") ); 
	
	toolsMenu = new wxMenu();
	wxMenuItem* menuToolChecksum;
	menuToolChecksum = new wxMenuItem( toolsMenu, idChecksum, wxString( _("Calculate Checksum") ) , wxEmptyString, wxITEM_NORMAL );
	toolsMenu->Append( menuToolChecksum );
	
	wxMenuItem* menuToolCompare;
	menuToolCompare = new wxMenuItem( toolsMenu, idCompare, wxString( _("Compare Files") ) , wxEmptyString, wxITEM_NORMAL );
	toolsMenu->Append( menuToolCompare );
	
	wxMenuItem* menuToolsXORView;
	menuToolsXORView = new wxMenuItem( toolsMenu, idXORView, wxString( _("XORView Thru") ) , _("View your XOR encrypted file without decrypting!"), wxITEM_CHECK );
	toolsMenu->Append( menuToolsXORView );
	
	mbar->Append( toolsMenu, _("Tools") ); 
	
	devicesMenu = new wxMenu();
	wxMenuItem* menuDevicesRam;
	menuDevicesRam = new wxMenuItem( devicesMenu, idDeviceRam, wxString( _("Open RAM Device") ) , wxEmptyString, wxITEM_NORMAL );
	devicesMenu->Append( menuDevicesRam );
	menuDevicesRam->Enable( false );
	
	wxMenuItem* menuDevicesMemorySPD;
	menuDevicesMemorySPD = new wxMenuItem( devicesMenu, idDeviceMemorySPD, wxString( _("Open Memory SPD") ) , _("Allow to edit Memory SPD values"), wxITEM_NORMAL );
	devicesMenu->Append( menuDevicesMemorySPD );
	
	menuDeviceDisk = new wxMenu();
	wxMenuItem* menuDeviceDiskItem = new wxMenuItem( devicesMenu, wxID_ANY, _("Open Disk Device"), wxEmptyString, wxITEM_NORMAL, menuDeviceDisk );
	wxMenuItem* menuDevicesDiskItem1;
	menuDevicesDiskItem1 = new wxMenuItem( menuDeviceDisk, wxID_ANY, wxString( _("N/A on this OS (yet)") ) , wxEmptyString, wxITEM_NORMAL );
	menuDeviceDisk->Append( menuDevicesDiskItem1 );
	
	devicesMenu->Append( menuDeviceDiskItem );
	
	wxMenuItem* menuDevicesProcessRAM;
	menuDevicesProcessRAM = new wxMenuItem( devicesMenu, idProcessRAM, wxString( _("Open Process RAM") ) , wxEmptyString, wxITEM_NORMAL );
	devicesMenu->Append( menuDevicesProcessRAM );
	menuDevicesProcessRAM->Enable( false );
	
	devicesMenu->AppendSeparator();
	
	menuDeviceImage = new wxMenu();
	wxMenuItem* menuDeviceImageItem = new wxMenuItem( devicesMenu, wxID_ANY, _("Device Image Tools"), wxEmptyString, wxITEM_NORMAL, menuDeviceImage );
	wxMenuItem* menuDeviceBackup;
	menuDeviceBackup = new wxMenuItem( menuDeviceImage, idDeviceBackup, wxString( _("Backup") ) , wxEmptyString, wxITEM_NORMAL );
	menuDeviceImage->Append( menuDeviceBackup );
	
	wxMenuItem* menuDeviceRestore;
	menuDeviceRestore = new wxMenuItem( menuDeviceImage, idDeviceRestore, wxString( _("Restore") ) , wxEmptyString, wxITEM_NORMAL );
	menuDeviceImage->Append( menuDeviceRestore );
	
	wxMenuItem* menuDeviceErase;
	menuDeviceErase = new wxMenuItem( menuDeviceImage, idDeviceErase, wxString( _("Erase") ) , wxEmptyString, wxITEM_NORMAL );
	menuDeviceImage->Append( menuDeviceErase );
	
	devicesMenu->Append( menuDeviceImageItem );
	
	mbar->Append( devicesMenu, _("Devices") ); 
	
	optionsMenu = new wxMenu();
	menuOptionsFileMode = new wxMenu();
	wxMenuItem* menuOptionsFileModeItem = new wxMenuItem( optionsMenu, wxID_ANY, _("File Mode"), wxEmptyString, wxITEM_NORMAL, menuOptionsFileMode );
	wxMenuItem* menuOptionsFileModeRO;
	menuOptionsFileModeRO = new wxMenuItem( menuOptionsFileMode, idFileRO, wxString( _("Read Only") ) , wxEmptyString, wxITEM_RADIO );
	menuOptionsFileMode->Append( menuOptionsFileModeRO );
	menuOptionsFileModeRO->Enable( false );
	menuOptionsFileModeRO->Check( true );
	
	wxMenuItem* menuOptionsFileModeRW;
	menuOptionsFileModeRW = new wxMenuItem( menuOptionsFileMode, idFileRW, wxString( _("Writeable") ) , wxEmptyString, wxITEM_RADIO );
	menuOptionsFileMode->Append( menuOptionsFileModeRW );
	menuOptionsFileModeRW->Enable( false );
	
	wxMenuItem* menuOptionsFileModeDW;
	menuOptionsFileModeDW = new wxMenuItem( menuOptionsFileMode, idFileDW, wxString( _("Direct Write") ) , wxEmptyString, wxITEM_RADIO );
	menuOptionsFileMode->Append( menuOptionsFileModeDW );
	menuOptionsFileModeDW->Enable( false );
	
	optionsMenu->Append( menuOptionsFileModeItem );
	
	wxMenuItem* menuOptionsPreferences;
	menuOptionsPreferences = new wxMenuItem( optionsMenu, wxID_PREFERENCES, wxString( _("Preferences") ) , wxEmptyString, wxITEM_NORMAL );
	optionsMenu->Append( menuOptionsPreferences );
	
	mbar->Append( optionsMenu, _("Options") ); 
	
	helpMenu = new wxMenu();
	wxMenuItem* menuHelpDonate;
	menuHelpDonate = new wxMenuItem( helpMenu, idDonate, wxString( _("Donate") ) , _("Donate some money to author as a return!"), wxITEM_NORMAL );
	helpMenu->Append( menuHelpDonate );
	
	wxMenuItem* menuHelpWiki;
	menuHelpWiki = new wxMenuItem( helpMenu, idWiki, wxString( _("Wiki") ) , _("Documentation page of wxHexEditor"), wxITEM_NORMAL );
	helpMenu->Append( menuHelpWiki );
	
	wxMenuItem* menuHelpBugReporting;
	menuHelpBugReporting = new wxMenuItem( helpMenu, idBugReport, wxString( _("Bug Reporting") ) , _("Report bugs for smashing them!"), wxITEM_NORMAL );
	helpMenu->Append( menuHelpBugReporting );
	
	wxMenuItem* menuHelpAbout;
	menuHelpAbout = new wxMenuItem( helpMenu, wxID_ABOUT, wxString( _("&About") ) + wxT('\t') + _("F1"), _("Show info about this application"), wxITEM_NORMAL );
	helpMenu->Append( menuHelpAbout );
	
	mbar->Append( helpMenu, _("&Help") ); 
	
	this->SetMenuBar( mbar );
	
	statusBar = this->CreateStatusBar( 5, wxST_SIZEGRIP, wxID_ANY );
	statusBar->SetFont( wxFont( 8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	
	wxBoxSizer* FrameSizer;
	FrameSizer = new wxBoxSizer( wxVERTICAL );
	
	MyNotebook = new wxAuiNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_SCROLL_BUTTONS|wxAUI_NB_TAB_MOVE|wxAUI_NB_TAB_SPLIT|wxAUI_NB_WINDOWLIST_BUTTON );
	
	FrameSizer->Add( MyNotebook, 1, wxEXPAND | wxALL, 5 );
	
	
	this->SetSizer( FrameSizer );
	this->Layout();
	FrameSizer->Fit( this );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( HexEditorGui::OnClose ) );
	this->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HexEditorGui::OnKeyDown ) );
	this->Connect( menuFileNew->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Connect( menuFileOpen->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Connect( menuFileOpenRecentDummy->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Connect( menuFileSave->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Connect( menuFileSaveAs->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Connect( menuFileClose->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Connect( menuFileImportTAG->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Connect( menuFileExportTAG->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Connect( menuFileQuit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Connect( menuEditUndo->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Connect( menuEditRedo->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Connect( menuEditCopy->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Connect( menuEditCopyAs->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Connect( menuEditSaveAsDump->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Connect( menuEditCut->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Connect( menuEditPaste->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Connect( menuEditFill->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Connect( menuEditDelete->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Connect( menuEditInsert->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Connect( menuEditFind->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Connect( menuEditReplace->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Connect( menuEditGotooffset->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Connect( menuViewInterprater->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnViewMenu ) );
	this->Connect( menuViewInterprater->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler( HexEditorGui::OnUpdateUI ) );
	this->Connect( menuViewToolbar->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnViewMenu ) );
	this->Connect( menuViewInfopanel->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnViewMenu ) );
	this->Connect( menuViewTagPanel->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnViewMenu ) );
	this->Connect( menuViewDisassemblerPanel->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnViewMenu ) );
	this->Connect( menuViewDisassemblerPanel->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler( HexEditorGui::OnUpdateUI ) );
	this->Connect( menuViewSearchPanel->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnViewMenu ) );
	this->Connect( menuViewSearchPanel->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler( HexEditorGui::OnUpdateUI ) );
	this->Connect( menuViewComparisonPanel->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnViewMenu ) );
	this->Connect( menuViewComparisonPanel->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler( HexEditorGui::OnUpdateUI ) );
	this->Connect( menuViewZebra->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnViewMenu ) );
	this->Connect( menuViewOffset->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnViewMenu ) );
	this->Connect( menuViewHex->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnViewMenu ) );
	this->Connect( menuViewText->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnViewMenu ) );
	this->Connect( menuToolChecksum->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnToolsMenu ) );
	this->Connect( menuToolCompare->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnToolsMenu ) );
	this->Connect( menuToolsXORView->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnToolsMenu ) );
	this->Connect( menuToolsXORView->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler( HexEditorGui::OnUpdateUI ) );
	this->Connect( menuDevicesRam->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnDevicesMenu ) );
	this->Connect( menuDevicesRam->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler( HexEditorGui::OnUpdateUI ) );
	this->Connect( menuDevicesMemorySPD->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnDevicesMenu ) );
	this->Connect( menuDevicesDiskItem1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnDevicesMenu ) );
	this->Connect( menuDevicesProcessRAM->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnDevicesMenu ) );
	this->Connect( menuDeviceBackup->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnDevicesMenu ) );
	this->Connect( menuDeviceRestore->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnDevicesMenu ) );
	this->Connect( menuDeviceErase->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnDevicesMenu ) );
	this->Connect( menuOptionsFileModeRO->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnOptionsMenu ) );
	this->Connect( menuOptionsFileModeRO->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler( HexEditorGui::OnUpdateUI ) );
	this->Connect( menuOptionsFileModeRW->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnOptionsMenu ) );
	this->Connect( menuOptionsFileModeRW->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler( HexEditorGui::OnUpdateUI ) );
	this->Connect( menuOptionsFileModeDW->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnOptionsMenu ) );
	this->Connect( menuOptionsFileModeDW->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler( HexEditorGui::OnUpdateUI ) );
	this->Connect( menuOptionsPreferences->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnOptionsMenu ) );
	this->Connect( menuHelpDonate->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnHelpMenu ) );
	this->Connect( menuHelpWiki->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnHelpMenu ) );
	this->Connect( menuHelpBugReporting->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnHelpMenu ) );
	this->Connect( menuHelpAbout->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnHelpMenu ) );
}

HexEditorGui::~HexEditorGui()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( HexEditorGui::OnClose ) );
	this->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HexEditorGui::OnKeyDown ) );
	this->Disconnect( wxID_NEW, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Disconnect( wxID_OPEN, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Disconnect( wxID_SAVE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Disconnect( wxID_SAVEAS, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Disconnect( idClose, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Disconnect( idImportTAGs, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Disconnect( idExportTAGs, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Disconnect( wxID_QUIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Disconnect( wxID_UNDO, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Disconnect( wxID_REDO, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Disconnect( wxID_COPY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Disconnect( idCopyAs, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Disconnect( idSaveAsDump, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Disconnect( wxID_CUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Disconnect( wxID_PASTE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Disconnect( idFillSelection, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Disconnect( wxID_DELETE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Disconnect( idInsert, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Disconnect( wxID_FIND, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Disconnect( wxID_REPLACE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Disconnect( idGotoOffset, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnMenuEvent ) );
	this->Disconnect( idInterpreter, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnViewMenu ) );
	this->Disconnect( idInterpreter, wxEVT_UPDATE_UI, wxUpdateUIEventHandler( HexEditorGui::OnUpdateUI ) );
	this->Disconnect( idToolbar, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnViewMenu ) );
	this->Disconnect( idInfoPanel, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnViewMenu ) );
	this->Disconnect( idTagPanel, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnViewMenu ) );
	this->Disconnect( idDisassemblerPanel, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnViewMenu ) );
	this->Disconnect( idDisassemblerPanel, wxEVT_UPDATE_UI, wxUpdateUIEventHandler( HexEditorGui::OnUpdateUI ) );
	this->Disconnect( idSearchPanel, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnViewMenu ) );
	this->Disconnect( idSearchPanel, wxEVT_UPDATE_UI, wxUpdateUIEventHandler( HexEditorGui::OnUpdateUI ) );
	this->Disconnect( idComparePanel, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnViewMenu ) );
	this->Disconnect( idComparePanel, wxEVT_UPDATE_UI, wxUpdateUIEventHandler( HexEditorGui::OnUpdateUI ) );
	this->Disconnect( idZebraStriping, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnViewMenu ) );
	this->Disconnect( idShowOffset, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnViewMenu ) );
	this->Disconnect( idShowHex, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnViewMenu ) );
	this->Disconnect( idShowText, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnViewMenu ) );
	this->Disconnect( idChecksum, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnToolsMenu ) );
	this->Disconnect( idCompare, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnToolsMenu ) );
	this->Disconnect( idXORView, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnToolsMenu ) );
	this->Disconnect( idXORView, wxEVT_UPDATE_UI, wxUpdateUIEventHandler( HexEditorGui::OnUpdateUI ) );
	this->Disconnect( idDeviceRam, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnDevicesMenu ) );
	this->Disconnect( idDeviceRam, wxEVT_UPDATE_UI, wxUpdateUIEventHandler( HexEditorGui::OnUpdateUI ) );
	this->Disconnect( idDeviceMemorySPD, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnDevicesMenu ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnDevicesMenu ) );
	this->Disconnect( idProcessRAM, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnDevicesMenu ) );
	this->Disconnect( idDeviceBackup, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnDevicesMenu ) );
	this->Disconnect( idDeviceRestore, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnDevicesMenu ) );
	this->Disconnect( idDeviceErase, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnDevicesMenu ) );
	this->Disconnect( idFileRO, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnOptionsMenu ) );
	this->Disconnect( idFileRO, wxEVT_UPDATE_UI, wxUpdateUIEventHandler( HexEditorGui::OnUpdateUI ) );
	this->Disconnect( idFileRW, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnOptionsMenu ) );
	this->Disconnect( idFileRW, wxEVT_UPDATE_UI, wxUpdateUIEventHandler( HexEditorGui::OnUpdateUI ) );
	this->Disconnect( idFileDW, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnOptionsMenu ) );
	this->Disconnect( idFileDW, wxEVT_UPDATE_UI, wxUpdateUIEventHandler( HexEditorGui::OnUpdateUI ) );
	this->Disconnect( wxID_PREFERENCES, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnOptionsMenu ) );
	this->Disconnect( idDonate, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnHelpMenu ) );
	this->Disconnect( idWiki, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnHelpMenu ) );
	this->Disconnect( idBugReport, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnHelpMenu ) );
	this->Disconnect( wxID_ABOUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( HexEditorGui::OnHelpMenu ) );
	
}

InterpreterGui::InterpreterGui( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* optionSizer;
	optionSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_check_unsigned = new wxCheckBox( this, ID_CHK_UNSIGNED, _("Unsigned"), wxDefaultPosition, wxDefaultSize, 0 );
	m_check_unsigned->SetFont( wxFont( 8, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, _("Sans") ) );
	
	optionSizer->Add( m_check_unsigned, 0, wxALL, 5 );
	
	m_check_bigendian = new wxCheckBox( this, ID_CHK_BIGENDIAN, _("Big Endian"), wxDefaultPosition, wxDefaultSize, 0 );
	m_check_bigendian->SetFont( wxFont( 8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	
	optionSizer->Add( m_check_bigendian, 0, wxALL, 5 );
	
	
	mainSizer->Add( optionSizer, 0, wxEXPAND, 4 );
	
	wxFlexGridSizer* numSizer;
	numSizer = new wxFlexGridSizer( 7, 2, 0, 0 );
	numSizer->AddGrowableCol( 1 );
	numSizer->SetFlexibleDirection( wxHORIZONTAL );
	
	m_static_bin = new wxStaticText( this, ID_DEFAULT, _("Binary"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
	m_static_bin->Wrap( -1 );
	m_static_bin->SetFont( wxFont( 8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	
	numSizer->Add( m_static_bin, 0, wxALIGN_CENTER, 2 );
	
	wxFlexGridSizer* fgBinSizer;
	fgBinSizer = new wxFlexGridSizer( 1, 2, 0, 0 );
	fgBinSizer->AddGrowableCol( 0 );
	fgBinSizer->SetFlexibleDirection( wxBOTH );
	fgBinSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_textctrl_binary = new wxTextCtrl( this, ID_DEFAULT, _("00000000"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textctrl_binary->HasFlag( wxTE_MULTILINE ) )
	{
	m_textctrl_binary->SetMaxLength( 8 );
	}
	#else
	m_textctrl_binary->SetMaxLength( 8 );
	#endif
	m_textctrl_binary->SetFont( wxFont( 8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_textctrl_binary->SetToolTip( _("Press enter to make changes!") );
	
	fgBinSizer->Add( m_textctrl_binary, 0, wxEXPAND, 1 );
	
	m_check_edit = new wxCheckBox( this, wxID_ANY, _("Edit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_check_edit->SetFont( wxFont( 8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_check_edit->SetToolTip( _("Allow editing by Data Interpreter Panel") );
	
	fgBinSizer->Add( m_check_edit, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 1 );
	
	
	numSizer->Add( fgBinSizer, 1, wxEXPAND, 5 );
	
	m_static_8bit = new wxStaticText( this, ID_DEFAULT, _("8 bit"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
	m_static_8bit->Wrap( -1 );
	m_static_8bit->SetFont( wxFont( 8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	
	numSizer->Add( m_static_8bit, 0, wxALIGN_CENTER, 0 );
	
	m_textctrl_8bit = new wxTextCtrl( this, ID_DEFAULT, _("0"), wxDefaultPosition, wxSize( -1,-1 ), wxTE_READONLY );
	m_textctrl_8bit->SetFont( wxFont( 8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	
	numSizer->Add( m_textctrl_8bit, 0, wxEXPAND, 1 );
	
	m_static_16bit = new wxStaticText( this, ID_DEFAULT, _("16 bit"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
	m_static_16bit->Wrap( -1 );
	m_static_16bit->SetFont( wxFont( 8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	
	numSizer->Add( m_static_16bit, 0, wxALIGN_CENTER, 0 );
	
	m_textctrl_16bit = new wxTextCtrl( this, ID_DEFAULT, _("0"), wxDefaultPosition, wxSize( -1,-1 ), wxTE_READONLY );
	m_textctrl_16bit->SetFont( wxFont( 8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	
	numSizer->Add( m_textctrl_16bit, 0, wxEXPAND, 1 );
	
	m_static_32bit = new wxStaticText( this, ID_DEFAULT, _("32 bit"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
	m_static_32bit->Wrap( -1 );
	m_static_32bit->SetFont( wxFont( 8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	
	numSizer->Add( m_static_32bit, 0, wxALIGN_CENTER, 2 );
	
	m_textctrl_32bit = new wxTextCtrl( this, ID_DEFAULT, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_textctrl_32bit->SetFont( wxFont( 8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	
	numSizer->Add( m_textctrl_32bit, 0, wxEXPAND, 1 );
	
	m_static_64bit = new wxStaticText( this, ID_DEFAULT, _("64 bit"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
	m_static_64bit->Wrap( -1 );
	m_static_64bit->SetFont( wxFont( 8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	
	numSizer->Add( m_static_64bit, 0, wxALIGN_CENTER, 2 );
	
	m_textctrl_64bit = new wxTextCtrl( this, ID_DEFAULT, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_textctrl_64bit->SetFont( wxFont( 8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	
	numSizer->Add( m_textctrl_64bit, 0, wxEXPAND, 1 );
	
	m_static_float = new wxStaticText( this, ID_DEFAULT, _("Float"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
	m_static_float->Wrap( -1 );
	m_static_float->SetFont( wxFont( 8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	
	numSizer->Add( m_static_float, 0, wxALIGN_CENTER, 2 );
	
	m_textctrl_float = new wxTextCtrl( this, ID_DEFAULT, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_textctrl_float->SetFont( wxFont( 8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	
	numSizer->Add( m_textctrl_float, 0, wxEXPAND, 1 );
	
	m_static_double = new wxStaticText( this, ID_DEFAULT, _("Double"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
	m_static_double->Wrap( -1 );
	m_static_double->SetFont( wxFont( 8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	
	numSizer->Add( m_static_double, 0, wxALIGN_CENTER|wxBOTTOM|wxTOP, 3 );
	
	m_textctrl_double = new wxTextCtrl( this, ID_DEFAULT, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_textctrl_double->SetFont( wxFont( 8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	
	numSizer->Add( m_textctrl_double, 0, wxEXPAND, 1 );
	
	
	mainSizer->Add( numSizer, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( mainSizer );
	this->Layout();
	mainSizer->Fit( this );
	
	// Connect Events
	m_check_unsigned->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( InterpreterGui::OnUpdate ), NULL, this );
	m_check_bigendian->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( InterpreterGui::OnUpdate ), NULL, this );
	m_textctrl_binary->Connect( wxEVT_CHAR, wxKeyEventHandler( InterpreterGui::OnTextEdit ), NULL, this );
	m_textctrl_binary->Connect( wxEVT_MIDDLE_DCLICK, wxMouseEventHandler( InterpreterGui::OnTextMouse ), NULL, this );
	m_textctrl_binary->Connect( wxEVT_MIDDLE_DOWN, wxMouseEventHandler( InterpreterGui::OnTextMouse ), NULL, this );
	m_textctrl_binary->Connect( wxEVT_MIDDLE_UP, wxMouseEventHandler( InterpreterGui::OnTextMouse ), NULL, this );
	m_textctrl_binary->Connect( wxEVT_RIGHT_DCLICK, wxMouseEventHandler( InterpreterGui::OnTextMouse ), NULL, this );
	m_textctrl_binary->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( InterpreterGui::OnTextMouse ), NULL, this );
	m_textctrl_binary->Connect( wxEVT_RIGHT_UP, wxMouseEventHandler( InterpreterGui::OnTextMouse ), NULL, this );
	m_check_edit->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( InterpreterGui::OnCheckEdit ), NULL, this );
}

InterpreterGui::~InterpreterGui()
{
	// Disconnect Events
	m_check_unsigned->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( InterpreterGui::OnUpdate ), NULL, this );
	m_check_bigendian->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( InterpreterGui::OnUpdate ), NULL, this );
	m_textctrl_binary->Disconnect( wxEVT_CHAR, wxKeyEventHandler( InterpreterGui::OnTextEdit ), NULL, this );
	m_textctrl_binary->Disconnect( wxEVT_MIDDLE_DCLICK, wxMouseEventHandler( InterpreterGui::OnTextMouse ), NULL, this );
	m_textctrl_binary->Disconnect( wxEVT_MIDDLE_DOWN, wxMouseEventHandler( InterpreterGui::OnTextMouse ), NULL, this );
	m_textctrl_binary->Disconnect( wxEVT_MIDDLE_UP, wxMouseEventHandler( InterpreterGui::OnTextMouse ), NULL, this );
	m_textctrl_binary->Disconnect( wxEVT_RIGHT_DCLICK, wxMouseEventHandler( InterpreterGui::OnTextMouse ), NULL, this );
	m_textctrl_binary->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( InterpreterGui::OnTextMouse ), NULL, this );
	m_textctrl_binary->Disconnect( wxEVT_RIGHT_UP, wxMouseEventHandler( InterpreterGui::OnTextMouse ), NULL, this );
	m_check_edit->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( InterpreterGui::OnCheckEdit ), NULL, this );
	
}

TagPanelGui::TagPanelGui( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* mainSize;
	mainSize = new wxBoxSizer( wxVERTICAL );
	
	TagPanelList = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	mainSize->Add( TagPanelList, 1, wxALL|wxEXPAND, 2 );
	
	wxBoxSizer* bSizerBottom;
	bSizerBottom = new wxBoxSizer( wxHORIZONTAL );
	
	m_buttonClear = new wxButton( this, wxID_ANY, _("Clear"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerBottom->Add( m_buttonClear, 1, wxALIGN_CENTER_HORIZONTAL, 2 );
	
	m_buttonHide = new wxButton( this, wxID_ANY, _("Hide"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonHide->Hide();
	
	bSizerBottom->Add( m_buttonHide, 1, 0, 5 );
	
	
	mainSize->Add( bSizerBottom, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( mainSize );
	this->Layout();
	mainSize->Fit( this );
	
	// Connect Events
	TagPanelList->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( TagPanelGui::OnTagSelect ), NULL, this );
	TagPanelList->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( TagPanelGui::OnRightMouse ), NULL, this );
	m_buttonClear->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TagPanelGui::OnClear ), NULL, this );
	m_buttonHide->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TagPanelGui::OnHide ), NULL, this );
}

TagPanelGui::~TagPanelGui()
{
	// Disconnect Events
	TagPanelList->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( TagPanelGui::OnTagSelect ), NULL, this );
	TagPanelList->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( TagPanelGui::OnRightMouse ), NULL, this );
	m_buttonClear->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TagPanelGui::OnClear ), NULL, this );
	m_buttonHide->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TagPanelGui::OnHide ), NULL, this );
	
}

InfoPanelGui::InfoPanelGui( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer( wxVERTICAL );
	
	m_InfoPanelText = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_InfoPanelText->Wrap( -1 );
	mainSizer->Add( m_InfoPanelText, 0, wxALL, 2 );
	
	
	this->SetSizer( mainSizer );
	this->Layout();
}

InfoPanelGui::~InfoPanelGui()
{
}

DisassemblerPanelGUI::DisassemblerPanelGUI( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerTop;
	bSizerTop = new wxBoxSizer( wxHORIZONTAL );
	
	wxString m_choiceVendorChoices[] = { _("INTEL"), _("AMD") };
	int m_choiceVendorNChoices = sizeof( m_choiceVendorChoices ) / sizeof( wxString );
	m_choiceVendor = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceVendorNChoices, m_choiceVendorChoices, 0 );
	m_choiceVendor->SetSelection( 0 );
	m_choiceVendor->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_choiceVendor->SetToolTip( _("CPU Vendor") );
	
	bSizerTop->Add( m_choiceVendor, 1, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	wxString m_choiceASMTypeChoices[] = { _("INTEL"), _("AT&T") };
	int m_choiceASMTypeNChoices = sizeof( m_choiceASMTypeChoices ) / sizeof( wxString );
	m_choiceASMType = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceASMTypeNChoices, m_choiceASMTypeChoices, 0 );
	m_choiceASMType->SetSelection( 0 );
	m_choiceASMType->SetToolTip( _("Assembly Type") );
	
	bSizerTop->Add( m_choiceASMType, 1, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	wxString m_choiceBitModeChoices[] = { _("16 Bit"), _("32 Bit"), _("64 Bit") };
	int m_choiceBitModeNChoices = sizeof( m_choiceBitModeChoices ) / sizeof( wxString );
	m_choiceBitMode = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceBitModeNChoices, m_choiceBitModeChoices, 0 );
	m_choiceBitMode->SetSelection( 1 );
	m_choiceBitMode->SetToolTip( _("Disassembly Bit Mode") );
	
	bSizerTop->Add( m_choiceBitMode, 1, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	
	mainSizer->Add( bSizerTop, 0, wxEXPAND, 5 );
	
	m_dasmCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_DONTWRAP|wxTE_MULTILINE|wxTE_READONLY );
	mainSizer->Add( m_dasmCtrl, 1, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	
	this->SetSizer( mainSizer );
	this->Layout();
	
	// Connect Events
	m_choiceVendor->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( DisassemblerPanelGUI::OnUpdate ), NULL, this );
	m_choiceASMType->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( DisassemblerPanelGUI::OnUpdate ), NULL, this );
	m_choiceBitMode->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( DisassemblerPanelGUI::OnUpdate ), NULL, this );
}

DisassemblerPanelGUI::~DisassemblerPanelGUI()
{
	// Disconnect Events
	m_choiceVendor->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( DisassemblerPanelGUI::OnUpdate ), NULL, this );
	m_choiceASMType->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( DisassemblerPanelGUI::OnUpdate ), NULL, this );
	m_choiceBitMode->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( DisassemblerPanelGUI::OnUpdate ), NULL, this );
	
}

GotoDialogGui::GotoDialogGui( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerTop;
	bSizerTop = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextOffset = new wxStaticText( this, wxID_ANY, _("Offset"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextOffset->Wrap( -1 );
	m_staticTextOffset->Hide();
	
	bSizerTop->Add( m_staticTextOffset, 0, wxALIGN_CENTER|wxALL, 5 );
	
	wxString m_choiceModeChoices[] = { _("Offset"), _("Sector") };
	int m_choiceModeNChoices = sizeof( m_choiceModeChoices ) / sizeof( wxString );
	m_choiceMode = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceModeNChoices, m_choiceModeChoices, 0 );
	m_choiceMode->SetSelection( 0 );
	bSizerTop->Add( m_choiceMode, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_comboBoxOffset = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_DROPDOWN );
	m_comboBoxOffset->Append( _(" ") );
	m_comboBoxOffset->Append( _(" ") );
	m_comboBoxOffset->Append( _(" ") );
	m_comboBoxOffset->Append( _(" ") );
	m_comboBoxOffset->Append( _(" ") );
	m_comboBoxOffset->Append( _(" ") );
	m_comboBoxOffset->Append( _(" ") );
	m_comboBoxOffset->Append( _(" ") );
	m_comboBoxOffset->Append( _(" ") );
	m_comboBoxOffset->Append( _(" ") );
	bSizerTop->Add( m_comboBoxOffset, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_dec = new wxRadioButton( this, wxID_ANY, _("Decimal"), wxDefaultPosition, wxDefaultSize, 0 );
	m_dec->SetValue( true ); 
	bSizerTop->Add( m_dec, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5 );
	
	m_hex = new wxRadioButton( this, wxID_ANY, _("Hex"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerTop->Add( m_hex, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	mainSizer->Add( bSizerTop, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerMedium;
	bSizerMedium = new wxBoxSizer( wxHORIZONTAL );
	
	m_button_prev = new wxButton( this, wxID_ANY, _("Previous Sector"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_prev->Hide();
	
	bSizerMedium->Add( m_button_prev, 1, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_button_next = new wxButton( this, wxID_ANY, _("Next Sector"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_next->Hide();
	
	bSizerMedium->Add( m_button_next, 1, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	
	mainSizer->Add( bSizerMedium, 1, wxEXPAND, 0 );
	
	wxBoxSizer* bSizerBottom;
	bSizerBottom = new wxBoxSizer( wxHORIZONTAL );
	
	wxString m_branchChoices[] = { _("From beginning"), _("From here"), _("From end") };
	int m_branchNChoices = sizeof( m_branchChoices ) / sizeof( wxString );
	m_branch = new wxRadioBox( this, wxID_ANY, _("Type of branch"), wxDefaultPosition, wxDefaultSize, m_branchNChoices, m_branchChoices, 1, wxRA_SPECIFY_ROWS );
	m_branch->SetSelection( 2 );
	bSizerBottom->Add( m_branch, 0, wxBOTTOM|wxLEFT, 5 );
	
	m_button_go = new wxButton( this, wxID_ANY, _("Go!"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_go->SetDefault(); 
	bSizerBottom->Add( m_button_go, 1, wxALIGN_CENTER|wxTOP|wxLEFT, 5 );
	
	
	mainSizer->Add( bSizerBottom, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( mainSizer );
	this->Layout();
	mainSizer->Fit( this );
	
	// Connect Events
	m_choiceMode->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GotoDialogGui::EventHandler ), NULL, this );
	m_comboBoxOffset->Connect( wxEVT_CHAR, wxKeyEventHandler( GotoDialogGui::OnChar ), NULL, this );
	m_comboBoxOffset->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GotoDialogGui::OnInput ), NULL, this );
	m_comboBoxOffset->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GotoDialogGui::OnGO ), NULL, this );
	m_dec->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GotoDialogGui::EventHandler ), NULL, this );
	m_hex->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GotoDialogGui::EventHandler ), NULL, this );
	m_button_prev->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GotoDialogGui::OnPreviousSector ), NULL, this );
	m_button_next->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GotoDialogGui::OnNextSector ), NULL, this );
	m_branch->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( GotoDialogGui::EventHandler ), NULL, this );
	m_button_go->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GotoDialogGui::OnGo ), NULL, this );
}

GotoDialogGui::~GotoDialogGui()
{
	// Disconnect Events
	m_choiceMode->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GotoDialogGui::EventHandler ), NULL, this );
	m_comboBoxOffset->Disconnect( wxEVT_CHAR, wxKeyEventHandler( GotoDialogGui::OnChar ), NULL, this );
	m_comboBoxOffset->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GotoDialogGui::OnInput ), NULL, this );
	m_comboBoxOffset->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GotoDialogGui::OnGO ), NULL, this );
	m_dec->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GotoDialogGui::EventHandler ), NULL, this );
	m_hex->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GotoDialogGui::EventHandler ), NULL, this );
	m_button_prev->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GotoDialogGui::OnPreviousSector ), NULL, this );
	m_button_next->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GotoDialogGui::OnNextSector ), NULL, this );
	m_branch->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( GotoDialogGui::EventHandler ), NULL, this );
	m_button_go->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GotoDialogGui::OnGo ), NULL, this );
	
}

FindDialogGui::FindDialogGui( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );
	
	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxHORIZONTAL );
	
	wxFlexGridSizer* fgSizerLeft;
	fgSizerLeft = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizerLeft->AddGrowableCol( 0 );
	fgSizerLeft->SetFlexibleDirection( wxBOTH );
	fgSizerLeft->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxBoxSizer* bSizerBottom;
	bSizerBottom = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizerTop;
	fgSizerTop = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizerTop->AddGrowableCol( 1 );
	fgSizerTop->SetFlexibleDirection( wxBOTH );
	fgSizerTop->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_static_search = new wxStaticText( this, wxID_ANY, _("Search: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_static_search->Wrap( -1 );
	fgSizerTop->Add( m_static_search, 0, wxALIGN_CENTER, 5 );
	
	m_comboBoxSearch = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_DROPDOWN );
	m_comboBoxSearch->Append( _(" ") );
	m_comboBoxSearch->Append( _(" ") );
	m_comboBoxSearch->Append( _(" ") );
	m_comboBoxSearch->Append( _(" ") );
	m_comboBoxSearch->Append( _(" ") );
	m_comboBoxSearch->Append( _(" ") );
	m_comboBoxSearch->Append( _(" ") );
	m_comboBoxSearch->Append( _(" ") );
	m_comboBoxSearch->Append( _(" ") );
	m_comboBoxSearch->Append( _(" ") );
	fgSizerTop->Add( m_comboBoxSearch, 0, wxALL|wxEXPAND, 5 );
	
	m_static_replace = new wxStaticText( this, wxID_ANY, _("Replace: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_static_replace->Wrap( -1 );
	m_static_replace->Hide();
	
	fgSizerTop->Add( m_static_replace, 0, wxALIGN_CENTER, 5 );
	
	m_comboBoxReplace = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_DROPDOWN );
	m_comboBoxReplace->Append( _(" ") );
	m_comboBoxReplace->Append( _(" ") );
	m_comboBoxReplace->Append( _(" ") );
	m_comboBoxReplace->Append( _(" ") );
	m_comboBoxReplace->Append( _(" ") );
	m_comboBoxReplace->Append( _(" ") );
	m_comboBoxReplace->Append( _(" ") );
	m_comboBoxReplace->Append( _(" ") );
	m_comboBoxReplace->Append( _(" ") );
	m_comboBoxReplace->Append( _(" ") );
	m_comboBoxReplace->Hide();
	
	fgSizerTop->Add( m_comboBoxReplace, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizerBottom->Add( fgSizerTop, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizerLeft->Add( bSizerBottom, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerOptions;
	bSizerOptions = new wxBoxSizer( wxHORIZONTAL );
	
	wxString m_searchtypeChoices[] = { _("Text"), _("Hex") };
	int m_searchtypeNChoices = sizeof( m_searchtypeChoices ) / sizeof( wxString );
	m_searchtype = new wxRadioBox( this, wxID_ANY, _("Search as"), wxDefaultPosition, wxDefaultSize, m_searchtypeNChoices, m_searchtypeChoices, 1, wxRA_SPECIFY_COLS );
	m_searchtype->SetSelection( 1 );
	bSizerOptions->Add( m_searchtype, 1, wxALL, 3 );
	
	wxStaticBoxSizer* sbSizerSearchOptions;
	sbSizerSearchOptions = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Options") ), wxVERTICAL );
	
	chkMatchCase = new wxCheckBox( sbSizerSearchOptions->GetStaticBox(), wxID_ANY, _("Match Case"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSearchOptions->Add( chkMatchCase, 0, wxALL, 5 );
	
	chkSearchBackwards = new wxCheckBox( sbSizerSearchOptions->GetStaticBox(), wxID_ANY, _("Search backwards"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSearchOptions->Add( chkSearchBackwards, 0, wxALL, 5 );
	
	chkWrapAround = new wxCheckBox( sbSizerSearchOptions->GetStaticBox(), wxID_ANY, _("Wrap around"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSearchOptions->Add( chkWrapAround, 0, wxALL, 5 );
	
	chkUTF8 = new wxCheckBox( sbSizerSearchOptions->GetStaticBox(), wxID_ANY, _("As UTF-8"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSearchOptions->Add( chkUTF8, 0, wxALL, 5 );
	
	
	bSizerOptions->Add( sbSizerSearchOptions, 1, wxEXPAND, 5 );
	
	
	fgSizerLeft->Add( bSizerOptions, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 2 );
	
	
	bSizerMain->Add( fgSizerLeft, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerButtons;
	bSizerButtons = new wxBoxSizer( wxVERTICAL );
	
	btnFind = new wxButton( this, wxID_ANY, _("Find"), wxDefaultPosition, wxDefaultSize, 0 );
	btnFind->SetDefault(); 
	bSizerButtons->Add( btnFind, 0, wxALIGN_CENTER|wxTOP, 2 );
	
	btnFindAll = new wxButton( this, wxID_ANY, _("Find All"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerButtons->Add( btnFindAll, 0, wxALIGN_CENTER|wxTOP, 2 );
	
	btnFindSomeBytes = new wxButton( this, wxID_ANY, _("Find Some Bytes"), wxDefaultPosition, wxDefaultSize, 0 );
	btnFindSomeBytes->SetToolTip( _("This function finds some different values at file. Usefull for finding non-null sections at disks.") );
	
	bSizerButtons->Add( btnFindSomeBytes, 0, wxALIGN_CENTER|wxTOP, 2 );
	
	m_staticline = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_staticline->Hide();
	
	bSizerButtons->Add( m_staticline, 0, wxALL|wxEXPAND, 5 );
	
	btnReplace = new wxButton( this, wxID_ANY, _("Replace"), wxDefaultPosition, wxDefaultSize, 0 );
	btnReplace->Hide();
	
	bSizerButtons->Add( btnReplace, 0, wxALIGN_CENTER, 2 );
	
	btnReplaceAll = new wxButton( this, wxID_ANY, _("Replace All"), wxDefaultPosition, wxDefaultSize, 0 );
	btnReplaceAll->Hide();
	
	bSizerButtons->Add( btnReplaceAll, 0, wxALIGN_CENTER, 2 );
	
	btnClose = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerButtons->Add( btnClose, 0, wxALIGN_CENTER, 2 );
	
	
	bSizerMain->Add( bSizerButtons, 0, wxEXPAND|wxRIGHT, 5 );
	
	
	this->SetSizer( bSizerMain );
	this->Layout();
	bSizerMain->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_comboBoxSearch->Connect( wxEVT_CHAR, wxKeyEventHandler( FindDialogGui::OnChar ), NULL, this );
	m_comboBoxSearch->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( FindDialogGui::EventHandler ), NULL, this );
	m_comboBoxSearch->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FindDialogGui::EventHandler ), NULL, this );
	m_comboBoxReplace->Connect( wxEVT_CHAR, wxKeyEventHandler( FindDialogGui::OnChar ), NULL, this );
	m_comboBoxReplace->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( FindDialogGui::EventHandler ), NULL, this );
	m_comboBoxReplace->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FindDialogGui::EventHandler ), NULL, this );
	m_searchtype->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( FindDialogGui::EventHandler ), NULL, this );
	chkMatchCase->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FindDialogGui::EventHandler ), NULL, this );
	chkSearchBackwards->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FindDialogGui::EventHandler ), NULL, this );
	chkWrapAround->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FindDialogGui::EventHandler ), NULL, this );
	chkUTF8->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FindDialogGui::EventHandler ), NULL, this );
	btnFind->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FindDialogGui::EventHandler ), NULL, this );
	btnFindAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FindDialogGui::EventHandler ), NULL, this );
	btnFindSomeBytes->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FindDialogGui::EventHandler ), NULL, this );
	btnReplace->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FindDialogGui::EventHandler ), NULL, this );
	btnReplaceAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FindDialogGui::EventHandler ), NULL, this );
}

FindDialogGui::~FindDialogGui()
{
	// Disconnect Events
	m_comboBoxSearch->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FindDialogGui::OnChar ), NULL, this );
	m_comboBoxSearch->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( FindDialogGui::EventHandler ), NULL, this );
	m_comboBoxSearch->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FindDialogGui::EventHandler ), NULL, this );
	m_comboBoxReplace->Disconnect( wxEVT_CHAR, wxKeyEventHandler( FindDialogGui::OnChar ), NULL, this );
	m_comboBoxReplace->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( FindDialogGui::EventHandler ), NULL, this );
	m_comboBoxReplace->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FindDialogGui::EventHandler ), NULL, this );
	m_searchtype->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( FindDialogGui::EventHandler ), NULL, this );
	chkMatchCase->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FindDialogGui::EventHandler ), NULL, this );
	chkSearchBackwards->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FindDialogGui::EventHandler ), NULL, this );
	chkWrapAround->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FindDialogGui::EventHandler ), NULL, this );
	chkUTF8->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( FindDialogGui::EventHandler ), NULL, this );
	btnFind->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FindDialogGui::EventHandler ), NULL, this );
	btnFindAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FindDialogGui::EventHandler ), NULL, this );
	btnFindSomeBytes->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FindDialogGui::EventHandler ), NULL, this );
	btnReplace->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FindDialogGui::EventHandler ), NULL, this );
	btnReplaceAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FindDialogGui::EventHandler ), NULL, this );
	
}

UpdateDialogGui::UpdateDialogGui( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* MainBoxSizer;
	MainBoxSizer = new wxBoxSizer( wxHORIZONTAL );
	
	wxbtmp_icon = new wxStaticBitmap( this, wxID_OPEN, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	MainBoxSizer->Add( wxbtmp_icon, 0, wxALIGN_CENTER|wxALL, 10 );
	
	wxBoxSizer* VerticalBoxSizer;
	VerticalBoxSizer = new wxBoxSizer( wxVERTICAL );
	
	version_text = new wxStaticText( this, wxID_ANY, _("New wxHexEditor version %s is available!"), wxDefaultPosition, wxDefaultSize, 0 );
	version_text->Wrap( -1 );
	VerticalBoxSizer->Add( version_text, 0, wxALIGN_CENTER|wxALL, 10 );
	
	m_hyperlink = new wxHyperlinkCtrl( this, wxID_ANY, _("Download new wxHexEditor"), _("http://www.wxhexeditor.org"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	VerticalBoxSizer->Add( m_hyperlink, 0, wxALIGN_CENTER|wxALL, 5 );
	
	wxchk_display = new wxCheckBox( this, wxID_ANY, _("Do not show this again."), wxDefaultPosition, wxDefaultSize, 0 );
	VerticalBoxSizer->Add( wxchk_display, 0, wxALIGN_CENTER|wxALL, 10 );
	
	
	MainBoxSizer->Add( VerticalBoxSizer, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( MainBoxSizer );
	this->Layout();
	MainBoxSizer->Fit( this );
	
	// Connect Events
	wxchk_display->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UpdateDialogGui::OnChkDisplay ), NULL, this );
}

UpdateDialogGui::~UpdateDialogGui()
{
	// Disconnect Events
	wxchk_display->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( UpdateDialogGui::OnChkDisplay ), NULL, this );
	
}

CompareDialogGui::CompareDialogGui( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizerFiles;
	fgSizerFiles = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizerFiles->AddGrowableCol( 1 );
	fgSizerFiles->SetFlexibleDirection( wxBOTH );
	fgSizerFiles->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_TextFile1 = new wxStaticText( this, wxID_ANY, _("File #1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_TextFile1->Wrap( -1 );
	fgSizerFiles->Add( m_TextFile1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	filePick1 = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, _("Select a file"), _("*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	fgSizerFiles->Add( filePick1, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_TextFile2 = new wxStaticText( this, wxID_ANY, _("File #2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_TextFile2->Wrap( -1 );
	fgSizerFiles->Add( m_TextFile2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	filePick2 = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, _("Select a file"), _("*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	fgSizerFiles->Add( filePick2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerMain->Add( fgSizerFiles, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerSearchFor;
	sbSizerSearchFor = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Search For") ), wxHORIZONTAL );
	
	m_radioDifferent = new wxRadioButton( sbSizerSearchFor->GetStaticBox(), wxID_ANY, _("Different bytes"), wxDefaultPosition, wxDefaultSize, 0 );
	m_radioDifferent->SetValue( true ); 
	sbSizerSearchFor->Add( m_radioDifferent, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_radioSame = new wxRadioButton( sbSizerSearchFor->GetStaticBox(), wxID_ANY, _("Same bytes"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSearchFor->Add( m_radioSame, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerMain->Add( sbSizerSearchFor, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerStopAfter;
	bSizerStopAfter = new wxBoxSizer( wxHORIZONTAL );
	
	checkStopCompare = new wxCheckBox( this, wxID_ANY, _("Stop comparison after"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerStopAfter->Add( checkStopCompare, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	spinStopCompare = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 0 );
	spinStopCompare->Enable( false );
	
	bSizerStopAfter->Add( spinStopCompare, 0, wxALL, 5 );
	
	m_staticTextHits = new wxStaticText( this, wxID_ANY, _("hits"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextHits->Wrap( -1 );
	bSizerStopAfter->Add( m_staticTextHits, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerMain->Add( bSizerStopAfter, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerMerger;
	bSizerMerger = new wxBoxSizer( wxHORIZONTAL );
	
	checkMergeSection = new wxCheckBox( this, wxID_ANY, _("Merge sections if close as"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerMerger->Add( checkMergeSection, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	spinMergeSection = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100000000, 0 );
	spinMergeSection->Enable( false );
	
	bSizerMerger->Add( spinMergeSection, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextBytes = new wxStaticText( this, wxID_ANY, _("bytes"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextBytes->Wrap( -1 );
	bSizerMerger->Add( m_staticTextBytes, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerMain->Add( bSizerMerger, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerSave;
	bSizerSave = new wxBoxSizer( wxHORIZONTAL );
	
	checkSaveResults = new wxCheckBox( this, wxID_ANY, _("Save Results to File"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerSave->Add( checkSaveResults, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	filePickSave = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, _("Select a file"), _("*.txt"), wxDefaultPosition, wxDefaultSize, wxFLP_OVERWRITE_PROMPT|wxFLP_SAVE );
	filePickSave->Enable( false );
	
	bSizerSave->Add( filePickSave, 0, wxALL, 5 );
	
	
	bSizerMain->Add( bSizerSave, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerSave1;
	bSizerSave1 = new wxBoxSizer( wxHORIZONTAL );
	
	checkConnectFiles = new wxCheckBox( this, wxID_ANY, _("Connect files for scrolling"), wxDefaultPosition, wxDefaultSize, 0 );
	checkConnectFiles->SetToolTip( _("With this option enabled, compared files will always show same address location.") );
	
	bSizerSave1->Add( checkConnectFiles, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerMain->Add( bSizerSave1, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerButtons;
	bSizerButtons = new wxBoxSizer( wxHORIZONTAL );
	
	btnCancel = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerButtons->Add( btnCancel, 1, wxALL, 5 );
	
	btnCompare = new wxButton( this, wxID_ANY, _("Compare"), wxDefaultPosition, wxDefaultSize, 0 );
	btnCompare->SetDefault(); 
	btnCompare->Enable( false );
	
	bSizerButtons->Add( btnCompare, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerMain->Add( bSizerButtons, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizerMain );
	this->Layout();
	bSizerMain->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	filePick1->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( CompareDialogGui::OnFileChange ), NULL, this );
	filePick2->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( CompareDialogGui::OnFileChange ), NULL, this );
	m_radioDifferent->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( CompareDialogGui::EventHandler ), NULL, this );
	m_radioSame->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( CompareDialogGui::EventHandler ), NULL, this );
	checkStopCompare->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CompareDialogGui::EventHandler ), NULL, this );
	checkMergeSection->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CompareDialogGui::EventHandler ), NULL, this );
	checkSaveResults->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CompareDialogGui::EventHandler ), NULL, this );
	filePickSave->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( CompareDialogGui::filePickSaveOnFileChanged ), NULL, this );
	checkConnectFiles->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CompareDialogGui::EventHandler ), NULL, this );
	btnCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CompareDialogGui::EventHandler ), NULL, this );
	btnCompare->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CompareDialogGui::EventHandler ), NULL, this );
}

CompareDialogGui::~CompareDialogGui()
{
	// Disconnect Events
	filePick1->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( CompareDialogGui::OnFileChange ), NULL, this );
	filePick2->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( CompareDialogGui::OnFileChange ), NULL, this );
	m_radioDifferent->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( CompareDialogGui::EventHandler ), NULL, this );
	m_radioSame->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( CompareDialogGui::EventHandler ), NULL, this );
	checkStopCompare->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CompareDialogGui::EventHandler ), NULL, this );
	checkMergeSection->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CompareDialogGui::EventHandler ), NULL, this );
	checkSaveResults->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CompareDialogGui::EventHandler ), NULL, this );
	filePickSave->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( CompareDialogGui::filePickSaveOnFileChanged ), NULL, this );
	checkConnectFiles->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CompareDialogGui::EventHandler ), NULL, this );
	btnCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CompareDialogGui::EventHandler ), NULL, this );
	btnCompare->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CompareDialogGui::EventHandler ), NULL, this );
	
}

ChecksumDialogGui::ChecksumDialogGui( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerTop;
	bSizerTop = new wxBoxSizer( wxHORIZONTAL );
	
	txtFileToHash = new wxStaticText( this, wxID_ANY, _("File To Hash:"), wxDefaultPosition, wxDefaultSize, 0 );
	txtFileToHash->Wrap( -1 );
	bSizerTop->Add( txtFileToHash, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerDiler;
	bSizerDiler = new wxBoxSizer( wxVERTICAL );
	
	chkFile = new wxCheckBox( this, wxID_ANY, _("Current File"), wxDefaultPosition, wxDefaultSize, 0 );
	chkFile->Enable( false );
	
	bSizerDiler->Add( chkFile, 0, wxALL, 5 );
	
	filePick = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, _("Select a file"), _("*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	bSizerDiler->Add( filePick, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizerTop->Add( bSizerDiler, 1, wxEXPAND, 5 );
	
	
	bSizerMain->Add( bSizerTop, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerHashTypes;
	bSizerHashTypes = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizerMD;
	sbSizerMD = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("MD") ), wxVERTICAL );
	
	chkMD2 = new wxCheckBox( sbSizerMD->GetStaticBox(), wxID_ANY, _("MD2 (slow!)"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerMD->Add( chkMD2, 0, 0, 5 );
	
	chkMD4 = new wxCheckBox( sbSizerMD->GetStaticBox(), wxID_ANY, _("MD4"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerMD->Add( chkMD4, 0, 0, 5 );
	
	chkMD5 = new wxCheckBox( sbSizerMD->GetStaticBox(), wxID_ANY, _("MD5"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerMD->Add( chkMD5, 0, 0, 5 );
	
	
	bSizerHashTypes->Add( sbSizerMD, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerSHA;
	sbSizerSHA = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("SHA") ), wxVERTICAL );
	
	chkSHA1 = new wxCheckBox( sbSizerSHA->GetStaticBox(), wxID_ANY, _("SHA1"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSHA->Add( chkSHA1, 0, 0, 5 );
	
	chkSHA224 = new wxCheckBox( sbSizerSHA->GetStaticBox(), wxID_ANY, _("SHA224"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSHA->Add( chkSHA224, 0, 0, 5 );
	
	chkSHA256 = new wxCheckBox( sbSizerSHA->GetStaticBox(), wxID_ANY, _("SHA256"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSHA->Add( chkSHA256, 0, 0, 5 );
	
	chkSHA384 = new wxCheckBox( sbSizerSHA->GetStaticBox(), wxID_ANY, _("SHA384"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSHA->Add( chkSHA384, 0, 0, 5 );
	
	chkSHA512 = new wxCheckBox( sbSizerSHA->GetStaticBox(), wxID_ANY, _("SHA512"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSHA->Add( chkSHA512, 0, 0, 5 );
	
	
	bSizerHashTypes->Add( sbSizerSHA, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerRIPEMD;
	sbSizerRIPEMD = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("RipeMD") ), wxVERTICAL );
	
	chkRIPEMD128 = new wxCheckBox( sbSizerRIPEMD->GetStaticBox(), wxID_ANY, _("RipeMD128"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerRIPEMD->Add( chkRIPEMD128, 0, 0, 5 );
	
	chkRIPEMD160 = new wxCheckBox( sbSizerRIPEMD->GetStaticBox(), wxID_ANY, _("RipeMD160"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerRIPEMD->Add( chkRIPEMD160, 0, 0, 5 );
	
	chkRIPEMD256 = new wxCheckBox( sbSizerRIPEMD->GetStaticBox(), wxID_ANY, _("RipeMD256"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerRIPEMD->Add( chkRIPEMD256, 0, 0, 5 );
	
	chkRIPEMD320 = new wxCheckBox( sbSizerRIPEMD->GetStaticBox(), wxID_ANY, _("RipeMD320"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerRIPEMD->Add( chkRIPEMD320, 0, 0, 5 );
	
	
	bSizerHashTypes->Add( sbSizerRIPEMD, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerHAVAL;
	sbSizerHAVAL = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("HAVAL") ), wxVERTICAL );
	
	chkHAVAL128 = new wxCheckBox( sbSizerHAVAL->GetStaticBox(), wxID_ANY, _("HAVAL128"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerHAVAL->Add( chkHAVAL128, 0, 0, 5 );
	
	chkHAVAL160 = new wxCheckBox( sbSizerHAVAL->GetStaticBox(), wxID_ANY, _("HAVAL160"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerHAVAL->Add( chkHAVAL160, 0, 0, 5 );
	
	chkHAVAL192 = new wxCheckBox( sbSizerHAVAL->GetStaticBox(), wxID_ANY, _("HAVAL192"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerHAVAL->Add( chkHAVAL192, 0, 0, 5 );
	
	chkHAVAL224 = new wxCheckBox( sbSizerHAVAL->GetStaticBox(), wxID_ANY, _("HAVAL224"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerHAVAL->Add( chkHAVAL224, 0, 0, 5 );
	
	chkHAVAL256 = new wxCheckBox( sbSizerHAVAL->GetStaticBox(), wxID_ANY, _("HAVAL256"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerHAVAL->Add( chkHAVAL256, 0, 0, 5 );
	
	
	bSizerHashTypes->Add( sbSizerHAVAL, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerTIGER;
	sbSizerTIGER = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("TIGER") ), wxVERTICAL );
	
	chkTIGER128 = new wxCheckBox( sbSizerTIGER->GetStaticBox(), wxID_ANY, _("TIGER128"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerTIGER->Add( chkTIGER128, 0, 0, 5 );
	
	chkTIGER160 = new wxCheckBox( sbSizerTIGER->GetStaticBox(), wxID_ANY, _("TIGER160"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerTIGER->Add( chkTIGER160, 0, 0, 5 );
	
	chkTIGER = new wxCheckBox( sbSizerTIGER->GetStaticBox(), wxID_ANY, _("TIGER192"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerTIGER->Add( chkTIGER, 0, 0, 5 );
	
	
	bSizerHashTypes->Add( sbSizerTIGER, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerOthers;
	sbSizerOthers = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Others") ), wxVERTICAL );
	
	chkADLER32 = new wxCheckBox( sbSizerOthers->GetStaticBox(), wxID_ANY, _("ADLER32"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerOthers->Add( chkADLER32, 0, 0, 5 );
	
	chkCRC32 = new wxCheckBox( sbSizerOthers->GetStaticBox(), wxID_ANY, _("CRC32"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerOthers->Add( chkCRC32, 0, 0, 5 );
	
	chkCRC32B = new wxCheckBox( sbSizerOthers->GetStaticBox(), wxID_ANY, _("CRC32B"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerOthers->Add( chkCRC32B, 0, 0, 5 );
	
	chkWHIRLPOOL = new wxCheckBox( sbSizerOthers->GetStaticBox(), wxID_ANY, _("WHIRLPOOL"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerOthers->Add( chkWHIRLPOOL, 0, 0, 5 );
	
	chkGOST = new wxCheckBox( sbSizerOthers->GetStaticBox(), wxID_ANY, _("GOST"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerOthers->Add( chkGOST, 0, 0, 5 );
	
	chkSNEFRU128 = new wxCheckBox( sbSizerOthers->GetStaticBox(), wxID_ANY, _("SNEFRU128"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerOthers->Add( chkSNEFRU128, 0, 0, 5 );
	
	chkSNEFRU256 = new wxCheckBox( sbSizerOthers->GetStaticBox(), wxID_ANY, _("SNEFRU256"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerOthers->Add( chkSNEFRU256, 0, 0, 5 );
	
	
	bSizerHashTypes->Add( sbSizerOthers, 1, wxEXPAND, 5 );
	
	
	bSizerMain->Add( bSizerHashTypes, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerButtons;
	bSizerButtons = new wxBoxSizer( wxHORIZONTAL );
	
	btnCancel = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerButtons->Add( btnCancel, 1, wxALL|wxEXPAND, 5 );
	
	btnCalculate = new wxButton( this, wxID_ANY, _("Calculate"), wxDefaultPosition, wxDefaultSize, 0 );
	btnCalculate->SetDefault(); 
	btnCalculate->Enable( false );
	
	bSizerButtons->Add( btnCalculate, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerMain->Add( bSizerButtons, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizerMain );
	this->Layout();
	bSizerMain->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	chkFile->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	filePick->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( ChecksumDialogGui::OnFileChange ), NULL, this );
	chkMD2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkMD4->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkMD5->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkSHA1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkSHA224->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkSHA256->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkSHA384->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkSHA512->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkRIPEMD128->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkRIPEMD160->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkRIPEMD256->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkRIPEMD320->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkHAVAL128->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkHAVAL160->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkHAVAL192->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkHAVAL224->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkHAVAL256->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkTIGER128->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkTIGER160->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkTIGER->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkADLER32->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkCRC32->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkCRC32B->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkWHIRLPOOL->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkGOST->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkSNEFRU128->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkSNEFRU256->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	btnCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	btnCalculate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
}

ChecksumDialogGui::~ChecksumDialogGui()
{
	// Disconnect Events
	chkFile->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	filePick->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( ChecksumDialogGui::OnFileChange ), NULL, this );
	chkMD2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkMD4->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkMD5->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkSHA1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkSHA224->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkSHA256->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkSHA384->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkSHA512->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkRIPEMD128->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkRIPEMD160->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkRIPEMD256->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkRIPEMD320->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkHAVAL128->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkHAVAL160->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkHAVAL192->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkHAVAL224->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkHAVAL256->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkTIGER128->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkTIGER160->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkTIGER->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkADLER32->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkCRC32->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkCRC32B->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkWHIRLPOOL->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkGOST->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkSNEFRU128->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	chkSNEFRU256->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	btnCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	btnCalculate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChecksumDialogGui::EventHandler ), NULL, this );
	
}

CopyAsDialogGui::CopyAsDialogGui( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizerSelections;
	fgSizerSelections = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizerSelections->AddGrowableCol( 1 );
	fgSizerSelections->SetFlexibleDirection( wxBOTH );
	fgSizerSelections->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	txtCopyAs = new wxStaticText( this, wxID_ANY, _("Copy As :"), wxDefaultPosition, wxDefaultSize, 0 );
	txtCopyAs->Wrap( -1 );
	fgSizerSelections->Add( txtCopyAs, 0, wxALIGN_CENTER|wxALL, 5 );
	
	wxString chcCopyAsChoices[] = { _("Full Text"), _("Special Hex"), _("Internet"), _("C/C++ Source"), _("Assembler Source") };
	int chcCopyAsNChoices = sizeof( chcCopyAsChoices ) / sizeof( wxString );
	chcCopyAs = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, chcCopyAsNChoices, chcCopyAsChoices, 0 );
	chcCopyAs->SetSelection( 0 );
	fgSizerSelections->Add( chcCopyAs, 1, wxALL|wxEXPAND, 5 );
	
	txtOption = new wxStaticText( this, wxID_ANY, _("Option:"), wxDefaultPosition, wxDefaultSize, 0 );
	txtOption->Wrap( -1 );
	fgSizerSelections->Add( txtOption, 0, wxALIGN_CENTER|wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	wxArrayString chcOptionChoices;
	chcOption = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, chcOptionChoices, 0 );
	chcOption->SetSelection( 0 );
	chcOption->Enable( false );
	
	fgSizerSelections->Add( chcOption, 1, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	bSizerMain->Add( fgSizerSelections, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerMiddle;
	bSizerMiddle = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizerLeft;
	bSizerLeft = new wxBoxSizer( wxVERTICAL );
	
	chkBigEndian = new wxCheckBox( this, wxID_ANY, _("As BigEndian"), wxDefaultPosition, wxDefaultSize, 0 );
	chkBigEndian->Enable( false );
	
	bSizerLeft->Add( chkBigEndian, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	wxStaticBoxSizer* sbSizerBPL;
	sbSizerBPL = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Bytes Per Line") ), wxVERTICAL );
	
	spnBytePerLine = new wxSpinCtrl( sbSizerBPL->GetStaticBox(), wxID_ANY, _("16"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 8, 1024, 0 );
	sbSizerBPL->Add( spnBytePerLine, 0, wxALIGN_RIGHT, 5 );
	
	
	bSizerLeft->Add( sbSizerBPL, 1, wxEXPAND, 5 );
	
	
	bSizerMiddle->Add( bSizerLeft, 0, 0, 5 );
	
	wxBoxSizer* bSizerRight;
	bSizerRight = new wxBoxSizer( wxVERTICAL );
	
	chkOffset = new wxCheckBox( this, wxID_ANY, _("Include Offset Part"), wxDefaultPosition, wxDefaultSize, 0 );
	chkOffset->SetValue(true); 
	bSizerRight->Add( chkOffset, 1, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	chkHex = new wxCheckBox( this, wxID_ANY, _("Include Hex Part"), wxDefaultPosition, wxDefaultSize, 0 );
	chkHex->SetValue(true); 
	bSizerRight->Add( chkHex, 1, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	chkText = new wxCheckBox( this, wxID_ANY, _("Include Text Part"), wxDefaultPosition, wxDefaultSize, 0 );
	chkText->SetValue(true); 
	bSizerRight->Add( chkText, 1, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	
	bSizerMiddle->Add( bSizerRight, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerMain->Add( bSizerMiddle, 0, 0, 5 );
	
	wxBoxSizer* bSizerButtons;
	bSizerButtons = new wxBoxSizer( wxHORIZONTAL );
	
	btnCancel = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerButtons->Add( btnCancel, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	btnCopy = new wxButton( this, wxID_OK, _("Copy"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerButtons->Add( btnCopy, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerMain->Add( bSizerButtons, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	this->SetSizer( bSizerMain );
	this->Layout();
	bSizerMain->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	chcCopyAs->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( CopyAsDialogGui::EventHandler ), NULL, this );
	chcOption->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( CopyAsDialogGui::EventHandler ), NULL, this );
	chkBigEndian->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CopyAsDialogGui::EventHandler ), NULL, this );
	btnCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CopyAsDialogGui::EventHandler ), NULL, this );
	btnCopy->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CopyAsDialogGui::EventHandler ), NULL, this );
}

CopyAsDialogGui::~CopyAsDialogGui()
{
	// Disconnect Events
	chcCopyAs->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( CopyAsDialogGui::EventHandler ), NULL, this );
	chcOption->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( CopyAsDialogGui::EventHandler ), NULL, this );
	chkBigEndian->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CopyAsDialogGui::EventHandler ), NULL, this );
	btnCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CopyAsDialogGui::EventHandler ), NULL, this );
	btnCopy->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CopyAsDialogGui::EventHandler ), NULL, this );
	
}

XORViewDialogGui::XORViewDialogGui( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxVERTICAL );
	
	txtWarning = new wxStaticText( this, wxID_ANY, _("For switching XORView Thru mode, all Undo&Redo buffer will reset and non-saved changes will discarded.\nAlso you can't use methods that changes file size (like delete and inject) with XORView Thru mode enabled."), wxDefaultPosition, wxDefaultSize, 0 );
	txtWarning->Wrap( -1 );
	bSizerMain->Add( txtWarning, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	wxBoxSizer* bSizerRadio;
	bSizerRadio = new wxBoxSizer( wxHORIZONTAL );
	
	txtSelection = new wxStaticText( this, wxID_ANY, _("Please enter XOR key as "), wxDefaultPosition, wxDefaultSize, 0 );
	txtSelection->Wrap( -1 );
	bSizerRadio->Add( txtSelection, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	radioASCII = new wxRadioButton( this, wxID_ANY, _("ASCII"), wxDefaultPosition, wxDefaultSize, 0 );
	radioASCII->SetValue( true ); 
	bSizerRadio->Add( radioASCII, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	radioHex = new wxRadioButton( this, wxID_ANY, _("Hex"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerRadio->Add( radioHex, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );
	
	XORtext = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizerRadio->Add( XORtext, 1, wxALIGN_CENTER|wxLEFT, 5 );
	
	
	bSizerMain->Add( bSizerRadio, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerButtons;
	bSizerButtons = new wxBoxSizer( wxHORIZONTAL );
	
	btnCancel = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerButtons->Add( btnCancel, 0, wxALL, 5 );
	
	btnOK = new wxButton( this, wxID_OK, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerButtons->Add( btnOK, 0, wxALL, 5 );
	
	
	bSizerMain->Add( bSizerButtons, 1, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizerMain );
	this->Layout();
	bSizerMain->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	XORtext->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( XORViewDialogGui::EventHandler ), NULL, this );
	XORtext->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( XORViewDialogGui::EventHandler ), NULL, this );
	btnCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( XORViewDialogGui::EventHandler ), NULL, this );
	btnOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( XORViewDialogGui::EventHandler ), NULL, this );
}

XORViewDialogGui::~XORViewDialogGui()
{
	// Disconnect Events
	XORtext->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( XORViewDialogGui::EventHandler ), NULL, this );
	XORtext->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( XORViewDialogGui::EventHandler ), NULL, this );
	btnCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( XORViewDialogGui::EventHandler ), NULL, this );
	btnOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( XORViewDialogGui::EventHandler ), NULL, this );
	
}

PreferencesDialogGui::PreferencesDialogGui( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 500,-1 ), wxDefaultSize );
	
	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerColour;
	sbSizerColour = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Colours") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizerColours;
	fgSizerColours = new wxFlexGridSizer( 2, 4, 0, 0 );
	fgSizerColours->SetFlexibleDirection( wxBOTH );
	fgSizerColours->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	txtBtn = new wxStaticText( sbSizerColour->GetStaticBox(), wxID_ANY, _("Hex Colors:"), wxDefaultPosition, wxDefaultSize, 0 );
	txtBtn->Wrap( -1 );
	fgSizerColours->Add( txtBtn, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	clrPickerForeground = new wxColourPickerCtrl( sbSizerColour->GetStaticBox(), wxID_ANY, wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	clrPickerForeground->SetToolTip( _("Foreground Colour") );
	
	fgSizerColours->Add( clrPickerForeground, 0, wxALL, 5 );
	
	clrPickerBackground = new wxColourPickerCtrl( sbSizerColour->GetStaticBox(), wxID_ANY, wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	clrPickerBackground->SetToolTip( _("Background Colour") );
	
	fgSizerColours->Add( clrPickerBackground, 0, wxALL, 5 );
	
	clrPickerBackgroundZebra = new wxColourPickerCtrl( sbSizerColour->GetStaticBox(), wxID_ANY, wxColour( 238, 238, 255 ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	clrPickerBackgroundZebra->SetToolTip( _("Zebra Colour") );
	
	fgSizerColours->Add( clrPickerBackgroundZebra, 0, wxALL, 5 );
	
	txtSelection = new wxStaticText( sbSizerColour->GetStaticBox(), wxID_ANY, _("Selection Colours:"), wxDefaultPosition, wxDefaultSize, 0 );
	txtSelection->Wrap( -1 );
	fgSizerColours->Add( txtSelection, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	clrPickerSelectionForeground = new wxColourPickerCtrl( sbSizerColour->GetStaticBox(), wxID_ANY, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	clrPickerSelectionForeground->SetToolTip( _("Selection Foreground Colour") );
	
	fgSizerColours->Add( clrPickerSelectionForeground, 0, wxALL, 5 );
	
	clrPickerSelectionBackground = new wxColourPickerCtrl( sbSizerColour->GetStaticBox(), wxID_ANY, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	clrPickerSelectionBackground->SetToolTip( _("Selection Colour") );
	
	fgSizerColours->Add( clrPickerSelectionBackground, 0, wxALL, 5 );
	
	btnResetColours = new wxButton( sbSizerColour->GetStaticBox(), wxID_ANY, _("Reset"), wxDefaultPosition, wxDefaultSize, 0 );
	btnResetColours->SetToolTip( _("Reset Colour Values to Default") );
	
	fgSizerColours->Add( btnResetColours, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	
	sbSizerColour->Add( fgSizerColours, 1, wxEXPAND|wxALL, 5 );
	
	
	bSizerMain->Add( sbSizerColour, 1, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizerLang;
	bSizerLang = new wxBoxSizer( wxHORIZONTAL );
	
	txtLang = new wxStaticText( this, wxID_ANY, _("Language:"), wxDefaultPosition, wxDefaultSize, 0 );
	txtLang->Wrap( -1 );
	bSizerLang->Add( txtLang, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString chcLangChoices;
	chcLang = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, chcLangChoices, 0 );
	chcLang->SetSelection( 0 );
	bSizerLang->Add( chcLang, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerMain->Add( bSizerLang, 0, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizerCharacterEncodings;
	bSizerCharacterEncodings = new wxBoxSizer( wxHORIZONTAL );
	
	txtCharacterFamily = new wxStaticText( this, wxID_ANY, _("Character Encoding Family:"), wxDefaultPosition, wxDefaultSize, 0 );
	txtCharacterFamily->Wrap( -1 );
	bSizerCharacterEncodings->Add( txtCharacterFamily, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString chcCharacterEncodingFamilyChoices;
	chcCharacterEncodingFamily = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, chcCharacterEncodingFamilyChoices, 0 );
	chcCharacterEncodingFamily->SetSelection( 0 );
	bSizerCharacterEncodings->Add( chcCharacterEncodingFamily, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerMain->Add( bSizerCharacterEncodings, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerSubCharacterEncodings;
	bSizerSubCharacterEncodings = new wxBoxSizer( wxHORIZONTAL );
	
	txtCharacterEncoding = new wxStaticText( this, wxID_ANY, _("Character Encoding:"), wxDefaultPosition, wxDefaultSize, 0 );
	txtCharacterEncoding->Wrap( -1 );
	bSizerSubCharacterEncodings->Add( txtCharacterEncoding, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString chcCharacterEncodingChoices;
	chcCharacterEncoding = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, chcCharacterEncodingChoices, 0 );
	chcCharacterEncoding->SetSelection( 0 );
	bSizerSubCharacterEncodings->Add( chcCharacterEncoding, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	txtfontSize = new wxStaticText( this, wxID_ANY, _("Size:"), wxDefaultPosition, wxDefaultSize, 0 );
	txtfontSize->Wrap( -1 );
	bSizerSubCharacterEncodings->Add( txtfontSize, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	spinFontSize = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 100, 10 );
	bSizerSubCharacterEncodings->Add( spinFontSize, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerMain->Add( bSizerSubCharacterEncodings, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerFormat;
	sbSizerFormat = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Custom Hex Formating") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizerCustomFormat;
	fgSizerCustomFormat = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizerCustomFormat->AddGrowableCol( 0 );
	fgSizerCustomFormat->SetFlexibleDirection( wxBOTH );
	fgSizerCustomFormat->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	comboCustomHexFormat = new wxComboBox( sbSizerFormat->GetStaticBox(), wxID_ANY, _("xx "), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	comboCustomHexFormat->Append( _("xxxx ") );
	comboCustomHexFormat->Append( _("xx xx xx xx xx xx xx xx  ") );
	comboCustomHexFormat->Append( _("xxxx xxxx xxxx xxxx  ") );
	comboCustomHexFormat->Enable( false );
	comboCustomHexFormat->SetToolTip( _("Recursive custom hex format pattern") );
	
	fgSizerCustomFormat->Add( comboCustomHexFormat, 1, wxALL|wxEXPAND, 5 );
	
	chkCustom = new wxCheckBox( sbSizerFormat->GetStaticBox(), wxID_ANY, _("Enable"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizerCustomFormat->Add( chkCustom, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizerFormat->Add( fgSizerCustomFormat, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerBytePerLine;
	bSizerBytePerLine = new wxBoxSizer( wxHORIZONTAL );
	
	chkBytePerLineLimit = new wxCheckBox( sbSizerFormat->GetStaticBox(), wxID_ANY, _("Bytes Per Line Limit"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerBytePerLine->Add( chkBytePerLineLimit, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	spinBytePerLine = new wxSpinCtrl( sbSizerFormat->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 256, 8 );
	spinBytePerLine->Enable( false );
	
	bSizerBytePerLine->Add( spinBytePerLine, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	sbSizerFormat->Add( bSizerBytePerLine, 0, 0, 5 );
	
	
	bSizerMain->Add( sbSizerFormat, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerTags;
	bSizerTags = new wxBoxSizer( wxVERTICAL );
	
	chkAutoShowTagPanel = new wxCheckBox( this, wxID_ANY, _("Auto show tag panel if tags detected"), wxDefaultPosition, wxDefaultSize, 0 );
	chkAutoShowTagPanel->SetValue(true); 
	bSizerTags->Add( chkAutoShowTagPanel, 0, wxALL, 5 );
	
	chkPortable = new wxCheckBox( this, wxID_ANY, _("Make program portable "), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerTags->Add( chkPortable, 0, wxALL, 5 );
	
	chkSingleInstance = new wxCheckBox( this, wxID_ANY, _("Single instance mode"), wxDefaultPosition, wxDefaultSize, 0 );
	chkSingleInstance->SetToolTip( _("Allows only one copy of the programx running at a time.\nOpening new files open new tabs on the program.") );
	
	bSizerTags->Add( chkSingleInstance, 0, wxALL, 5 );
	
	
	bSizerMain->Add( bSizerTags, 0, 0, 5 );
	
	wxBoxSizer* bSizerBtns;
	bSizerBtns = new wxBoxSizer( wxHORIZONTAL );
	
	BtnCancel = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerBtns->Add( BtnCancel, 0, wxALL, 5 );
	
	BtnSave = new wxButton( this, wxID_SAVE, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerBtns->Add( BtnSave, 0, wxALL, 5 );
	
	
	bSizerMain->Add( bSizerBtns, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	this->SetSizer( bSizerMain );
	this->Layout();
	bSizerMain->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	clrPickerForeground->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	clrPickerBackground->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	clrPickerBackgroundZebra->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	clrPickerSelectionForeground->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	clrPickerSelectionBackground->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	btnResetColours->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PreferencesDialogGui::OnResetColours ), NULL, this );
	chcCharacterEncodingFamily->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	chcCharacterEncoding->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	spinFontSize->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( PreferencesDialogGui::SpinEventHandler ), NULL, this );
	spinFontSize->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	comboCustomHexFormat->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	comboCustomHexFormat->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	comboCustomHexFormat->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	chkCustom->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	chkBytePerLineLimit->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	spinBytePerLine->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	spinBytePerLine->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	chkPortable->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	BtnSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PreferencesDialogGui::OnSave ), NULL, this );
}

PreferencesDialogGui::~PreferencesDialogGui()
{
	// Disconnect Events
	clrPickerForeground->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	clrPickerBackground->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	clrPickerBackgroundZebra->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	clrPickerSelectionForeground->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	clrPickerSelectionBackground->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	btnResetColours->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PreferencesDialogGui::OnResetColours ), NULL, this );
	chcCharacterEncodingFamily->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	chcCharacterEncoding->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	spinFontSize->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( PreferencesDialogGui::SpinEventHandler ), NULL, this );
	spinFontSize->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	comboCustomHexFormat->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	comboCustomHexFormat->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	comboCustomHexFormat->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	chkCustom->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	chkBytePerLineLimit->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	spinBytePerLine->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	spinBytePerLine->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	chkPortable->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PreferencesDialogGui::EventHandler ), NULL, this );
	BtnSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PreferencesDialogGui::OnSave ), NULL, this );
	
}

DeviceBackupDialogGui::DeviceBackupDialogGui( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* MainSizer;
	MainSizer = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizerSourceDestination;
	fgSizerSourceDestination = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizerSourceDestination->AddGrowableCol( 1 );
	fgSizerSourceDestination->SetFlexibleDirection( wxHORIZONTAL );
	fgSizerSourceDestination->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	txtSource = new wxStaticText( this, wxID_ANY, _("Source :"), wxDefaultPosition, wxDefaultSize, 0 );
	txtSource->Wrap( -1 );
	fgSizerSourceDestination->Add( txtSource, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString chcPartitionChoices;
	chcPartition = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 300,-1 ), chcPartitionChoices, 0 );
	chcPartition->SetSelection( 0 );
	fgSizerSourceDestination->Add( chcPartition, 1, wxALL|wxEXPAND, 5 );
	
	txtDestination = new wxStaticText( this, wxID_ANY, _("Destination :"), wxDefaultPosition, wxDefaultSize, 0 );
	txtDestination->Wrap( -1 );
	fgSizerSourceDestination->Add( txtDestination, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	filePickBackup = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, _("Select a file"), _("*"), wxDefaultPosition, wxDefaultSize, wxFLP_OVERWRITE_PROMPT|wxFLP_SAVE|wxFLP_USE_TEXTCTRL );
	fgSizerSourceDestination->Add( filePickBackup, 0, wxALL|wxEXPAND, 5 );
	
	
	MainSizer->Add( fgSizerSourceDestination, 0, wxEXPAND, 5 );
	
	wxBoxSizer* ButtonSizer;
	ButtonSizer = new wxBoxSizer( wxHORIZONTAL );
	
	btnCancel = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	ButtonSizer->Add( btnCancel, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	btnBackup = new wxButton( this, wxID_ANY, _("Backup"), wxDefaultPosition, wxDefaultSize, 0 );
	ButtonSizer->Add( btnBackup, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	MainSizer->Add( ButtonSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	this->SetSizer( MainSizer );
	this->Layout();
	MainSizer->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	btnBackup->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DeviceBackupDialogGui::OnBackup ), NULL, this );
}

DeviceBackupDialogGui::~DeviceBackupDialogGui()
{
	// Disconnect Events
	btnBackup->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DeviceBackupDialogGui::OnBackup ), NULL, this );
	
}

DeviceRestoreDialogGui::DeviceRestoreDialogGui( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* MainSizer;
	MainSizer = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizerSourceDestination;
	fgSizerSourceDestination = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizerSourceDestination->AddGrowableCol( 1 );
	fgSizerSourceDestination->SetFlexibleDirection( wxBOTH );
	fgSizerSourceDestination->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	txtSource = new wxStaticText( this, wxID_ANY, _("Source :"), wxDefaultPosition, wxDefaultSize, 0 );
	txtSource->Wrap( -1 );
	fgSizerSourceDestination->Add( txtSource, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	filePickBackup = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, _("Select a file"), _("*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE|wxFLP_FILE_MUST_EXIST|wxFLP_OPEN|wxFLP_USE_TEXTCTRL );
	fgSizerSourceDestination->Add( filePickBackup, 0, wxALL|wxEXPAND, 5 );
	
	txtDestination = new wxStaticText( this, wxID_ANY, _("Destination :"), wxDefaultPosition, wxDefaultSize, 0 );
	txtDestination->Wrap( -1 );
	fgSizerSourceDestination->Add( txtDestination, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString chcPartitionChoices;
	chcPartition = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 300,-1 ), chcPartitionChoices, 0 );
	chcPartition->SetSelection( 0 );
	fgSizerSourceDestination->Add( chcPartition, 0, wxALL|wxEXPAND, 5 );
	
	
	MainSizer->Add( fgSizerSourceDestination, 1, wxEXPAND, 5 );
	
	wxBoxSizer* ButtonSizer;
	ButtonSizer = new wxBoxSizer( wxHORIZONTAL );
	
	btnCancel = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	ButtonSizer->Add( btnCancel, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	btnRestore = new wxButton( this, wxID_ANY, _("Restore"), wxDefaultPosition, wxDefaultSize, 0 );
	ButtonSizer->Add( btnRestore, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	MainSizer->Add( ButtonSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	this->SetSizer( MainSizer );
	this->Layout();
	MainSizer->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	btnRestore->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DeviceRestoreDialogGui::OnRestore ), NULL, this );
}

DeviceRestoreDialogGui::~DeviceRestoreDialogGui()
{
	// Disconnect Events
	btnRestore->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DeviceRestoreDialogGui::OnRestore ), NULL, this );
	
}

DeviceEraseDialogGui::DeviceEraseDialogGui( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* MainSizer;
	MainSizer = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizerSourceDestination;
	fgSizerSourceDestination = new wxFlexGridSizer( 1, 2, 0, 0 );
	fgSizerSourceDestination->AddGrowableCol( 1 );
	fgSizerSourceDestination->SetFlexibleDirection( wxBOTH );
	fgSizerSourceDestination->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	txtDestination = new wxStaticText( this, wxID_ANY, _("Destination :"), wxDefaultPosition, wxDefaultSize, 0 );
	txtDestination->Wrap( -1 );
	fgSizerSourceDestination->Add( txtDestination, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString chcPartitionChoices;
	chcPartition = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 300,-1 ), chcPartitionChoices, 0 );
	chcPartition->SetSelection( 0 );
	fgSizerSourceDestination->Add( chcPartition, 0, wxALL|wxEXPAND, 5 );
	
	
	MainSizer->Add( fgSizerSourceDestination, 0, wxEXPAND, 5 );
	
	wxString radioEraseChoices[] = { _("0x00"), _("0xFF"), _("0xRANDOM") };
	int radioEraseNChoices = sizeof( radioEraseChoices ) / sizeof( wxString );
	radioErase = new wxRadioBox( this, wxID_ANY, _("Erase With "), wxDefaultPosition, wxDefaultSize, radioEraseNChoices, radioEraseChoices, 1, wxRA_SPECIFY_ROWS );
	radioErase->SetSelection( 0 );
	MainSizer->Add( radioErase, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* ButtonSizer;
	ButtonSizer = new wxBoxSizer( wxHORIZONTAL );
	
	btnCancel = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	ButtonSizer->Add( btnCancel, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	btnErase = new wxButton( this, wxID_ANY, _("Erase"), wxDefaultPosition, wxDefaultSize, 0 );
	ButtonSizer->Add( btnErase, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	MainSizer->Add( ButtonSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	this->SetSizer( MainSizer );
	this->Layout();
	MainSizer->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	btnErase->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DeviceEraseDialogGui::OnErase ), NULL, this );
}

DeviceEraseDialogGui::~DeviceEraseDialogGui()
{
	// Disconnect Events
	btnErase->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DeviceEraseDialogGui::OnErase ), NULL, this );
	
}

OSXMessageDialogGui::OSXMessageDialogGui( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxHORIZONTAL );
	
	icon_bitmap = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	bSizerMain->Add( icon_bitmap, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxVERTICAL );
	
	txtCaption = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	txtCaption->Wrap( -1 );
	txtCaption->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );
	
	bSizer51->Add( txtCaption, 0, wxALL, 5 );
	
	txtMessage = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	txtMessage->Wrap( -1 );
	bSizer51->Add( txtMessage, 0, wxALL, 5 );
	
	btnOK = new wxButton( this, wxID_OK, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer51->Add( btnOK, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	
	bSizerMain->Add( bSizer51, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizerMain );
	this->Layout();
	bSizerMain->Fit( this );
	
	this->Centre( wxBOTH );
}

OSXMessageDialogGui::~OSXMessageDialogGui()
{
}
