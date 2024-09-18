#------------------------------------------------------------------------------
# primary source: .eps
# store ROOT plots in .eps format, make .png and .pdf out of .eps files
#------------------------------------------------------------------------------
dir=.

note       := mu2e-50203
# bkg_table  := background_optimized_standalone

tex_files := $(note).tex # $(wildcard *.tex)

pdfs := $(patsubst figures/eps/%.eps, figures/pdf/%.pdf,  $(wildcard figures/eps/*.eps ))

pngs := $(patsubst figures/eps/%.eps, figures/png/%.png, $(wildcard figures/eps/*.eps ))

figures/pdf/%.pdf: figures/eps/%.eps
	ps2pdf -dEPSCrop $? $@

figures/png/%.png: figures/eps/%.eps
	convert -density 400 -depth 8 -quality 85 -trim  $? $@

pdf: $(pdfs) 
# 	echo $?
png: $(pngs) 
# 	echo $?

note: $(tex_files) pdf 
	if [ ! -d tmp ] ; then mkdir tmp ; fi ; \
	echo BIBINPUTS=$$BIBINPUTS ; \
	pdflatex -output-directory=tmp $^ ; \
	cd tmp ; \
	bibtex $(note) ; \
	cd .. ; \
	pdflatex -output-directory=tmp $^

table: $(bkg_table).tex
	if [ ! -d tmp ]; then mkdir tmp; fi; \
	pdflatex -output-directory=tmp $^;
	pdftops -eps tmp/$(bkg_table).pdf figures/eps/$(bkg_table).eps

all: pdf note table
	echo $(pdfs)
	echo $?
