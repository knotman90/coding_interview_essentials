TEXFLAGS = -bibtex -pdf -interaction=nonstopmode -use-make
BUILD_DIR = build
MAIN_FILE_NAME = main

.PHONY: all clean $(BUILD_DIR)/$(MAIN_FILE_NAME).pdf

all: $(BUILD_DIR)/$(MAIN_FILE_NAME).pdf tests

tests:
	mkdir -p build && cd build && cmake .. && $(MAKE)

$(BUILD_DIR)/$(MAIN_FILE_NAME).pdf: sources/$(MAIN_FILE_NAME).tex $(BUILD_DIR)
	pdflatex  $(TEXFLAGS) -jobname=$(@:.pdf=) -f $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	(cd build && $(MAKE) clean) && cd build && rm -f *.nlo *.lot *.bcf *.acn *.glsdefs *.aux *.log *.lof \
                    *.toc *.bak *.sav *.ist *.nls  *.nlo *.xml *.xdy 

