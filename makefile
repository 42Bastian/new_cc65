# makefile for the complete archive

export TOP:=$(PWD)

all	: info

.ONESHELL:
info:
	@echo use :
	@echo "'make install' to install the package"
	@echo "'make demos'   to make the demos"
	@echo "'make _src'    to zip the sources"
	@echo "'make _bin'    to zip the binaries"

.ONESHELL:
install:
	@$(MAKE) -C cc65 install -j
	$(MAKE) -C ra65 install -j
	$(MAKE) -C runtime install
	$(MAKE) -C libsrc install
	$(MAKE) -C libsrc/lynx install
.ONESHELL:
demos:
	@$(MAKE) -C examples.c65
	$(MAKE) -C examples.c65/demos

.ONESHELL:
clean:
	@$(MAKE) -C cc65 clean
	$(MAKE) -C ra65 clean
	$(MAKE) -C libsrc clean
	$(MAKE) -C libsrc/lynx clean
	$(MAKE) -C examples.c65 clean
	$(MAKE) -C examples.c65/demos clean
	rm -f include/*.bak
	rm bin/*
	touch bin/dummy

.ONESHELL:
_src: clean
	cd ..
	7z a newcc65src new_cc65
	cd $(TOP)

.ONESHELL:
_bin: install
	@cd ..
	7z a newcc65bin.7z new_cc65/bin new_cc65/lib
	cd new_cc65
