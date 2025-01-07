# makefile for the complete archive

all	: info

info:
	@echo use :
	@echo "'make install' to install the package"
	@echo "'make demos'   to make the demos"
	@echo "'make _src'    to zip the sources"
	@echo "'make _bin'    to zip the binaries"

install:
	@$(MAKE) -C cc65 install
	$(MAKE) -C ra65 install
	$(MAKE) -C runtime install
	$(MAKE) -C libsrc install
	$(MAKE) -C libsrc/lynx install
demos:
	@$(MAKE) -C examples.c65
	$(MAKE) -C examples.c65/demos

clean:
	@$(MAKE) -C cc65 clean
	$(MAKE) -C ra65 clean
	$(MAKE) -C libsrc clean
	$(MAKE) -C libsrc/lynx clean
	$(MAKE) -C examples.c65 clean
	$(MAKE) -C examples.c65/demos clean
	rm -f include/*.bak
_src:
	@touch bin/dummy
	@touch lib/dummy
	@cd ..;\
	zip -r -u newcc65src newcc65/cc65/ newcc65/ra65 newcc65/libsrc \
               newcc65/examples.c65 newcc65/include newcc65/bin/dummy \
               newcc65/doc newcc65/lib/dummy;\
	zip -r -u newcc65src\
               newcc65/readme.txt newcc65/makefile newcc65/addenum.txt newcc65/changes* newcc65/install.txt \
               newcc65/runtime;\
	cd newcc65
	@rm bin/dummy lib/dummy

_bin:
	@cd ..;\
	zip -r newcc65bin newcc65/bin newcc65/lib;\
	cd newcc65
