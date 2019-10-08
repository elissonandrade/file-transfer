CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := bin/transfer

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
SRC_TEST := $(filter-out $(SRCDIR)/main.cpp, $(SOURCES) )
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -std=c++11

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET)"; $(CC) $^ -o $(TARGET) 

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) -c -o $@ $<"; $(CC) -c -o $@ $< $(CFLAGS)

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)
  
test_%:
	$(CC) $(CFLAGS) $(SRC_TEST) test/$@.cpp -o bin/$@
