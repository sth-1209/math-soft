TEX_FILE = navier-stokes.tex
BIB_FILE = references.bib
PDF_FILE = navier-stokes.pdf

all: $(PDF_FILE)

$(PDF_FILE): $(TEX_FILE) $(BIB_FILE)
	xelatex $(TEX_FILE)
	bibtex $(basename $(TEX_FILE))
	xelatex $(TEX_FILE)
	xelatex $(TEX_FILE)

clean:
	rm -f *.aux *.log *.pdf \
	*.toc *.snm *.nav *.out \
	*.thm *.bbl *.ps *.dvi *.blg \
	*.bcf *.xml
.PHONY: all clean