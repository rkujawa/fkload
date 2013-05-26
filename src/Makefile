TOOLS_DIR = tools
LOADER_DIR = loader

LOADER_IMAGE = fkload.img
LOADER_ROM = kick.rom  # fkload.rom

.PHONY: tools loader

all: tools loader img2rom

tools:
	$(MAKE) -C $(TOOLS_DIR)

loader: 
	$(MAKE) -C $(LOADER_DIR)

img2rom: $(LOADER_DIR)/$(LOADER_IMAGE)
	$(TOOLS_DIR)/makerom $(LOADER_DIR)/$(LOADER_IMAGE) $(LOADER_ROM) 

clean:
	$(MAKE) -C $(TOOLS_DIR) clean
	$(MAKE) -C $(LOADER_DIR) clean
	rm -f $(LOADER_ROM)
 
