TEXFLAGS = -bibtex -pdf -interaction=nonstopmode -use-make
BUILD_DIR = build
BUILD_DIR_FULL = build/full
MAIN_FILE_NAME = main
FULLBOOK_FILE_NAME = fullbook

.PHONY: all clean pdf $(BUILD_DIR)/$(MAIN_FILE_NAME).pdf fullpdf $(BUILD_DIR_FULL)/$(FULLBOOK_FILE_NAME).pdf

all: $(BUILD_DIR)/$(MAIN_FILE_NAME).pdf tests $(BUILD_DIR_FULL)/$(FULLBOOK_FILE_NAME).pdf

pdf: $(BUILD_DIR)/$(MAIN_FILE_NAME).pdf

fullpdf: $(BUILD_DIR_FULL)/$(FULLBOOK_FILE_NAME).pdf

tests:
	mkdir -p build && cd build && cmake -DCMAKE_BUILD_TYPE=Debug .. && $(MAKE)

$(BUILD_DIR)/$(MAIN_FILE_NAME).pdf: sources/$(MAIN_FILE_NAME).tex $(BUILD_DIR)
	pdflatex  $(TEXFLAGS) -jobname=$(@:.pdf=) -f $<
	biber build/main.bcf

$(BUILD_DIR_FULL)/$(FULLBOOK_FILE_NAME).pdf: sources/$(FULLBOOK_FILE_NAME).tex $(BUILD_DIR_FULL)
	pdflatex  $(TEXFLAGS) -jobname=$(@:.pdf=) -f $<
	biber $(BUILD_DIR_FULL)/$(FULLBOOK_FILE_NAME).bcf

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)


$(BUILD_DIR_FULL):
	mkdir -p $(BUILD_DIR_FULL)

full: clean fullpdf fullpdf


clean:
	(cd build && $(MAKE) clean) && cd build && rm -f *.nlo *.lot *.bcf *.acn *.glsdefs *.aux *.log *.lof \
                    *.toc *.bak *.sav *.ist *.nls  *.nlo *.xml *.xdy *.idx *.pdf *.blg *.lol *.bbl \
					&& cd full && rm -f *.nlo *.lot *.bcf *.acn *.glsdefs *.aux *.log *.lof \
                    *.toc *.bak *.sav *.ist *.nls  *.nlo *.xml *.xdy *.idx *.pdf  *.blg *.lol *.bbl

