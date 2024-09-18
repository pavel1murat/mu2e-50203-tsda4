///////////////////////////////////////////////////////////////////////////////
// HistDir and FiguresDir have to be defined before init_local_files.C
// always print in .eps, convert to .png or .pdf in GNUMakefile
//
///////////////////////////////////////////////////////////////////////////////
const char* Mu2eNotesDir        = "/exp/mu2e/data/projects/pipenu/notes";     // mu2egpvm*
const char* Mu2eTalksDir        = "/exp/mu2e/data/projects/pipenu/talks";     // mu2egpvm*
const char* Mu2eHistDir         = "/exp/mu2e/data/projects/pipenu/hist";      // mu2egpvm*

const char* NoteRepo            = "mu2e-50203-tsda4";

char  FiguresDir    [500] = "";
char  pipenu_HistDir[500] = "";

double BR_pienu   = 1.23e-4;
double NPOT_pienu = 2.5e8;          // 500(s1 jobs)x500,000(events per s1 job)

#include <stdio.h>
#include <string.h>
#include "Stntuple/val/stn_catalog.hh"
#include "Stntuple/scripts/plot_hist_1D.C"
#include "Stntuple/scripts/plot_hist_2D.C"
#include "pipenu/ana/Analysis.hh"

stn_catalog*      catalog;           // has to be global
pipenu::Analysis* gPipenu;           // same

#include "pipenu/ana/scripts/init_pipenu_datasets.C"

#include "plot_figure_00011.C"           // ns_trk 
#include "plot_figure_00012.C"           // ns_cal

#include "plot_figure_00021.C"           // sgs mom
#include "plot_figure_00022.C"           // sgs edep
#include "plot_figure_00023.C"           // sgs time

#include "plot_figure_00031.C"           // cal mom
#include "plot_figure_00032.C"           // cal edep
#include "plot_figure_00033.C"           // cal time
//-----------------------------------------------------------------------------
// real [machine-dependent] values of Mu2eNotesDir and Mu2eHistDir 
// should be defined in .rootrc
// it is assumed that the note has been checed out into $mu2e.NotesDir/$NoteRepo
// and all needed histograms are located in $mu2e.HistDir/su2020
// this is a talk !!
//-----------------------------------------------------------------------------
void init() {
  
  stn_book* book;

  const char* notes_dir = gEnv->GetValue("mu2e.NotesDir",Mu2eTalksDir);
  sprintf(FiguresDir,"%s/%s/figures",notes_dir,NoteRepo);
  gEnv->SetValue("FiguresDir",FiguresDir);

  const char* hist_dir = gEnv->GetValue("mu2e.pipenu.HistDir",Mu2eHistDir);
  sprintf(pipenu_HistDir,"%s",hist_dir);

  catalog = new stn_catalog("my");
  
  book = new stn_book("pipenu",pipenu_HistDir);
  init_pipenu_datasets(book);
  catalog->AddBook(book);

  gPipenu = new pipenu::Analysis("a");
  
  printf(" after init_local\n");
}

//-----------------------------------------------------------------------------
plot_data_t* plot(int Figure, int Print = 0) {
  plot_data_t* pdata;

  init();
//-----------------------------------------------------------------------------
// fig   10, 13: 
//-----------------------------------------------------------------------------
  if      (Figure ==   11) pdata = plot_figure_00011(Figure,Print);  //
  if      (Figure ==   12) pdata = plot_figure_00012(Figure,Print);  //

  if      (Figure ==   21) pdata = plot_figure_00021(Figure,Print);  // sgs mom
  if      (Figure ==   22) pdata = plot_figure_00022(Figure,Print);  // sgs edep
  if      (Figure ==   23) pdata = plot_figure_00023(Figure,Print);  // sgs time

  if      (Figure ==   31) pdata = plot_figure_00031(Figure,Print);  // cal mom
  if      (Figure ==   32) pdata = plot_figure_00032(Figure,Print);  // cal edep
  if      (Figure ==   33) pdata = plot_figure_00033(Figure,Print);  // cal time

  return pdata;
}
