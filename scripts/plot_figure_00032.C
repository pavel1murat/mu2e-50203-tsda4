//-----------------------------------------------------------------------------
// bpim0b0s24 and 
//-----------------------------------------------------------------------------
plot_data_t* plot_figure_00032(int Figure, int Print) {
    
  const char* neut0b0s34 = "pipenu.neut0b0s31r0000";
  const char* neut1b0s34 = "pipenu.neut1b0s31r0000";

  const char* book       = "pipenu";
  const char* prod_job   = "detstepana.0000";
  const char* hist_name  = "/DetStepAna/DetStepAna/cal/edep";

  plot_data_t* pdata     = new plot_data_t(2);   // 3 histograms overlaid
  plot_data_t& p         = *pdata;
//-----------------------------------------------------------------------------
// histograms made by the production job
//------------------------------------------------------------------------------
  p.hd[0]              = hist_data_t(catalog,book,neut0b0s34,prod_job,hist_name);
  p.hd[0].fNewName     = "tsda4";
  p.hd[0].fRebin       = 1;
  p.hd[0].fLabel       = "TSdA4";
  // p.hd[1].fMarkerColor = kBlue;
  // p.hd[1].fMarkerStyle = 21;
  // p.hd[1].fMarkerSize  = 0.8;
  p.hd[0].fLineWidth   = 2;
  p.hd[0].fDrawOpt     = "h";
  //  p.hd[1].fLumiSF      = gPipenu->GetChannel("rpc04bs44r0000")->NormSF();

  p.hd[1]              = hist_data_t(catalog,book,neut1b0s34,prod_job,hist_name);
  p.hd[1].fNewName     = "no_tsda4";
  p.hd[1].fRebin       = 1;
  p.hd[1].fLabel       = "no TSdA4";
  // p.hd[0].fMarkerColor = kRed+1;
  // p.hd[0].fMarkerStyle = 20;
  p.hd[1].fDrawOpt     = "h";
  //  p.hd[0].
  // p.fXMin              = 0.;
  // p.fXMax              = 300;
  // p.fYMin              = 1e-1;
  // p.fYMax              = 2e3;
  p.fCanvasName        = Form("Figure_%04i",Figure);
  p.fName              = Form("figure_%05i",Figure);
  p.fLabel             = "";
  p.fXAxisTitle        = "EDep, MeV";
  p.fYLogScale         = 1;

  p.fStatBoxXMin       = 0.70;
  p.fStatBoxXMax       = 0.90;
  p.fStatBoxYMax       = 0.90;
  p.fStatBoxYMin       = 0.70;

  p.fLegendXMin        = 0.45; p.fLegendXMax  = 0.65; p.fLegendYMin  = 0.7; p.fLegendYMax  = 0.85; 
    
  plot_hist_1d(&p,-1);

  p.fCanvas->Modified();
  p.fCanvas->Update();

  // TArrow* arr = new TArrow(200,100,200,20,0.015);
  // arr->Draw();

  printf(" plot.C p.fOutputFn = %s\n",p.fOutputFn.Data());
    
  if (Print == 1) p.print() ;

  return pdata;
}
