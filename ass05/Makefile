PROJ = lsq
SRC_DIR=./src
DOC_DIR=./doc
GENDATA := $(PROJ)_data
DATA = testdata.txt
IMAGE = $(DOC_DIR)/output.eps
REF = $(DOC_DIR)/references.bib
PDF = $(DOC_DIR)/$(PROJ).pdf

all: $(PROJ) $(GENDATA) $(DATA) $(IMAGE) $(PDF)

$(PROJ): $(SRC_DIR)/$(PROJ).c
	gcc -o $(PROJ) $(SRC_DIR)/$(PROJ).c

$(GENDATA): $(SRC_DIR)/$(GENDATA).c
	gcc -o ./src/$(GENDATA) $(SRC_DIR)/$(GENDATA).c


$(DATA): $(GENDATA)
	./src/$(GENDATA)
	./$(PROJ)

$(IMAGE): $(DATA)
	gnuplot ./$(DOC_DIR)/$(PROJ).gp

$(PDF): $(DOC_DIR)/$(PROJ).tex $(IMAGE) $(REF)
	cd $(DOC_DIR);\
	xelatex $(PROJ);\
	bibtex	$(PROJ);\
	xelatex $(PROJ);\
	xelatex $(PROJ);\

exe: $(SRC_DIR)/$(PROJ).c
	gcc -o $(PROJ) $(SRC_DIR)/$(PROJ).c

doc: $(PDF) 

clean:
	rm -rf *.aux *.bbl *.blg *.log *.out *.pdf *.toc \
	$(PROJ) ./src/$(GENDATA) $(DATA) $(IMAGE) \
	*.nav *.snm *.dat
	cd $(DOC_DIR); rm -rf *.aux *.bbl *.blg *.log *.out *.pdf *.toc \
	*.nav *.snm *.dat

.PHONY: all clean exe doc