PROJ = step-3
SRC_DIR = ./src
DOC_DIR = ./doc

TEX = introduction.tex
GP = $(SRC_DIR)/build/solution.gp
PDF = final.pdf
IMAGE = $(SRC_DIR)/build/solution.eps

.PHONY: all clean 

all: $(PDF)
	@mv $(DOC_DIR)/introduction.pdf $(PDF)

$(PDF): $(DOC_DIR)/$(TEX) $(IMAGE)
	@echo "Compiling XeLaTeX document..."
	@cd $(DOC_DIR);\
	xelatex $(TEX);

$(GP): $(SRC_DIR)/$(PROJ).cc
	@echo "IMAGE Compiling..."
	@cd $(SRC_DIR);\
	mkdir -p build;\
	cd build && cmake ..;\
	$(MAKE);\
	./$(PROJ);

$(IMAGE): $(GP)
	gnuplot -e "filename='$<'" \
		-e "set term postscript eps" \
		-e "set output '$(IMAGE)'" \
		-e "set xlabel 'x'" \
		-e "set ylabel 'y'" \
		-e "set title 'Solution Plot'" \
		-e "set pm3d" \
		-e "splot '$<' using 1:2:3 with lines notitle"

clean: 
	@echo "cleaning..."
	@rm -rf *.pdf $(SRC_DIR)/build ;\
	cd $(DOC_DIR); rm -rf *.aux *.bbl *.blg *.log *.out *.pdf *_latexmk *.fls *.xdv
